#include <stdio.h>
// inc
typedef struct
{
    int m, n;
    int values[100][100];
} matrix;

int main()
{
    int m, n, p;
    printf("Enter m, n, p: ");
    scanf("%d %d %d", &m, &n, &p);
    matrix A = {m, n}, B = {n, p};
}