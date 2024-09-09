#include <stdio.h>

void decrypt(char message[], int l, int r) {
	if (l >= r) return;
	
	char temp = message[r];
	message[r] = message[l];
	message[l] = temp;
	
	decrypt(message, l + 1, r - 1);
}

int main() {
	char message[1000];
	
	char c;
	int len = 0;
	printf("Enter encrypted text: ");
	fgets(message, 1000, stdin); // input string from console (upto newline)
	
	while (message[len] != '\n') len++;
	
	decrypt(message, 0, len - 1);
	
	printf("Decrypted message: %s\n", message);
}
