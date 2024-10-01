#include <stdio.h>

int isUpperTriangular(int A[][100], int n)
{
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (A[i][j] != 0)
                return 0;
        }
    }
    return 1;
}

int main()
{
    int n;
    int A[100][100];
    printf("Enter size of matrix: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("Enter A[%d][%d]: ", i, j);
            scanf("%d", &A[i][j]);
        }
    }

    int flag = isUpperTriangular(A, n);

    if (flag)
    {
        printf("Entered matrix is upper triangular.\n");
    }
    else
    {
        printf("Entered matrix is not upper triangular.\n");
    }

    return 0;
}