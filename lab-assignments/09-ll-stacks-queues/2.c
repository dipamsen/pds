#include <stdio.h>
#define MAX 200

typedef struct {
	int top;
	char arr[MAX];
} Stack;

int inputString(char *s, int len) {
	s[0] = '\0';
	while (s[0] == '\0' || s[0] == '\n')
		fgets(s, len, stdin);
	int i = 0; 
	while (s[i] != '\n' && s[i] != '\0') i++;
	s[i] = '\0';
	return i;
}


Stack initStack() {
	Stack s;
	s.top = -1;
	return s;
}

void push(Stack *s, char val) {
	s->arr[++s->top] = val;
}

char pop(Stack *s) {
	return s->arr[s->top--];
}

int main() {
	char input[MAX];
	printf("Enter string: ");
	inputString(input, MAX);
	
	Stack s1 = initStack();
	Stack s2 = initStack();
	
	int i = 0;
	while (input[i] != '\0') {
		push(&s1, input[i]);
		i++;
	}
	
	i--;
	while (i >= 0) {
		push(&s2, input[i]);
		i--;
	}
	
	int isPalindrome = 1;
	while (s1.top > -1) {
		if (pop(&s1) != pop(&s2)) {
			isPalindrome = 0;
			break;
		}
	}
	
	if (isPalindrome) {
		printf("Entered string is a palindrome.\n");
	} else {
		printf("Entered string is not a palindrome.\n");
	}
	
	return 0;
}
