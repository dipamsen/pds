/*
p3] Write a program in C that performs the following tasks: [25 marks]
1. Read a floating-point number x and an integer n from the user.
2. Compute and print the following:
	o Ceiling of x: The smallest integer greater than or equal to x.
	o Floor of x: The largest integer less than or equal to x.
	o Result of dividing x by n as a floating-point number.
	o Result of dividing x by n and casting the result to an integer.
	o Result of dividing n by x as a floating-point number.
	o Result of dividing n by x and casting the result to an integer.
3. Print all floating-point results up to 2 decimal places, to do this you
can use:
printf("%.2f", floating_point_value);
- Include<math.h> [while compiling: gcc 3.c -o 3.out -lm]
- To find ceil of x use: ceil(x)
- To find floor of x use: floor(x)
- To convert a floating-point number to an integer, use the int type cast:
int intValue = (int)x; // Casts float x to int.
- To convert an integer to a floating-point number, use the float type cast:
float floatValue = (float)n; // Casts int n to float
*/
#include <math.h>
#include <stdio.h>

int main() {
	
	float x;
	int n;
	
	printf("Enter a floating point number (x): ");
	scanf("%f", &x);
	printf("Enter an integer (n): ");
	scanf("%d", &n);
	
	printf("\n");
	
	printf("Ceiling of x: %d\n", (int) ceil(x));
	printf("Floor of x: %d\n", (int) floor(x));
	printf("Result of dividing x by n as a floating point number: %.2f\n", x / n);
	printf("Result of dividing x by n and casting the result to an integer: %d\n", (int)(x / n));
	printf("Result of dividing n by x as a floating point number: %.2f\n", n / x);
	printf("Result of dividing n by x and casting the result to an integer: %d\n", (int)(n / x));
	
	return 0;
}
