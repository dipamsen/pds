/*
p4] In this problem, you need to compute the derivative of a degree-5
polynomial of one variable x: a5 x^5 + a4 x^4 + a3 x^3 + a2 x^2 + a1 x + a0 
[25 marks]
Assume that the coefficients ai of the polynomial are integers. Input the 6
coefficients from the user. Print the polynomial, and then compute and
print the derivative polynomial.
*/

#include <stdio.h>

int main() {
	int a5, a4, a3, a2, a1, a0;
	
	printf("Enter the constant term: ");
	scanf("%d", &a0);
	
	printf("Enter the coefficient of x: ");
	scanf("%d", &a1);
	
	printf("Enter the coefficient of x^2: ");
	scanf("%d", &a2);
	
	printf("Enter the coefficient of x^3: ");
	scanf("%d", &a3);
	
	printf("Enter the coefficient of x^4: ");
	scanf("%d", &a4);
	
	printf("Enter the coefficient of x^5: ");
	scanf("%d", &a5);
	
	printf("\n");
	
	// let derivative polynomial be
	// d(x) = d4 x^4 + d3 x^3 + d2 x^2 + d1 x + d0
	int d4, d3, d2, d1, d0;
	
	d4 = a5 * 5;
	d3 = a4 * 4;
	d2 = a3 * 3;
	d1 = a2 * 2;
	d0 = a1;
	
	// note: negative terms are printed with plus sign prepended
	// because of hardcoded +, to fix it we need to conditionally
	// check whether each term is positive or negative, and print 
	// the sign accordingly.
	printf("Polynomial is %d*x^5 + %d*x^4 + %d*x^3 + %d*x^2 + %d*x + %d\n", a5, a4, a3, a2, a1, a0);
	printf("Derivative is %d*x^4 + %d*x^3 + %d*x^2 + %d*x + %d\n", d4, d3, d2, d1, d0);
	
	return 0;
}
