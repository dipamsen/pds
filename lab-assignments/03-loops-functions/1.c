#include <stdio.h>

int main() {
	int n, i, j;
	printf("Enter number of rows (odd number, 1 <= N <= 30): ");
	scanf("%d", &n);
	while (n < 1 || n > 30 || n % 2 == 0) {
		printf("Invalid input.\n");
		printf("Enter number of rows (odd number, 1 <= N <= 30): ");
		scanf("%d", &n);
	}
	
	int mid = (n + 1) / 2;
	int spaces = mid - 1;
	
	for (i = 1; i <= mid; i++) { // i: row number
		int val = i;
		for (j = 0; j < spaces; j++) {
			printf("   ");
		}
		for (j = 0; j < mid - spaces; j++) {
			printf("%2d ", val);
			val++;
		}
		
		val = 2 * i - 2;
		for (j = 1; j < mid - spaces; j++) {
			printf("%2d ", val);
			val--;
		}
		printf("\n");
		
		spaces--;
	}
	spaces = 1;
	for (i = mid - 1; i > 0; i--) { 
		int val = i;
		for (j = 0; j < spaces; j++) {
			printf("   ");
		}
		for (j = 0; j < mid - spaces; j++) {
			printf("%2d ", val);
			val++;
		}
		
		val = 2 * i - 2;
		for (j = 1; j < mid - spaces; j++) {
			printf("%2d ", val);
			val--;
		}
		printf("\n");
		
		spaces++;
	}

	return 0;
}
