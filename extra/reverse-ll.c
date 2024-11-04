// Reverse a linked list.

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int val;
    struct node *next;
} Node;

Node *create(int arr[], int n) {
    Node *head = NULL, *tail = NULL;
    for (int i = 0; i < n; i++) {
        if (tail == NULL) {
            head = tail = (Node *)malloc(1 * sizeof(Node));
        } else {
            tail->next = (Node *)malloc(1 * sizeof(Node));
            tail = tail->next;
        }
        tail->val = arr[i];
        tail->next = NULL;
    }
    return head;
}

void freell(Node *head) {
    if (head == NULL)
        return;
    freell(head->next);
    free(head);
}

void print(Node *head) {
    Node *tail = head;
    while (tail != NULL) {
        printf("%d ", tail->val);
        if (tail->next != NULL)
            printf("-> ");
        tail = tail->next;
    }
    printf("\n");
}

void reverse(Node **head) {
    Node *prev = NULL, *curr = *head, *next = curr->next;
    while (curr != NULL) {
        curr->next = prev;
        prev = curr;
        curr = next;
        if (curr != NULL)
            next = curr->next;
    }
    *head = prev;
}

int main() {
    int arr[] = {2, 5, 4, 8, 1, 3, 7, 9, 6};

    Node *head = create(arr, sizeof(arr) / sizeof(int));

    print(head);

    reverse(&head);

    print(head);
}