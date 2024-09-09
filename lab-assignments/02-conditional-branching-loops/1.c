#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
	int n;
	double pi = 3.1415926535; // sum formulae never converges to 22/7, leading to an infinite loop; so using hardcoded value of pi
	
	double est1 = 0;
	double est2 = 0;
	
	double sum1 = 0, sum2 = 0;
	
	do {
		printf("Enter precision (number of correct decimal places): ");
		scanf("%d", &n);
	} while (n >= 9 || n <= 0);
	
	double maxdiff = pow(10, -n-1); // for checking correct upto n places
	
	// eq 1
	long long int i = 1;
	while (1) {
		sum1 += 1.0 / (i * i);
		est1 = sqrt(6 * sum1);
		
		if (fabs(est1 - pi) < maxdiff) {
			break;
		}
		
		i++;
	}
	
	printf("For series 1, number of iterations required = %lld\n", i);
	printf("Estimate (upto %d places): ", n);
	if (n == 1) {
		printf("%.1lf\n\n", est1);
	} else if (n == 2) {
		printf("%.2lf\n\n", est1);
	} else if (n == 3) {
		printf("%.3lf\n\n", est1);
	} else if (n == 4) {
		printf("%.4lf\n\n", est1);
	} else if (n == 5) {
		printf("%.5lf\n\n", est1);
	} else if (n == 6) {
		printf("%.6lf\n\n", est1);
	} else if (n == 7) {
		printf("%.7lf\n\n", est1);
	} else if (n == 8) {
		printf("%.8lf\n\n", est1);
	} 
	
	
	long long int j = 1;
	int sgn = 1;
	while (1) {
		sum2 += (sgn * 4.0) / (2 * j - 1);
		est2 = sum2;
		
		if (fabs(est2 - pi) < maxdiff) {
			break;
		}
		j++;
		sgn *= -1;
	}
	
	printf("For series 2, number of iterations required = %lld\n", j);
	printf("Estimate (upto %d places): ", n);
	
	if (n == 1) {
		printf("%.1lf\n\n", est2);
	} else if (n == 2) {
		printf("%.2lf\n\n", est2);
	} else if (n == 3) {
		printf("%.3lf\n\n", est2);
	} else if (n == 4) {
		printf("%.4lf\n\n", est2);
	} else if (n == 5) {
		printf("%.5lf\n\n", est2);
	} else if (n == 6) {
		printf("%.6lf\n\n", est2);
	} else if (n == 7) {
		printf("%.7lf\n\n", est2);
	} else if (n == 8) {
		printf("%.8lf\n\n", est2);
	} 
	
}
