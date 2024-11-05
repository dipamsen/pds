#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	char roll[9];
	char name[37];
	float cgpa;
} Student;

// inputs string having spaces
void input_str(char *s) {
	int len = 0;
	while (1) {
		char c = getchar();
		if (c == '\n') { // to prevent capturing trailing whitespace
			if (len == 0) continue;
			return;
		}
		s[len++] = c;
	}
}

// partitioning for quicksort
int partition(Student *arr, int n) {
	int p = n - 1; // pivot
	int left = -1;
	
	for (int i = 0; i < n; i++) {
		if (strcmp(arr[i].roll, arr[p].roll) <= 0) { // arr[i] <= arr[p]
			left++;
			if (i != left) {
				// swap arr[i] and arr[left] 
				Student temp = arr[left];
				arr[left] = arr[i];
				arr[i] = temp;
			}
		}
	}
	
	return left; // pivot position after partitioning (LpR)
}


// QuickSort implementation
void sort(Student *arr, int n) {
	if (n <= 1) return;
	int pivot = partition(arr, n);
	
	sort(arr, pivot);
	sort(arr + pivot + 1, n - pivot - 1);
}

// prints list of students in tabular format
void print(Student *arr, int n) {
	printf("\n| Roll No  | Student Name                           | CGPA   |\n");
	printf("|----------|----------------------------------------|--------|\n");
	for (int i = 0; i < n; i++) {
		printf("| %-8s | %-38s | %-6.1f |\n", arr[i].roll, arr[i].name, arr[i].cgpa);
	}
	printf("\n");
}

int main() {
	int n;
	printf("Enter number of students: ");
	scanf("%d", &n);
	
	Student *students = (Student *) malloc(n * sizeof(Student));
	
	for (int i = 0; i < n; i++) {
		printf("\nStudent %d:\n", i+1);
		printf("\tRoll Number: ");
		scanf("%s", students[i].roll);
		printf("\tName: ");
		input_str(students[i].name);
		printf("\tCGPA: ");
		scanf("%f", &students[i].cgpa);
	}
	
	sort(students, n);
	
	printf("\nSorted students list (by roll no.): \n");
	
	print(students, n);
	
	free(students);
	
	return 0;
}
