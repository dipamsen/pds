#include <stdio.h>
#include <math.h>

int main()
{
    int a, b, c, d, e;
    printf("Enter 5 integers: ");
    scanf("%d%d%d%d%d", &a, &b, &c, &d, &e);

    float avg = (a + b + c + d + e) / 5.0;
    printf("Arithmetic Mean: %f\n", avg);
    printf("Geometric Mean: %f\n", pow(a * b * c * d * e, 0.2));
    printf("Harmonic Mean: %f\n", 5.0 / (1.0 / a + 1.0 / b + 1.0 / c + 1.0 / d + 1.0 / e));

    float mos = (a * a + b * b + c * c + d * d + e * e) / 5.0;
    printf("Standard Deviation: %f\n", sqrt(mos - avg * avg));
    return 0;
}