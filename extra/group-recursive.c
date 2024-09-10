// Modified from problem from Lab Test 1 from different Section
// Given numbers 9 + 8 + 7 + 6 + ... + 1, you can perform operations:
// 1. GROUP -> Group any two consecutive digits. Eg. 98 + 7 + 6 + ... + 1
// 2. REPLACE -> Replace + sign with -. Eg. 98 - 7 + 6 + ... + 1
// By using these two operations, print all possible solutions which give result 100.
// Eg. 9 + 8 + 76 + 5 + 4 - 3 + 2 - 1

#include <stdio.h>

int abs(int x)
{
    return (x > 0) ? x : -x;
}

void group(int arr[], int len, int n)
{
    if (n >= 1)
    {
        arr[len] = n;
        group(arr, len + 1, n - 1);
        arr[len] = -n;
        group(arr, len + 1, n - 1);
    }
    if (n >= 2)
    {
        arr[len] = n * 10 + n - 1;
        group(arr, len + 1, n - 2);
        arr[len] = -(n * 10 + n - 1);
        group(arr, len + 1, n - 2);
    }
    if (n == 0)
    {
        int sum = 0;
        for (int i = 0; i < len; i++)
        {
            sum += arr[i];
        }
        if (sum == 100 && arr[0] > 0)
        {
            printf("%d ", arr[0]);
            for (int i = 1; i < len; i++)
            {
                printf("%c %d ", (arr[i] > 0 ? '+' : '-'), abs(arr[i]));
            }
            printf("= %d", sum);
            printf("\n");
        }
    }
}

int main()
{
    int arr[20];

    group(arr, 0, 9);
}