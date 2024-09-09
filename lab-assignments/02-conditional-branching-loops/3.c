#include <stdio.h>

int main() {
	char c;
	printf("Enter any string of characters:\n");
	do {
		scanf("%c", &c);
		
		
		if (c >= 'a' && c <= 'z') {
			c -= 32; // conversion to block
		}
		
		switch (c) {
			case 'A':
			case 'E':
			case 'I':
			case 'O':
			case 'U':
				printf("Vowel          %c\n", c);
				break;
				
			case '0':
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6': 
			case '7':
			case '8':
			case '9':
				printf("Digit          %c\n", c);
				break;
				
			case 'B':
			case 'C':
			case 'D':
			case 'F': 
			case 'G':
			case 'H':
			case 'J':
			case 'K':
			case 'L':
			case 'M':
			case 'N':
			case 'P': 
			case 'Q':
			case 'R':
			case 'S':
			case 'T':
			case 'V':
			case 'W':
			case 'X':
			case 'Y':
			case 'Z':
				printf("Consonant      %c\n", c);
				break;
			
			case '+':
			case '-':
			case '*':
			case '/':
			case '%':
				printf("BinaryOperator %c\n", c);
				break;
			
			case ',':
			case ':':
			case ';':
			case '\'':
			case '\"':
				printf("Punctuator     %c\n", c);
				break;
			
			case '(':
			case ')':
			case '{':
			case '}':
			case '[':
			case ']':
				printf ("Bracket        %c\n", c);
				break;
				
			default:
				break;
		}
		
		
		
	} while (c != '\n');
}
