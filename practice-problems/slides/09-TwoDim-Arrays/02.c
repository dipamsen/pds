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

int isLowerTriangular(int A[][100], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (A[i][j] != 0)
                return 0;
        }
    }
    return 1;
}

int isDiagonal(int A[][100], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
                continue;
            if (A[i][j] != 0)
                return 0;
        }
    }
    return 1;
}

int isIdentity(int A[][100], int n)
{
    if (!isDiagonal(A, n))
        return 0;
    for (int i = 0; i < n; i++)
    {
        if (A[i][i] != 1)
            return 0;
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

    int flag1 = isUpperTriangular(A, n);
    int flag2 = isLowerTriangular(A, n);
    int flag3 = isDiagonal(A, n);
    int flag4 = isIdentity(A, n);

    if (flag1)
    {
        printf("Given matrix is upper triangular.\n");
    }
    if (flag2)
    {
        printf("Given matrix is lower triangular.\n");
    }
    if (flag3)
    {
        printf("Given matrix is diagonal matrix.\n");
    }
    if (flag4)
    {
        printf("Given matrix is identity matrix.\n");
    }

    return 0;
}