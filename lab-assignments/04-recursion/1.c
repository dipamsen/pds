#include <stdio.h>

int recaman(int n, int arr[]) {
	if (n == 0) return 0;
	int prev = recaman(n-1, arr);
	int v = prev - n;
	int flag = 0;
	int i;
	for (i = 0; i < n - 1; i++) {
		if (arr[i] == v) {
			flag = 1;
			break;
		}
	}
	if (v > 0 && flag == 0) // v is positive and is not already present in the sequence
	{
		arr[n-1] = v; // a_n is stored in arr[n - 1] since a_1 is stored in arr[0] (output starts with a_1)
	}
	else 
	{
		arr[n-1] = prev + n;
	}
	return arr[n-1];
}

int main(void) {
	int num;
	printf("Enter number of terms of Recaman's sequence to calculate: ");
	scanf("%d", &num);
	
	int arr[1000];
	
	recaman(num, arr);
	for (int i = 0; i < num; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
	return 0;
}
