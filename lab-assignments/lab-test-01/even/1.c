#include <stdio.h>

int isBinary(long long int n)
{
	while (n > 0)
	{
		if ((n % 10) != 0 && (n % 10) != 1)
			return 0;
		n /= 10;
	}

	return 1;
}

int num_bits(long long int n)
{
	int i = 0;
	while (n > 0)
	{
		i++;
		n /= 10;
	}
	return i;
}

long long int bitwise_nor(long long int a, long long int b)
{
	int lena = num_bits(a);
	int lenb = num_bits(b);
	int max = (lena > lenb) ? lena : lenb;

	long long int output = 0;

	long long int m = 1;
	int i;
	for (i = 0; i < max; i++)
	{
		// a % 10 NOR b % 10
		int x = a % 10;
		int y = b % 10;
		if (x == 0 && y == 0)
		{ // if both operands are 0
			// NOR = 1
			output += 1 * m;
		} // else NOR = 0

		a /= 10;
		b /= 10;

		m *= 10;
	}

	return output;
}

int main()
{
	long long int a, b;

	while (1)
	{
		printf("Enter first binary number: ");
		scanf("%lld", &a);
		if (isBinary(a))
			break;
		printf("The entered binary number is not valid. Enter the correct one.\n");
	}
	printf("The entered binary number is valid and has %d bits.\n", num_bits(a));

	while (1)
	{
		printf("Enter second binary number: ");
		scanf("%lld", &b);
		if (isBinary(b))
			break;
		printf("The entered binary number is not valid. Enter the correct one.\n");
	}
	printf("The entered binary number is valid and has %d bits.\n", num_bits(b));

	printf("Bitwise NOR of %lld and %lld is %lld\n", a, b, bitwise_nor(a, b));

	return 0;
}
