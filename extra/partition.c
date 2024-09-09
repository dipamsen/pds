// Given a number, find all possible representations of that number as a sum of non decreasing positive integers.
// Note that the number itself is also considered as a possible outcome.
// Eg. 4 = 1 + 1 + 1 + 1
//     4 = 1 + 1 + 2
//     4 = 1 + 3
//     4 = 2 + 2
//     4 = 4

#include <stdio.h>

void partition(int arr[], int len, int n, int min)
{
    if (n == 0)
    {
        int sum = arr[0];
        printf("%d ", arr[0]);
        for (int i = 1; i < len; i++)
        {
            printf("+ %d ", arr[i]);
            sum += arr[i];
        }
        printf("= %d\n", sum);
        return;
    }
    if (n == 1)
    {
        arr[len] = 1;
        partition(arr, len + 1, n - 1, 1);
    }
    else
    {
        for (int i = min; i <= n / 2; i++)
        {
            arr[len] = i;
            partition(arr, len + 1, n - i, i);
        }
        arr[len] = n;
        partition(arr, len + 1, n - n, n);
    }
}

int main()
{
    int arr[1000];
    int n;
    scanf("%d", &n);
    partition(arr, 0, n, 1);
    return 0;
}