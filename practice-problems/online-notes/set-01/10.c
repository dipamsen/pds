#include <stdio.h>

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    else
        return gcd(b, a % b);
}
int abs(int x)
{
    return (x > 0) ? x : -x;
}

void printlowest(int n, int d)
{
    int g = gcd(abs(n), abs(d));
    printf("%d/%d", n / g, d / g);
}

int main()
{
    int a, b, c, d;
    printf("Enter 4 integers: ");
    scanf("%d%d%d%d", &a, &b, &c, &d);

    printf("a/b + c/d = %d/%d = ", a * d + b * c, b * d);
    printlowest(a * d + b * c, b * d);
    printf("\n");

    printf("a/b - c/d = %d/%d = ", a * d - b * c, b * d);
    printlowest(a * d - b * c, b * d);
    printf("\n");

    printf("a/b * c/d = %d/%d = ", a * c, b * d);
    printlowest(a * c, b * d);
    printf("\n");
    return 0;
}