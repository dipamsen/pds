#include <stdio.h>
#include <stdlib.h>
#define MAX 200

typedef struct node {
	int val;
	struct node *next;
} Node;

int inputString(char *s, int len) {
	s[0] = '\0';
	while (s[0] == '\0' || s[0] == '\n')
		fgets(s, len, stdin);
	int i = 0; 
	while (s[i] != '\n' && s[i] != '\0') i++;
	s[i] = '\0';
	return i;
}

void freeLL(Node *head) {
	if (head == NULL) return;
	freeLL(head->next);
	free(head);
}

void printLL(Node *head) {
	Node *tail = head;

	while (tail != NULL) {
		printf("%d", tail->val);
		if (tail->next != NULL) printf(" -> ");
		tail = tail->next;
	}
	printf("\n");
}


void printSet(Node *head) {
	Node *tail = head;
	printf("{");
	while (tail != NULL) {
		printf("%d", tail->val);
		if (tail->next != NULL) printf(", ");		
		tail = tail->next;
	}
	printf("}\n");
}

int contains(Node *head, int val) {
	if (head == NULL) return 0;
	if (head->val == val) return 1;
	return contains(head->next, val);
}

Node *inputSet() { // Read a set of integers and store them in a linked list.
	char set[MAX];
	int len = inputString(set, MAX);
	
	Node *head = NULL, *tail = NULL;
	
	int reading = 0;
	int curr = 0;
	int dupe = 0;
	for (int i = 0; i < len; i++) {
		char c = set[i];
		switch (c) {
			case '{': break;
			case '0'...'9': 
				reading = 1;
				curr = curr * 10 + (c - '0');
				break;
			case ',':
			case '}':
			default: 
				if (reading) {
					if (head != NULL && contains(head, curr)) {
						// duplicate element in set
						dupe = 1;
						break;
					}
					Node *tmp = malloc(1 * sizeof(Node));
					tmp->val = curr;
					tmp->next = NULL;
					
					if (tail != NULL) {
						tail->next = tmp;
						tail = tail->next;
					} else head = tail = tmp;
					curr = 0;
					reading = 0;
				}
				break;
		}
		
		if (c == '}' || dupe) {
			break;
		}
	}
	
	if (dupe) {
		printf("Invalid set entered.\n");
		freeLL(head);
		return NULL;	
	}
	
	return head;
}

int insert(Node *head, int val) { // Insert an element in an existing set.
	Node *tail = head;
	if (contains(head, val)) return 0;
	while (tail->next != NULL)
		tail = tail->next;
	Node *new = malloc(1 * sizeof(Node));
	new->val = val;
	new->next = NULL;
	tail->next = new;
	return 1;
}

int disjointSet(Node *s1, Node *s2, int *cmn) { // Verify whether two sets are disjoint.
	Node *t1 = s1;
	
	while (t1 != NULL) {
		if (contains(s2, t1->val)) {
			*cmn = t1->val;
			return 0;
		}
		t1 = t1->next;
	}
	return 1;
}

Node *unionSet(Node *s1, Node *s2) { // Perform union and intersection of two sets.
	Node *res = NULL;
	Node *t = NULL;
	Node *t1 = s1;
	Node *t2 = s2;
	while (t1 != NULL) {
		Node *tmp = (Node *)malloc(1 * sizeof(Node));
		tmp->val = t1->val;
		tmp->next = NULL;
		if (t == NULL) res = t = tmp;
		else {
			t->next = tmp;
			t = t->next;
		}
		t1 = t1->next;
	}
	while (t2 != NULL) {
		if (!contains(res, t2->val)) {
			Node *tmp = (Node *)malloc(1 * sizeof(Node));
			tmp->val = t2->val;
			tmp->next = NULL;
			if (t == NULL) res = t = tmp;
			else {
				t->next = tmp;
				t = t->next;
			}
		}
		t2 = t2->next;
	}
	
	return res;
}


Node *intersectSet(Node *s1, Node *s2) { // Perform union and intersection of two sets.
	Node *res = NULL;
	Node *t = NULL;
	Node *t1 = s1;
	while (t1 != NULL) {
		if (contains(s2, t1->val)) {
			Node *tmp = (Node *)malloc(1 * sizeof(Node));
			tmp->val = t1->val;
			tmp->next = NULL;
			if (t == NULL) res = t = tmp;
			else {
				t->next = tmp;
				t = t->next;
			}
		}
		t1 = t1->next;
	}
	return res;
}

Node *differenceSet(Node *s1, Node *s2) { // Perform the set difference between two given sets.
	Node *res = NULL;
	Node *t = NULL;
	Node *t1 = s1;
	while (t1 != NULL) {
		if (!contains(s2, t1->val)) {
			Node *tmp = (Node *)malloc(1 * sizeof(Node));
			tmp->val = t1->val;
			tmp->next = NULL;
			if (t == NULL) res = t = tmp;
			else {
				t->next = tmp;
				t = t->next;
			}
		}
		t1 = t1->next;
	}
	return res;
}

int main() {
	Node *s1 = NULL;
	while (s1 == NULL) {
		printf("Set-1: ");
		s1 = inputSet();
	}
	
	printf("L1-Set-1: ");
	printLL(s1);
	
	Node *s2 = NULL;
	while (s2 == NULL) {
		printf("Set-2: ");
		s2 = inputSet();
	}
	
	printf("L1-Set-2: ");
	printLL(s2);
	
	printf("\n");
	
	int n1;
	int ins1 = 0;
	while (ins1 == 0) {
		printf("Insert into Set-1: ");
		scanf("%d", &n1);
		ins1 = insert(s1, n1);
		if (!ins1) {
			printf("%d cannot be inserted as per set rules\n", n1);
		}
	}
	printf("Set-1: ");
	printSet(s1);
	
	printf("\n");
	
	printf("L1-Set-1: ");
	printLL(s1);	
	printf("L2-Set-2: ");
	printLL(s2);
	
	printf("\n");
	
	int common = 0;
	int dsj = disjointSet(s1, s2, &common);
	
	if (dsj) {
		printf("Set-1 and Set-2 are disjoint.\n");
	} else {
		printf("Set-1 and Set-2 are not disjoint, because of common element %d.\n", common);
	}
	
	Node *uni = unionSet(s1, s2);
	Node *inter = intersectSet(s1, s2);
	
	printf("\n");
	
	printf("Union of Set-1 and Set-2: ");
	printSet(uni);
	printf("Intersection of Set-1 and Set-2: ");
	printSet(inter);
	
	printf("\n");
	
	Node *d1 = differenceSet(s1, s2);
	Node *d2 = differenceSet(s2, s1);
	
	printf("Set difference Set-1 - Set-2: ");
	printSet(d1);
	printf("Set difference Set-2 - Set-1: ");
	printSet(d2);
	
	freeLL(s1);
	freeLL(s2);
	freeLL(uni);
	freeLL(inter);
	freeLL(d1);
	freeLL(d2);
	
	return 0;
}
