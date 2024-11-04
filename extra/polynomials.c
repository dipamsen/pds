// Storing, and performing operations (addition, subtraction) on
// polynomials. Memory efficient for sparse polynomials. (Linked List implementation)

#include <stdio.h>
#include <stdlib.h>

typedef struct Term { // a x^k
    int a, k;
    struct Term *next;
} Term;

// maintains decreasing order of k in linked list
void insert(Term **head, int a, int k) { // double pointer because may need to manipulate head
    Term *new = malloc(1 * sizeof(Term));
    new->a = a;
    new->k = k;

    Term *h = *head;
    if (k > h->k) {
        // insert at head
        *head = new;
        new->next = h;
        return;
    }
    Term *t = h;
    while (t->next != NULL) {
        // insert in middle
        if (t->k > k && k > t->next->k) {
            Term *u = t->next;
            t->next = new;
            new->next = u;
            return;
        }
        t = t->next;
    }
    // insert at tail
    t->next = new;
    new->next = NULL;
}

void print(Term *poly) {
    Term *t = poly;
    while (t != NULL) {
        if (t->k > 1)
            printf("%dx^%d ", t->a, t->k);
        else if (t->k == 1)
            printf("%dx ", t->a);
        else
            printf("%d ", t->a);
        if (t->next != NULL)
            printf("+ ");

        t = t->next;
    }
    printf("\n");
}

Term *add(Term *p1, Term *p2) {
    Term *sum = NULL;

    Term *t1 = p1; // tail pointers
    Term *t2 = p2;
    Term *t3 = NULL;

    while (t1 != NULL || t2 != NULL) {
        if (t3 == NULL)
            sum = t3 = malloc(1 * sizeof(Term));
        else {
            t3->next = malloc(1 * sizeof(Term));
            t3 = t3->next;
        }

        if (t1 != NULL && t2 != NULL && t1->k == t2->k) {
            t3->a = t1->a + t2->a;
            t3->k = t1->k;
            t3->next = NULL;
            t1 = t1->next;
            t2 = t2->next;
        } else if (t1 == NULL || (t2 != NULL && t1->k < t2->k)) {
            t3->a = t2->a;
            t3->k = t2->k;
            t3->next = NULL;
            t2 = t2->next;
        } else {
            t3->a = t1->a;
            t3->k = t1->k;
            t3->next = NULL;
            t1 = t1->next;
        }
    }
    t3->next = NULL;

    return sum;
}

Term *subtract(Term *p1, Term *p2) {
    Term *res = NULL;

    Term *t1 = p1; // tail pointers
    Term *t2 = p2;
    Term *t3 = NULL;

    while (t1 != NULL || t2 != NULL) {
        if (t3 == NULL)
            res = t3 = malloc(1 * sizeof(Term));
        else {
            t3->next = malloc(1 * sizeof(Term));
            t3 = t3->next;
        }

        if (t1 != NULL && t2 != NULL && t1->k == t2->k) {
            t3->a = t1->a - t2->a;
            t3->k = t1->k;
            t3->next = NULL;
            t1 = t1->next;
            t2 = t2->next;
        } else if (t1 == NULL || (t2 != NULL && t1->k < t2->k)) {
            t3->a = -t2->a;
            t3->k = t2->k;
            t3->next = NULL;
            t2 = t2->next;
        } else {
            t3->a = t1->a;
            t3->k = t1->k;
            t3->next = NULL;
            t1 = t1->next;
        }
    }
    t3->next = NULL;

    return res;
}

int main() {
    Term *p1 = NULL, *p2 = NULL; // polynomials

    printf("Enter first polynomial:\n");
    for (int i = 0;; i++) {
        int a, k;
        printf("\tenter term %d: ", i + 1);
        scanf("%d %d", &a, &k);
        if (a == 0 && k == -1)
            break;
        if (p1 == NULL) {
            p1 = (Term *)malloc(1 * sizeof(Term));
            p1->a = a;
            p1->k = k;
            p1->next = NULL;
        } else
            insert(&p1, a, k);
    }

    printf("\nEnter second polynomial:\n");
    for (int i = 0;; i++) {
        int a, k;
        printf("\tenter term %d: ", i + 1);
        scanf("%d %d", &a, &k);
        if (a == 0 && k == -1)
            break;
        if (p2 == NULL) {
            p2 = (Term *)malloc(1 * sizeof(Term));
            p2->a = a;
            p2->k = k;
            p2->next = NULL;
        } else
            insert(&p2, a, k);
    }

    printf("\nPolynomials: \n");
    print(p1);
    print(p2);

    printf("\nSum: ");
    Term *sum = add(p1, p2);
    print(sum);

    printf("\nDifference: ");
    Term *d = subtract(p1, p2);
    print(d);
}