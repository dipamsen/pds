/*
p2] Swap 2 numbers: [25 marks]
Write a C program to swap two given numbers. You need to assign the
input numbers (from the keyboard) to two variables “x” and “y”. You need
to perform the swapping of the values associated to the variables and
print the variables before and after swapping.
a] using 1 extra variable.
b] without using any extra variable.
*/

#include <stdio.h>

int main() {
	
	int x, y;
	
	printf("PART A\n\n");
	
	printf("Enter two integers: ");
	scanf("%d %d", &x, &y);
	
	printf("Before swapping: ");
	printf("x = %d, y = %d\n", x, y);
	
	int temp = y;
	y = x;
	x = temp;
	
	printf("After swapping: ");
	printf("x = %d, y = %d\n", x, y);
	
	printf("\n\nPART B\n\n");
	
	printf("Enter two numbers: ");
	scanf("%d %d", &x, &y);
	
	printf("Before swapping: ");
	printf("x = %d, y = %d\n", x, y);
	
	x = x + y;
	y = x - y;
	x = x - y;
	
	// x = 2 y = 4
	// x = 6 y = 4
	// x = 6 y = 2
	// x = 4 y = 2
	
	printf("After swapping: ");
	printf("x = %d, y = %d\n", x, y);
	
	
	return 0;
}
