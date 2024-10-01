#include <stdio.h>
#include <stdlib.h>

// This program uses '\0' terminated strings so that strings themselves contain information about their size
// since otherwise we would require additional int pointers so that functions can "pass" the sizes into main.

char *input_str(int n) {
	char *str = malloc((n+1) * sizeof(char));
	if (str == NULL) {
		printf("Memory not available.\n");
		exit(1);
	}
	int i;
	
	printf("Enter string : ");
	for (i = 0; i < n; i++) {
		char c = getchar();
		if (c == '\n') {
			i--;
			continue;
		}
		*(str + i) = c;
	}
	*(str + n) = '\0';
	
	return str;
}

char *str_set(char *str, int n) { 
	char *set = malloc((n + 1) * sizeof(char));
	if (set == NULL) {
		printf("Memory not available.\n");
		exit(1);
	}
	int sz = 0;
	int i;
	for (i = 0; i < n; i++) {
		char c = *(str + i);
		// does this char already exist in the set?
		int j;
		for (j = 0; j < sz; j++) if (*(set + j) == c) break;
		if (j == sz) // doesnt exist
		{
			*(set + sz) = c;
			sz++;
		}
	}
	
	set = realloc(set, (sz + 1) * sizeof(char));
	*(set + sz) = '\0';
	return set;
}

char *set_union(char *set1, char *set2) {
	int m = 0, n = 0;
	while (*(set1 + m) != '\0') m++;
	while (*(set2 + n) != '\0') n++;
	char *output = malloc((m + n + 1) * sizeof(char));
	if (output == NULL) {
		printf("Memory not available.\n");
		exit(1);
	}
	int sz = 0, i;
	for (i = 0; i < m; i++) { // copy set1 as is
		*(output + sz) = *(set1 + i);
		sz++;
	}
	
	for (i = 0; i < n; i++) {
		char c = *(set2 + i);
		int j;
		for (j = 0; j < sz; j++) if (*(output + j) == c) break;
		if (j == sz) { // doesnt exist
			// add it
			*(output + sz) = c;
			sz++;
		}
	}
	
	output = realloc(output, (sz + 1) * sizeof(char));
	*(output + sz) = '\0';
	return output;
}


char *set_intersection(char *set1, char *set2) {
	int m = 0, n = 0;
	while (*(set1 + m) != '\0') m++;
	while (*(set2 + n) != '\0') n++;
	char *output = malloc((m + n + 1) * sizeof(char));
	if (output == NULL) {
		printf("Memory not available.\n");
		exit(1);
	}
	int sz = 0, i;
	for (i = 0; i < m; i++) {
		char c = *(set1 + i);
		// does c exist in set2?
		int j;
		for (j = 0; j < n; j++) if (*(set2 + j) == c) break;
		if (j < n) { // yes, it does
			*(output + sz) = c;
			sz++;
		}
	}
	
	output = realloc(output, (sz + 1) * sizeof(char));
	*(output + sz) = '\0';
	return output;
}

void display(char *str) {
	while (*str != '\0') printf("%c", *(str++));
	printf("\n");
}

int main() {
	int n1;
	printf("Enter length of first string: ");
	scanf("%d", &n1);
	char *str1 = input_str(n1);
	
	int n2;
	printf("Enter length of second string: ");
	scanf("%d", &n2);
	char *str2 = input_str(n2);
	
	char *set1 = str_set(str1, n1);
	char *set2 = str_set(str2, n2);
	
	printf("Set-1: ");
	display(set1);
	
	printf("Set-2: ");
	display(set2);
	
	char *union12 = set_union(set1, set2);
	char *intersection12 = set_intersection(set1, set2);
	
	printf("Union of Set-1 and Set-2: ");
	display(union12);
	printf("Intersection of Set-1 and Set-2: ");
	display(intersection12);
	
	free(str1);
	free(str2);
	free(set1);
	free(set2);
	free(union12);
	free(intersection12);
	
	return 0;
	
}
