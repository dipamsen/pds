// Evaluation of arithmetic expressions by conversion into postfix notation

// usage: ./a.out [arithmetic expression]
// eg:    ./a.out "3+2*2+3"
//        ./a.out "32+2+30/10*4"
//        ./a.out "5+(7-4)*10/5+3*2"
// (quotes are only needed for bash syntax, they are not passed to the program)

// includes basic error finding!


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 200

typedef struct {
	int type; // 0 = operand, 1 = operator, 2 = (, 3 = )
	union {
		char op;
		int data;
	} val;
	int pos;
} Token;

typedef struct {
	Token arr[MAX];
	int top;
} Stack;

Stack init() {
	Stack s;
	s.top = -1;
	return s;
}

void push(Stack *s, Token v) {
	s->arr[++s->top] = v;
}

Token pop(Stack *s) {
	return s->arr[s->top--];
}

int isEmpty(Stack s) {
	return s.top == -1;
}

int isOperator(char c) {
	return c == '+' || c == '-' || c == '*' || c == '/';
}

int evaluate(Token a, Token b, Token o) {
	switch(o.val.op) {
		case '+': return b.val.data + a.val.data;
		case '-': return b.val.data - a.val.data;
		case '/': return b.val.data / a.val.data;
		case '*': return b.val.data * a.val.data;
	}
}

int precedence(Token t) {
	switch (t.val.op) {
		case '+':
		case '-':
			return 10;
		case '*':
		case '/':
			return 20;
	}
}

void printError(char *input, int pos, char *reason) {
	printf("Error:\n");
	printf("\t\'%s\'\n", input);

	if (pos >= 0) {
		printf("\t ");
		for (int i =0; i < pos; i++) printf(" ");
		printf("^\n");
		printf("\t ");
		for (int i =0; i < pos; i++) printf(" ");
		printf("%s", reason);
		printf("\n");
		printf("\n");
	} else printf("\tinvalid expression\n");
	
}

int main(int argc, char *argv[]) {
	if (argc < 2) {
		printf("usage: %s [arithmetic expression]\n", argv[0]);
		printf("eg:    %s \"3+2*2+3\"\n", argv[0]);
		printf("       %s \"32+2+30/10*4\"\n", argv[0]);
		printf("       %s \"5+(7-4)*10/5+3*2\"\n", argv[0]);
		return 0;
	}
	
	char input[MAX];
	strcpy(input, argv[1]);
	
	Token tokens[MAX];
	int len = 0;
	
	int i = 0;
	int reading = 0;
	int curr = 0;
	int currPos = 0;
	while (input[i] != '\0') { // Tokenisation
		char c = input[i];
		if ('0' <= c && c <= '9') {
			if (!reading) {
				currPos = i;
				reading = 1;
			}
			curr = curr * 10 + (c - '0');
		} else {
			if (reading) {
				Token t;
				t.type = 0;
				t.val.data = curr;
				t.pos = currPos;
				reading = 0;
				curr = 0;
				tokens[len++] = t;
			}
			if (isOperator(c)) {
				Token t;
				t.type = 1;
				t.val.op = c;
				t.pos = i;
				tokens[len++] = t;
			} else if (c == '(') {
				Token t;
				t.type = 2;
				t.pos = i;
				tokens[len++] = t;
			} else if (c == ')') {
				Token t;
				t.type = 3;
				t.pos = i;
				tokens[len++] = t;
			}
		}
		i++;
	}
	if (reading) {
		Token t;
		t.type = 0;
		t.val.data = curr;
		t.pos = currPos;
		reading = 0;
		curr = 0;
		tokens[len++] = t;
	}
	
	//for (int i = 0; i < len; i++) {
	//	Token t = tokens[i];
	//	if (t.type == 0) printf("%d", t.val.data);
	//	if (t.type == 1) printf("%c", t.val.op);
	//	printf("(%d) ", t.pos);
	//}
	//printf("\n");
	
	// Conversion to postfix
	Token postfix[MAX];
	int l = 0;
	Stack st1 = init();
	
	for (int i = 0; i < len; i++) {
		Token t = tokens[i];
		if (t.type == 0) { // operand
			postfix[l++] = t;
		} else if (t.type == 1) { // operator
			if (isEmpty(st1)) {
				push(&st1, t);
				continue;
			}
			Token top = st1.arr[st1.top];
			if (top.type == 1) { // operator
				// pop until top is less precedence that t
				while (precedence(st1.arr[st1.top]) >= precedence(t)) {
					postfix[l++] = pop(&st1);
				}
				push(&st1, t);
			} else if (top.type == 2) { // opening paren
				push(&st1, t);
			}
		} else if (t.type == 2) { // opening paren
			push(&st1, t);
		} else if (t.type == 3) { // closing paren
			// pop until you reach matching paren
			while (!isEmpty(st1) && st1.arr[st1.top].type != 2) {
				postfix[l++] = pop(&st1);
			}
			if (isEmpty(st1)) {
				// Paren matching error
				printError(input, t.pos, "mismatched parenthesis");
				exit(1);
			}
			pop(&st1);
		}
	}

		
	// pop everything
	while (!isEmpty(st1)) {
		Token t = pop(&st1);
		if (t.type > 1) {
			// Paren matching error
			printError(input, t.pos, "mismatched parenthesis");
			exit(1);
		}
		postfix[l++] = t;
	}
	
	printf("Postfix: ");
	
	for (int i = 0; i < l; i++) {
		Token t = postfix[i];
		if (t.type == 0) printf("%d", t.val.data);
		if (t.type == 1) printf("%c", t.val.op);
		printf(" ");
	}
	printf("\n");
	
	// Evaluate Result
	
	Stack st2 = init();
	
	for (int i = 0; i < l; i++) {
		Token t = postfix[i];
		if (t.type == 0) { // operand
			push(&st2, t);
		} else if (t.type == 1) { // operator, assumed to be binary
			Token a, b;
			int err = 0;
			if (!isEmpty(st2)) a = pop(&st2);
			else err = 1;
			if (!isEmpty(st2)) b = pop(&st2);
			else err = 1;
			
			if (err) {
				printError(input, t.pos, "unexpected operator");
				exit(1);
			}
			
			int r = evaluate(a, b, t);
			Token new;
			new.type = 0;
			new.val.data = r;
			new.pos = -1;
			push(&st2, new);
		}
	}
	
	if (st2.top != 0) {
		printError(input, st2.arr[st2.top].pos, "unexpected token");
		exit(1);
	}
	
	printf("Result:  %d\n", st2.arr[st2.top].val.data);
			
	
	
	return 0;
}
