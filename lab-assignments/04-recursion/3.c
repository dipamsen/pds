#include <stdio.h>

long int sum_of_two_strings(char str1[], char str2[]) {
	int len1 = 0, len2 = 0;
	
	while (str1[len1] != '\0') len1++;
	while (str2[len2] != '\0') len2++;
	
	long int output = 0;
	long int mult = 1;
	
	while (len1 > 0 || len2 > 0) {
		if (len1 > 0) {
			output += (str1[--len1] - 48) * mult;
		}
		if (len2 > 0) {
			output += (str2[--len2] - 48) * mult;
		}
		mult *= 10;
	}
	return output;
}

int main() {

	char s1[100];
	char s2[100];
	
	printf("Enter string1: ");
	scanf("%s", s1);
	
	printf("Enter string2: ");
	scanf("%s", s2);
	
	printf("The sum of two strings is %ld\n", sum_of_two_strings(s1, s2));
	
	return 0;
}
