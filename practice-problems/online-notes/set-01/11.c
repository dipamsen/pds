#include <stdio.h>

int gcd(int a, int b)
{
    if (b == 0)
    {
        return a;
    }
    return gcd(b, a % b);
}

int abs(int x)
{
    return (x > 0) ? x : -x;
}

void lowest(int a, int b)
{
    int neg = (a < 0 && b > 0) || (a > 0 && b < 0);
    int g = gcd(abs(a), abs(b));
    if (neg)
        printf("%d/%d", -a / g, b / g);
    else
        printf("%d/%d", a / g, b / g);
}

int main()
{

    int a, b, c, d;
    printf("Enter four integers: ");
    scanf("%d%d%d%d", &a, &b, &c, &d);

    // 1.
    int rsn1 = a * c + b * d;
    int rsd1 = c * c + d * d;

    int uvn1 = b * c - a * d;
    int uvd1 = c * c + d * d;

    printf("(%d + i%d) / (%d + i%d) = %d/%d + i %d/%d = ", a, b, c, d, rsn1, rsd1, uvn1, uvd1);
    lowest(rsn1, rsd1);
    printf(" + i ");
    lowest(uvn1, uvd1);
    printf("\n");

    // 2.

    int rsn2 = a * c + b * d;
    int rsd2 = a * a + b * b;

    int uvn2 = a * d - b * c;
    int uvd2 = a * a + b * b;

    printf("(%d + i%d) / (%d + i%d) = %d/%d + i %d/%d = ", c, d, a, b, rsn2, rsd2, uvn2, uvd2);
    lowest(rsn2, rsd2);
    printf(" + i ");
    lowest(uvn2, uvd2);
    printf("\n");

    return 0;
}