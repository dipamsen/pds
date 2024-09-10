#include <stdio.h>

void group_char(char str[], int len)
{
	int i;
	for (i = 0; i < len - 1; i++)
	{
		int j;
		for (j = i + 1; j < len; j++)
		{
			if (str[j] == str[i])
				break;
		}

		if (j < len)
		{
			// swap str[i+1] and str[j]
			char t = str[j];
			str[j] = str[i + 1];
			str[i + 1] = t;
		}
	}
}

void rec_group_char(char str[], int len, int start)
{
	if (len == start)
		return;
	for (int i = start + 1; i < len; i++)
	{
		if (str[i] == str[start])
		{
			// swap str[i] and str[start + 1]
			int t = str[i];
			str[i] = str[start + 1];
			str[start + 1] = t;
			break;
		}
	}
	rec_group_char(str, len, start + 1);
}

void group_char_freq(char str[], int len)
{
	int i = 0; // start
	while (i < len)
	{
		char minChar = 0;
		int minOcc = 201, minIndex;
		char currChar = 0;
		int currOcc = 201;
		int j;
		for (j = i; j < len; j++)
		{
			if (currChar == str[j])
				currOcc++;
			else
			{
				if (minOcc > currOcc)
				{
					minOcc = currOcc;
					minChar = currChar;
					minIndex = j - minOcc;
				}
				currChar = str[j];
				currOcc = 1;
			}
		}
		if (minOcc > currOcc)
		{
			minOcc = currOcc;
			minChar = currChar;
			minIndex = j - minOcc;
		}

		for (int k = minIndex - 1; k >= i; k--)
		{
			str[k + minOcc] = str[k];
		}
		for (int k = 0; k < minOcc; k++)
		{
			str[i + k] = minChar;
		}

		i += minOcc;
	}
}

void rec_group_char_freq(char str[], int len, int start)
{
	if (len == start)
		return;
	// from str[start] to str[len-1], find which char appears least frequently

	char currChar = 0;
	int currOcc = 201;
	int startIndex = 0;
	char minChar = 0;
	int minOcc = 201;
	int minStartIndex = 0;
	for (int i = start; i < len; i++)
	{
		if (currChar == str[i])
		{
			currOcc++;
		}
		else
		{
			if (minOcc > currOcc)
			{
				minOcc = currOcc;
				minChar = currChar;
				minStartIndex = startIndex;
			}
			currChar = str[i];
			currOcc = 1;
			startIndex = i;
		}
	}
	if (minOcc > currOcc)
	{
		minOcc = currOcc;
		minChar = currChar;
		minStartIndex = startIndex;
	}

	// minChar occurs least number of times
	// move them to the front of the stray

	for (int i = minStartIndex - 1; i >= start; i--)
	{
		str[i + minOcc] = str[i];
	}
	for (int i = start; i < start + minOcc; i++)
	{
		str[i] = minChar;
	}

	rec_group_char_freq(str, len, start + minOcc);
}

int main()
{
	char C[200];
	int i;
	printf("Enter input string: ");
	for (i = 0; i < 200; i++)
	{
		char l;
		scanf("%c", &l);
		if (l == '\n')
			break;
		C[i] = l;
	}
	C[i] = '\0';

	int len = i;

	printf("Input string = %s\n", C);

	int choice1;
	do
	{
		printf("User choice for grouping same characters : ");
		scanf("%d", &choice1);
	} while (choice1 < 1 || choice1 > 2);

	switch (choice1)
	{
	case 1:
		printf("Non-recursive function group_char() is chosen\n");
		group_char(C, len);
		break;
	case 2:
		printf("Recursive function rec_group_char() is chosen\n");
		rec_group_char(C, len, 0);
		break;
	}

	printf("String after grouping based on character = %s\n", C);

	int choice2;
	do
	{
		printf("User choice for arranging sequences of characters : ");
		scanf("%d", &choice2);
	} while (choice2 < 1 || choice2 > 2);

	switch (choice2)
	{
	case 1:
		printf("Non-recursive function group_char_freq() is chosen\n");
		group_char_freq(C, len);
		break;
	case 2:
		printf("Recursive function rec_group_char_freq() is chosen\n");
		rec_group_char_freq(C, len, 0);
		break;
	}

	printf("String after arranging the sequences in ascending order = %s\n", C);

	return 0;
}
