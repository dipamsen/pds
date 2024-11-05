#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	char val;
	struct node *next;
} node;

// prints a linked list
void print(node *head) {
	node *tail = head;
	while (tail != NULL) {
		printf("%c", tail->val);
		if (tail->next != NULL) printf(" --> ");
		
		tail = tail->next;
	}
	printf("\n");
}


// recursively reverse a sublist starting from head, of size k
node *reverse(node *head, int k) {
	if (head == NULL) return head;
	int i = 0;
	node *prev = NULL, *curr = head;
	while (curr != NULL && i < k) {
		node *next = curr->next;
		curr->next = prev; // reverse the link
		prev = curr;
		curr = next;
		i++;
	}
	
	// at this point, prev = new "head" of this sublist    (originally, last node of current sublist)
	//                curr = what was originally prev.next (first node of next sublist)
	//                head = new "tail" of this sublist    (originally, first node of current sublist)
	
	// reverse next sublist
	node *nexthead = reverse(curr, k); // will return the new head of the next sublist
	head->next = nexthead; // point this sublist's "tail" to next sublist's "head"
	
	return prev; // return new head of this sublist
}
// if current sublist is last sublist, `curr` will become NULL (after the while loop)
// and so next recursive call will be reverse(NULL) which will hit base case.
// (base case returns NULL, so the last node of this sublist will point to NULL, as required).


// frees a linked list
void freell(node *head) {
	if (head == NULL) return;
	freell(head->next);
	free(head);
}


int main() {
	int n;
	printf("Enter number of nodes: ");
	scanf("%d", &n);
	
	node *head = NULL, *tail = NULL;
	
	printf("\n");	
	for (int i = 0; i < n; i++) {
		char c;
		printf("Enter element %d: ", i + 1);
		scanf(" %c", &c);
		
		// create a node
		node *temp = (node *) malloc(1 * sizeof(node));
		temp->val = c;
		temp->next = NULL;
		
		if (tail == NULL) head = tail = temp;
		else {
			tail->next = temp;
			tail = tail->next;
		}
	}
	
	printf("\nOriginal list:\n");	
	print(head);
	
	int k;
	printf("\nEnter value of k: ");
	scanf("%d", &k);
	if (k < 1) {
		printf("\tk should be at least 1.\n");
		exit(1);
	}
	
	head = reverse(head, k);
	
	printf("\nModified list:\n");	
	print(head);
	
	freell(head);
	
	return 0;
}
