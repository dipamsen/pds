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

char *rise_str(char *s, int n) {
	char *output = malloc((n + 1) * sizeof(char));
	int sz = 0;
	
	int wordInit = 0;
	char p = '\0'; // prev char
	int addCurrWord = 1;
	
	int i;
	for (i = 0; i <= n; i++) {
		if (i == n || *(s + i) == ' ') {
			if (addCurrWord) {
				if (sz != 0) { // add a space if this is not the first word found
					*(output + sz) = ' ';
					sz++;
				}
			
				// copy wordInit to i - 1 into output
				int j;
				for (j = wordInit; j < i; j++) {
					*(output + sz) = *(s + j);
					sz++;
				}
			}
		
			// reset variables
			wordInit = i + 1;
			addCurrWord = 1;
			p = '\0';
		} else {
			char c = *(s + i);
			if (addCurrWord && p != '\0' && p >= c) {
				// not rising :(
				addCurrWord = 0;
			}
			p = c;
		}
	}
	
	output = realloc(output, (sz + 1) * sizeof(char));
	*(output + sz) = '\0';
	return output;
}


char *fall_str(char *s, int n) {
	char *output = malloc((n + 1) * sizeof(char));
	int sz = 0;
	
	int wordInit = 0;
	char p = '\0'; // prev char
	int addCurrWord = 1;
	
	int i;
	for (i = 0; i <= n; i++) {
		if (i == n || *(s + i) == ' ') {
			if (addCurrWord) {
				if (sz != 0) { // add a space if this is not the first word found
					*(output + sz) = ' ';
					sz++;
				}
			
				// copy wordInit to i - 1 into output
				int j;
				for (j = wordInit; j < i; j++) {
					*(output + sz) = *(s + j);
					sz++;
				}
			}
		
			// reset variables
			wordInit = i + 1;
			addCurrWord = 1;
			p = '\0';
		} else {
			char c = *(s + i);
			if (addCurrWord && p != '\0' && p <= c) {
				// not falling 
				addCurrWord = 0;
			}
			p = c;
		}
	}
	
	output = realloc(output, (sz + 1) * sizeof(char));
	*(output + sz) = '\0';
	return output;
}


char *rise_fall_str(char *s, int n) {
	char *output = malloc((n + 1) * sizeof(char));
	int sz = 0;
	
	int wordInit = 0;
	char p = '\0'; // prev char
	int addCurrWord = 1;
	int shouldRise = -1;
	
	int i;
	for (i = 0; i <= n; i++) {
		if (i == n || *(s + i) == ' ') {
			if (addCurrWord) {
				if (sz != 0) { // add a space if this is not the first word found
					*(output + sz) = ' ';
					sz++;
				}
			
				// copy wordInit to i - 1 into output
				int j;
				for (j = wordInit; j < i; j++) {
					*(output + sz) = *(s + j);
					sz++;
				}
			}
		
			// reset variables
			wordInit = i + 1;
			addCurrWord = 1;
			p = '\0';
		} else {
			char c = *(s + i);
			if (addCurrWord && p != '\0') {
				if (shouldRise == -1) {
					// first two chars
					if (c > p) shouldRise = 0;
					else if (c < p) shouldRise = 1;
					else addCurrWord = 0;
				} else {
					if ((shouldRise && c > p) || (!shouldRise && c < p)) {
						shouldRise = 1 - shouldRise; // alternate rise/fall
					} else { // did not follow pattern
						addCurrWord = 0;
					}
				}
			}
			p = c;
		}
	}
	
	output = realloc(output, (sz + 1) * sizeof(char));
	*(output + sz) = '\0';
	return output;
}


char *flat_str(char *s, int n) {
	char *output = malloc((n + 1) * sizeof(char));
	int sz = 0;
	
	int wordInit = 0;
	char p = '\0'; // prev char
	int addCurrWord = 1;
	
	int i;
	for (i = 0; i <= n; i++) {
		if (i == n || *(s + i) == ' ') {
			if (addCurrWord) {
				if (sz != 0) { // add a space if this is not the first word found
					*(output + sz) = ' ';
					sz++;
				}
			
				// copy wordInit to i - 1 into output
				int j;
				for (j = wordInit; j < i; j++) {
					*(output + sz) = *(s + j);
					sz++;
				}
			}
		
			// reset variables
			wordInit = i + 1;
			addCurrWord = 1;
			p = '\0';
		} else {
			char c = *(s + i);
			if (addCurrWord && p != '\0') {
				if (p != c) addCurrWord = 0;
			}
			p = c;
		}
	}
	
	output = realloc(output, (sz + 1) * sizeof(char));
	*(output + sz) = '\0';
	return output;
}



void display_str(char *str) {
	while (*str != '\0') printf("%c", *(str++));
	printf("\n");
}

int main() {
	int n;
	printf("Enter length of string: ");
	scanf("%d", &n);
	
	char *str = input_str(n);
	
	char *rising = rise_str(str, n);
	printf("rise_str: ");
	display_str(rising);
	
	char *falling = fall_str(str, n);
	printf("fall_str: ");
	display_str(falling);
	
	char *risingfalling = rise_fall_str(str, n);
	printf("rise_fall_str: ");
	display_str(risingfalling);
	
	char *flat = flat_str(str, n);
	printf("fall_str: ");
	display_str(flat);
	
	free(str);
	free(rising);
	free(falling);
	free(risingfalling);
	free(flat);
	
	return 0;
}
