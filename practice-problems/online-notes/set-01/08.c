#include <stdio.h>

int main()
{

    printf("Problem (a)\n");
    int x1 = -29, x2 = 31;
    int y1 = x1 * x1 * x1 + x1 * x1 - 905 * x1 - 2697;
    int y2 = x2 * x2 * x2 + x2 * x2 - 905 * x2 - 2697;

    printf("p(%d) = %d\n", x1, y1);
    printf("p(%d) = %d\n", x2, y2);

    int sum = -1;
    int x3 = sum - x1 - x2;
    printf("Third root is %d\n\n", x3);

    printf("Problem (b)\n");
    long long int x = -2931;
    long long int y = x * x * x + 2871LL * x * x - 174961LL * x + 2634969LL;
    printf("p(%lld) = %lld\n\n", x, y);

    printf("Problem (c)\n");
    long long int sum2 = -1;
    long long int a = 0, b = 0, c;
    while (a * a * a + a * a - 74034 * a + 5294016LL != 0)
    {
        a++;
    }

    while (b * b * b + b * b - 74034 * b + 5294016LL != 0)
    {
        b--;
    }

    c = sum2 - a - b;

    printf("Roots are %lld, %lld, %lld\n\n", a, b, c);

    printf("Problem (d)\n");
    int sum3 = -1;
    a = 0;
    b = 0;
    while (a * a * a + a * a - 28033 * a - 1815937LL != 0)
    {
        a++;
    }

    while (b * b * b + b * b - 28033 * b - 1815937LL != 0)
    {
        b--;
    }

    c = sum3 - a - b;

    printf("Roots are %lld, %lld, %lld\n\n", a, b, c);

    return 0;
}