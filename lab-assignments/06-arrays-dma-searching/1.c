#include <stdio.h>
#include <time.h>
#include <stdlib.h>
int main() {
	srand(time(NULL));
	int n, max, threshold, count = 0;
	printf("Enter size of array: ");
	scanf("%d", &n);
	int *arr = malloc(n * sizeof(int));
	if (arr == NULL) {
		printf("Error in allocating memory.\n");
		exit(1);
	}
	printf("Enter maximum possible value: ");
	scanf("%d", &max);
	for (int i = 0; i < n; i++) 
		arr[i] = rand() % (max + 1); // gets a number from 0 to max (both inclusive), almost uniform distribution
	printf("Enter threshold: ");
	scanf("%d", &threshold);
	for (int i = 0; i < n; i++) if (arr[i] >= threshold) count++;
	printf("Out of %d numbers, %d are equal to or above the given threshold.\n", n, count);
	free(arr);
}
