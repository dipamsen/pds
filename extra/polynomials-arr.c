// Polynomial storage and operations as an array of coefficients
// Lot of memory consumed for high order sparse polynomials.
// Simpler code.
// benefits: - like terms automatically merged
//           - 0 terms automatically handled
//           - simpler multiplication algorithm
// See also: polynomials.c for a linked-list implementation which is more memory efficient for sparse arrays.

#include <stdio.h>
#include <stdlib.h>

#define MAX_ORDER 100

typedef int Polynomial[MAX_ORDER];

void init(int *p) {
    for (int i = 0; i < MAX_ORDER; i++)
        p[i] = 0;
}

void print(Polynomial p) {
    int first = 1;
    for (int i = MAX_ORDER - 1; i >= 0; i--) {
        if (p[i] == 0)
            continue;
        if (!first)
            printf("+ ");
        if (first)
            first = !first;

        if (i > 1)
            printf("%dx^%d ", p[i], i);
        else if (i == 1)
            printf("%dx ", p[i]);
        else
            printf("%d ", p[i]);
    }
    printf("\n");
}

int main() {
    Polynomial p1, p2;
    init(p1);
    init(p2);

    printf("Enter first polynomial:\n");
    for (int i = 0;; i++) {
        int a, k;
        printf("\tenter term %d: ", i + 1);
        scanf("%d %d", &a, &k);
        if (a == 0 && k == -1)
            break;
        p1[k] += a;
    }

    printf("\nEnter second polynomial:\n");
    for (int i = 0;; i++) {
        int a, k;
        printf("\tenter term %d: ", i + 1);
        scanf("%d %d", &a, &k);
        if (a == 0 && k == -1)
            break;
        p2[k] += a;
    }

    printf("\nPolynomials: \n");
    print(p1);
    print(p2);

    printf("\nSum: ");
    Polynomial sum;
    init(sum);
    for (int i = 0; i < MAX_ORDER - 1; i++)
        sum[i] = p1[i] + p2[i];
    print(sum);

    printf("\nDifference: ");
    Polynomial diff;
    init(diff);
    for (int i = 0; i < MAX_ORDER - 1; i++)
        diff[i] = p1[i] - p2[i];
    print(diff);

    printf("\nProduct: ");
    Polynomial prod;
    init(prod);
    for (int i = 0; i < MAX_ORDER - 1; i++)
        for (int j = 0; j < MAX_ORDER - 1; j++)
            prod[i + j] += p1[i] * p2[j];
    print(prod);
}