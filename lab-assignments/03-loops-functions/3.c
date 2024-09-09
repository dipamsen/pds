#include <stdio.h>

int min_max(int length, int max, int min);
int word_equal(int pl, int cl);
void output(int nc, int nw, int max, int min, int ne);

int main() {
	int failed = 0;
	do {
		char c;
		int newWord = 1;
		int currLen = 0, prevLen = 0;
		failed = 0;
		
		int max = 0, min = 0, chars = 0, words = 0, pairs = 0;
	
		printf("Enter the input text using only alphabets: ");
		do {
			scanf("%c", &c);
			if (!failed) {
				if (newWord) {
					printf("word[%d] = ", words + 1);
					newWord = 0;
				}
				
				if (c == ' ' || c == '\n') { // end of word
					printf("\nLength of word[%d] = %d\n\n", words + 1, currLen);
					
					if (word_equal(prevLen, currLen)) pairs++;
					
					// edge case for first iteration
					// since the function only returns either 1 or -1 but not both
					if (min == 0 && max == 0) max = min = currLen; 
					
					switch (min_max(currLen, max, min)) {
						case 1: max = currLen; break;
						case -1: min = currLen; break;
						case 0: break;
					}
					
					prevLen = currLen;
					
					words++;
					
					currLen = 0;
					newWord = 1;
				} else if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
					chars++;
					printf("%c", c);
					currLen++;
				} else {
					printf("\nEnter the correct input again.\n\n");
					failed = 1;
					continue;
				}
				failed = 0;
			}
		} while (c != '\n');
		
		if (!failed) {

			output(chars, words, max, min, pairs);
		}
	} while (failed == 1);
	
	return 0;
}

int min_max(int length, int max, int min) {
	if (length >= max) return 1;
	else if (length <= min) return -1;
	else return 0;
}

int word_equal(int pl, int cl) {
	return (pl == cl);
}

void output(int nc, int nw, int max, int min, int ne) {
	printf("Number of characters = %d\n", nc);
	printf("Number of words = %d\n", nw);
	printf("Maximum size of the words = %d\n", max);
	printf("Minimum size of the words = %d\n", min);
	printf("Number of pairs of successive words of equal size = %d\n", ne);
}
