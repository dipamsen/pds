#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define N 4

int *myFun(int grid[N][N], int max) {
	int *histogram = malloc(max * sizeof(int));
	if (histogram == NULL) {
		printf("Error in allocating memory.\n");
		exit(1);
	}
	for (int i = 0; i < max; i++) histogram[i] = 0;
	for (int i = 0; i < N; i++) for (int j = 0; j < N; j++)	histogram[grid[i][j]]++;
	return histogram;
}

int main() {
	int grid[N][N], k;
	do {
		printf("Enter k (2 <= k <= 8): ");
		scanf("%d", &k);
	} while (k < 2 || k > 8);
	
	int maxVal = 1 << k; // 2^k; (non inclusive max)
	
	for (int i = 0; i < N; i++) for (int j = 0; j < N; j++)	grid[i][j] = rand() % maxVal;

	int *histogram = myFun(grid, maxVal);
	int freqSum = 0;
	printf("Int.    Freq.\n");
	for (int i = 0; i < maxVal; i++) {
		printf("%-5d   %-5d\n", i, histogram[i]);
		freqSum += histogram[i];
	}
	printf("\nThe size of the matrix is %d and the sum of frequency values is %d.\n", N * N, freqSum);
	free(histogram);
	return 0;
}
