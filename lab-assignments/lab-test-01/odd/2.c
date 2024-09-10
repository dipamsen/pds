#include <stdio.h>

void group_dup(int arr[], int len)
{
	int i;
	for (i = 0; i < len - 1; i++)
	{
		int j;
		for (j = i + 1; j < len; j++)
		{
			if (arr[j] == arr[i])
				break;
		}

		if (j < len)
		{
			// swap arr[i+1] and arr[j]
			int t = arr[j];
			arr[j] = arr[i + 1];
			arr[i + 1] = t;
		}
	}
}

void rec_group_dup(int arr[], int len, int start)
{
	if (len == start)
		return;
	for (int i = start + 1; i < len; i++)
	{
		if (arr[i] == arr[start])
		{
			// swap arr[i] and arr[start + 1]
			int t = arr[i];
			arr[i] = arr[start + 1];
			arr[start + 1] = t;
			break;
		}
	}
	rec_group_dup(arr, len, start + 1);
}

void group_dup_freq(int arr[], int len)
{
	int i = 0; // start
	while (i < len)
	{
		int maxNum = 0, maxOcc = 0, maxIndex;
		int currNum = 0, currOcc = 0;
		int j;
		for (j = i; j < len; j++)
		{
			if (currNum == arr[j])
				currOcc++;
			else
			{
				if (maxOcc < currOcc)
				{
					maxOcc = currOcc;
					maxNum = currNum;
					maxIndex = j - maxOcc;
				}
				currNum = arr[j];
				currOcc = 1;
			}
		}
		if (maxOcc < currOcc)
		{
			maxOcc = currOcc;
			maxNum = currNum;
			maxIndex = j - maxOcc;
		}

		for (int k = maxIndex - 1; k >= i; k--)
		{
			arr[k + maxOcc] = arr[k];
		}
		for (int k = 0; k < maxOcc; k++)
		{
			arr[i + k] = maxNum;
		}

		i += maxOcc;
	}
}

void rec_group_dup_freq(int arr[], int len, int start)
{
	if (len == start)
		return;
	// from arr[start] to arr[len-1], find which number appears most frequently

	int currNum = 0;
	int currOcc = 0;
	int startIndex = 0;
	int maxNum = 0;
	int maxOcc = 0;
	int maxStartIndex = 0;
	for (int i = start; i < len; i++)
	{
		if (currNum == arr[i])
		{
			currOcc++;
		}
		else
		{
			if (maxOcc < currOcc)
			{
				maxOcc = currOcc;
				maxNum = currNum;
				maxStartIndex = startIndex;
			}
			currNum = arr[i];
			currOcc = 1;
			startIndex = i;
		}
	}
	if (maxOcc < currOcc)
	{
		maxOcc = currOcc;
		maxNum = currNum;
		maxStartIndex = startIndex;
	}

	// maxNum occurs most number of times
	// move them to the front of the array

	for (int i = maxStartIndex - 1; i >= start; i--)
	{
		arr[i + maxOcc] = arr[i];
	}
	for (int i = start; i < start + maxOcc; i++)
	{
		arr[i] = maxNum;
	}

	rec_group_dup_freq(arr, len, start + maxOcc);
}

int main()
{
	int A[100];
	int i;
	printf("Enter input array (terminate with 0 or negative): ");
	for (i = 0; i < 100; i++)
	{
		int num;
		scanf("%d", &num);
		if (num > 0)
			A[i] = num;
		else
			break;
	}

	int len = i;

	printf("\nInput array by the user\n");
	printf("\nA[%d] = ", len);
	for (i = 0; i < len; i++)
		printf("%d ", A[i]);
	printf("\n\n");

	int choice1;
	do
	{
		printf("User choice for grouping duplicates : ");
		scanf("%d", &choice1);
	} while (choice1 < 1 || choice1 > 2);

	switch (choice1)
	{
	case 1:
		printf("Non-recursive function group_dup() is chosen\n");
		group_dup(A, len);
		break;
	case 2:
		printf("Recursive function rec_group_dup() is chosen\n");
		rec_group_dup(A, len, 0);
		break;
	}

	printf("\nA[%d] = ", len);
	for (i = 0; i < len; i++)
		printf("%d ", A[i]);
	printf("\n\n");

	int choice2;
	do
	{
		printf("User choice for arranging sequences of duplicates : ");
		scanf("%d", &choice2);
	} while (choice2 < 1 || choice2 > 2);

	switch (choice2)
	{
	case 1:
		printf("Non-recursive function group_dup_freq() is chosen\n");
		group_dup_freq(A, len);
		break;
	case 2:
		printf("Recursive function rec_group_dup_freq() is chosen\n");
		rec_group_dup_freq(A, len, 0);
		break;
	}

	printf("\nA[%d] = ", len);
	for (i = 0; i < len; i++)
		printf("%d ", A[i]);
	printf("\n");

	return 0;
}
