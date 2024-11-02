#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef char string[200];

typedef struct digit {
	int dig;
	struct digit *next;
} Digit;

typedef struct {
	Digit *head;
	int isNegative;
} Number;

Number init(string s) {
	Number num;
	num.head = NULL;
	num.isNegative = 0;
	Digit *tail = NULL, *ptr = NULL;
	int n = strlen(s);

	for (int i = n - 1; i >= 0; i--) {
		ptr = (Digit *) malloc(1 * sizeof(Digit));
		ptr->dig = s[i] - '0';
		ptr->next = NULL;

		if (tail == NULL) { 
			num.head = tail = ptr;
		} else {
			tail->next = ptr;
			tail = tail->next;
		}
	}
	return num;
}

void print_d(Digit *n) {
	if (n->next != NULL) print_d(n->next);
	printf("%d", n->dig);
}

void print(Number n) {
	if (n.isNegative) printf("-");
	print_d(n.head);
	printf("\n");
}


int greater(Number n1, Number n2) {
	
}


Number add(Number n1, Number n2) {
	Number result;
	result.head = NULL;
	result.isNegative = 0;
	Digit *t = NULL;
	Digit *t1 = n1.head;
	Digit *t2 = n2.head;
	
	int carry = 0;
	while (t1 != NULL || t2 != NULL) {
		Digit *p = (Digit *) malloc(1 * sizeof(Digit));
		p->dig = 0;
		p->next = NULL;
		if (t1 != NULL) p->dig += t1->dig;
		if (t2 != NULL) p->dig += t2->dig;
		p->dig += carry;
		
		carry = p->dig / 10;
		p->dig = p->dig % 10;
		
		if (t1 != NULL) t1 = t1 -> next;
		if (t2 != NULL) t2 = t2 -> next;
		if (t == NULL) {
			result.head = p;
			t = p;
		}
		else {
			t->next = p;
			t = t->next;
		}
	}
	if (carry) {
		Digit *p = (Digit *) malloc(1 * sizeof(Digit));
		p->dig = carry;
		p->next = NULL;
		t->next = p;
		t = t->next;
	}
	return result;
}


Number sub(Number n1, Number n2) {
	Number result;
	result.head = NULL;
	result.isNegative = 0;
	Digit *t = NULL;
	Digit *t1 = n1.head;
	Digit *t2 = n2.head;
	
	int borrow = 0;
	while (t1 != NULL || t2 != NULL) {
		Digit *p = (Digit *) malloc(1 * sizeof(Digit));
		p->dig = 0;
		p->next = NULL;
		if (t1 != NULL) p->dig += t1->dig;
		if (t2 != NULL) p->dig -= t2->dig;
		p->dig -= borrow;
		
		if (p -> dig < 0) {
			borrow = 1;
			p->dig += 10;
		} else borrow = 0;
		
		if (t1 != NULL) t1 = t1 -> next;
		if (t2 != NULL) t2 = t2 -> next;
		if (t == NULL) {
			result.head = p;
			t = p;
		}
		else {
			t->next = p;
			t = t->next;
		}
	}
	if (borrow) {
		// 10's complement
		t = result.head;
		while (t != NULL) {
			t->dig = 9 - t->dig;
			t = t->next;
		}
		result.head->dig++;
		t = result.head;
		while (t->dig > 10) {
			t->dig /= 10;
			if (t->next != NULL) t->next->dig++;
			else {
				Digit *p = (Digit *) malloc(1 * sizeof(Digit));
				p->dig = 1;
				p->next = NULL;
				t->next = p;
			}
			t = t->next;
		}
		result.isNegative = 1;
	}
	t = result.head;
	while (t->next != NULL && t->next->next != NULL) t = t->next;
	if (t->next->dig == 0) {
		free(t->next);
		t->next = 0;
	}
	return result;
}

Number mult(Number n1, Number n2) {
	Number result;
	result.head = NULL;
	result.isNegative = 0;
	Digit *t = NULL;
	Digit *t1 = n1.head;
	Digit *t2 = n2.head;
	
	// keep t2, loop over t1
	int i = 0;
	while (t2 != NULL) {
		int carry = 0;
		t = result.head;
		for (int j = 0; j < i; j++) if (t->next != NULL) t = t -> next;
		while (t1 != NULL) {
			if (t == NULL) {
				result.head = t = (Digit *) malloc(1 * sizeof(Digit));
				t->dig = 0;
				t->next = NULL;
			} else if (t -> next == NULL) {
				t->next = (Digit *) malloc(1 * sizeof(Digit));
				t->next->dig = 0;
				t->next->next = NULL;
			} 
			

			int out = t1->dig * t2->dig + carry;
			carry = out / 10;
			out %= 10;
			
			t->dig += out;
			if (t->dig > 10) {
				carry += t->dig / 10;
				t->dig %= 10;
			}
			
			t = t->next;
			t1 = t1 -> next;
		}
		t2 = t2 -> next;
		i++;
	}
	
	return result;
}

int main() {
	string s1, s2;
	printf("Input two positive numbers: \n");
	printf("a = ");
	scanf("%s", s1);
	printf("b = ");
	scanf("%s", s2);
	
	Number n1, n2;
	n1 = init(s1);
	n2 = init(s2);
	
	//print(n1);
	//printf("\n");
	//print(n2);
	//printf("\n");
	
	printf("\nOutput: \n");
	
	Number n3 = add(n1, n2);
	printf("a + b = ");
	print(n3);
	
	Number n4 = sub(n1, n2);
	printf("a - b = ");
	print(n4);
	
	
	Number n5 = mult(n1, n2);
	printf("a * b = ");
	print(n5);


}
