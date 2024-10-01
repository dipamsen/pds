#include <stdio.h>
#include <stdlib.h>

float *input_arr(int n) {
	float *output = malloc(n * sizeof(float));
	if (output == NULL) {
		printf("Memory not available.\n");
		exit(1);
	}
	int i;
	printf("Enter Array x = ");
	for (i = 0; i < n; i++) {
		scanf("%f", output + i);
	}
	
	return output;
}

float mean_arr(float *arr, int n) {
	float sum = 0;
	int i;
	for (i = 0; i < n; i++) {
		sum += *(arr + i);
	}
	return sum / n;
}

float absolute(float x) {
	return (x > 0) ? x : -x;
}


void insert_mean_arr(float *arr, int n, float elt) {
	// figure out where to insert elt
	float minAbsDiff = absolute(elt - *arr);
	int index = 0;
	int i;
	for (i = 1; i < n-1; i++) {
		float absDiff = absolute(elt - *(arr + i));
		if (absDiff < minAbsDiff) {
			minAbsDiff = absDiff;
			index = i;
		}
	}
	
	// shift all elements from index to end 1 block ahead
	for (i = n - 2; i >= index; i--) {
		*(arr + i + 1) = *(arr + i);
	}
	// put elt at index
	*(arr + index) = elt;
}

void display_arr(float *arr, int n) {
	int i;
	for (i = 0; i < n; i++) {
		printf("%.3f\t", *(arr + i));
	}
	printf("\n");
}

int main() {
	int n;
	printf("Enter size of array x: ");
	scanf("%d", &n);
	
	float *arr = input_arr(n);
	
	float mean = mean_arr(arr, n);
	printf("Mean (M) = %f\n", mean);
	
	// resize arr
	arr = realloc(arr, (n + 1) * sizeof(float));
	if (arr == NULL) {
		printf("Memory not available.\n");
		exit(1);
	}
	n++;
	

	
	insert_mean_arr(arr, n, mean);
	
	printf("Array after insertion of Mean = ");
	display_arr(arr, n);
	
	free(arr);
	
	return 0;
}
