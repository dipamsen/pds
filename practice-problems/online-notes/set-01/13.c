#include <stdio.h>

float absf(float x)
{
    return x > 0 ? x : -x;
}

int equal(float a, float b)
{
    return absf(a - b) < 0.00001;
}

int main()
{
    float a, b, c, d, e, f;
    printf("Enter first line (a x + b y = c): ");
    scanf("%f %f %f", &a, &b, &c);

    printf("Enter second line (d x + e y = f): ");
    scanf("%f %f %f", &d, &e, &f);

    printf("\n");
    printf("Lines entered: \n");
    printf("%f x + %f y = %f\n", a, b, c);
    printf("%f x + %f y = %f\n", d, e, f);
    printf("\n");

    float x, y;

    // a x + b y = c
    // d x + e y = f

    if (b == 0)
    {
        // inf slope (vertical line)
        // x = c / a
        if (e == 0)
        {
            // x = f / d
            if (equal(f / d, c / a))
            {
                printf("Lines are coincident. Infinite intersection points.");
            }
            else
            {
                printf("Lines are parallel. No intersection point.");
            }
        }
        else
        {
            x = c / a;
            y = (f - d * c / a) / e;
            printf("Intersection point: (%f, %f)", x, y);
        }
    }
    else if (e == 0)
    {
        // x = f / d
        x = f / d;
        y = (c - a * f / d) / b;
        printf("Intersection point: (%f, %f)", x, y);
    }
    else
    {
        float m1 = -1.0 * a / b;
        float m2 = -1.0 * d / e;

        if (equal(m1, m2))
        {
            if (c * d == a * f)
            {
                printf("Lines are coincident. Infinite intersection points.");
            }
            else
            {
                printf("Lines are parallel. No intersection point.");
            }
        }
        else
        {
            // | a b ||x| = | c |
            // | d e ||y|   | f |
            // |x| =     1     |  e -b || c |
            // |y|   (ae - bd) | -d  a || f |
            x = (e * c - b * f) / (a * e - b * d);
            y = (-c * d + a * f) / (a * e - b * d);
            printf("Intersection point: (%f, %f)", x, y);
        }
    }
}