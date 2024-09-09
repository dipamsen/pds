#include <stdio.h>

int checkPerfect(int x);
void listPerfectNumbers(int a, int b);

int main() {
	int a, b;
	
	printf("Input the range: ");
	scanf("%d %d", &a, &b);	
	while (a <= 0 || b <= 0 || a >= b) {
		printf("Input Range is incorrect. Enter the correct range.\n");
		printf("Input the range: ");
		scanf("%d %d", &a, &b);
	}
	
	listPerfectNumbers(a, b);

	return 0;
}

int checkPerfect(int x) {
	int sum = 0;
	for (int i = 1; i < x; i++) {
		if (x % i == 0) {
			sum += i;
		}
	}
	if (sum == x) return 1;
	else return 0;
}

void listPerfectNumbers(int a, int b) {
	printf("The perfect numbers between %d and %d are: ", a, b);
	int found = 0;
	for (int i = a; i <= b; i++) {
		if (checkPerfect(i)) {
			printf("%d\t", i);
			found = 1;
		}
	}
	if (!found) {
		printf("(none exist)");
	}
	printf("\n");
}
