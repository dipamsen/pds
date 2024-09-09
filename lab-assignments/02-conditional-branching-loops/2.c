#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
	int n;
	
	do {
		printf("Enter number of correct decimal places: ");
		scanf("%d", &n);
	} while (8 <= n || n <= 1);
	
	double rec = 0;
	double prev = 0;
	
	double maxdiff = pow(10, -n-1);
	
	int sgn = 1;
	for (int i = 0; ; i++, sgn *= -1) {
		int fact = 1;
		if (i > 0) {
			for (int j = 1; j <= i; j++) {
				fact *= j;
			}
		}
		prev = rec;
		rec += sgn * 1.0 / fact;
		
		if (fabs((1.0 / rec) - (1.0 / prev)) < maxdiff) break;
		
	}
	
	printf("Result: ");
	switch(n) {
		case 2: 
			printf("%.2lf", (1.0 / rec));
			break;
		case 3: 
			printf("%.3lf", (1.0 / rec));
			break;
		case 4: 
			printf("%.4lf", (1.0 / rec));
			break;
		case 5: 
			printf("%.5lf", (1.0 / rec));
			break;
		case 6: 
			printf("%.6lf", (1.0 / rec));
			break;
		case 7: 
			printf("%.7lf", (1.0 / rec));
			break;
	}
	
	printf("\n");
}
