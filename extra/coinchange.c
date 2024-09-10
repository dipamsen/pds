// Given a number k, find minimum number of coins of denomination 3, 8, 10 required to get a total value of k.
// Return -1 if no possible combination exists.
// Eg. k = 3 -> 1
//     k = 13 -> 2 (10 + 3)
//     k = 16 -> 2 (8 + 8)

#include <stdio.h>

int minpositive(int a, int b, int c)
{
    if (a < 0 && b < 0 && c < 0)
        return -1;
    if (a < 0)
    {
        if (b < 0)
            return c;
        if (c < 0)
            return b;
        return (b > c) ? c : b;
    }
    if (b < 0)
    {
        if (c < 0)
            return a;
        return (a > c) ? c : a;
    }
    if (c < 0)
    {
        return (a > b) ? b : a;
    }
    return (a > b) ? ((b > c) ? c : b) : ((a > c) ? c : a);
}

int change(int k)
{
    if (k < 3)
        return -1;
    if (k == 3 || k == 8 || k == 10)
        return 1;

    int a = change(k - 3);
    int b = change(k - 8);
    int c = change(k - 10);

    if (a < 0 && b < 0 && c < 0)
        return -1;
    return minpositive(a, b, c) + 1;
}

int main()
{
    int n;
    scanf("%d", &n);

    int o = change(n);
    if (o > 0)
        printf("%d coins required for %d\n", o, n);
    else
        printf("Not possible for %d.\n", n);

    return 0;
}