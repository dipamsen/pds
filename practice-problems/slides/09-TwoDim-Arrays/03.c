#include <stdio.h>

int sameSum(int A[100][100], int n)
{
    int commonSum = -1;
    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = 0; j < n; j++)
        {
            sum += A[i][j];
        }
        if (commonSum == -1)
            commonSum = sum;
        else if (commonSum != sum)
            return 0;
    }

    commonSum = -1;
    for (int j = 0; j < n; j++)
    {
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += A[i][j];
        }
        if (commonSum == -1)
            commonSum = sum;
        else if (commonSum != sum)
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

    if (sameSum(A, n))
    {
        printf("Yes.\n");
    }
    else
    {
        printf("No.\n");
    }
    return 0;
}