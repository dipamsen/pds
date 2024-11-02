// different sorting algorithms

#include <stdio.h>
#include <stdlib.h>

void selection_sort(int nums[], int n)
{
    for (int i = 0; i < n; i++)
    {
        int min = i;
        for (int j = i + 1; j < n; j++)
        {
            if (nums[j] < nums[min])
                min = j;
        }
        // swap i, min
        int temp = nums[min];
        nums[min] = nums[i];
        nums[i] = temp;
    }
}

void bubble_sort(int nums[], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (nums[j] > nums[j + 1])
            {
                int temp = nums[j + 1];
                nums[j + 1] = nums[j];
                nums[j] = temp;
            }
        }
    }
}

void mergesort(int nums[], int n)
{
    if (n > 1)
    {
        int p = n / 2;
        int q = n - p;
        int *B = (int *)malloc(p * sizeof(int));
        int *C = (int *)malloc(q * sizeof(int));

        int i;
        for (i = 0; i < p; i++)
            B[i] = nums[i];
        for (i = p; i < n; i++)
            C[i - p] = nums[i];
        mergesort(B, p);
        mergesort(C, q);
        // merge B and C to nums
        int a = 0;
        int l = 0, r = 0;
        while (l < p && r < q)
        {
            if (B[l] < C[r])
                nums[a++] = B[l++];
            else
                nums[a++] = C[r++];
        }
        if (l == p)
        {
            // copy C
            for (r; r < q; r++)
                nums[a++] = C[r];
        }
        else
            // copy B
            for (l; l < p; l++)
                nums[a++] = B[l];

        free(B);
        free(C);
    }
}

int partition(int A[], int n)
{
    int p = A[n - 1];
    int l = -1;
    int i;
    for (i = 0; i < n; i++)
    {
        if (A[i] <= p)
        {
            l++;
            // swal l and i
            int temp = A[l];
            A[l] = A[i];
            A[i] = temp;
        }
    }
    return l;
}

void quicksort(int A[], int n)
{
    if (n <= 1)
        return;
    int p = partition(A, n);
    quicksort(A, p);
    quicksort(A + p + 1, n - p - 1);
}

void print(int nums[], int n)
{
    printf("[");
    for (int i = 0; i < 10; i++)
    {
        printf("%d", nums[i]);
        if (i != 9)
            printf(", ");
    }
    printf("]\n");
}

int main()
{
    int A[] = {4, 2, 10, 6, 3, 8, 9, 1, 7, 5};
    print(A, 10);
    selection_sort(A, 10);
    print(A, 10);

    int B[] = {4, 2, 10, 6, 3, 8, 9, 1, 7, 5};
    print(B, 10);
    bubble_sort(B, 10);
    print(B, 10);

    int C[] = {4, 2, 10, 6, 3, 8, 9, 1, 7, 5};
    print(C, 10);
    mergesort(C, 10);
    print(C, 10);

    int D[] = {4, 2, 10, 6, 3, 8, 9, 1, 7, 5};
    print(D, 10);
    quicksort(D, 10);
    print(D, 10);
}