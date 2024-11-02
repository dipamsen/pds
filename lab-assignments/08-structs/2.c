#include <stdio.h>
#include <stdlib.h>
#define MAX_ELEMENTS 100

typedef struct {
	int row, col;
	int val;
} MatrixElement;

typedef MatrixElement SparseMatrix[MAX_ELEMENTS];

int add(SparseMatrix *m1, int n1, SparseMatrix *m2, int n2, SparseMatrix *result) {
	// go through m1's non-zero elements
	// 	for each m1's element, check if there exists a non-zero element in m2 in that spot
	//	if so, add them
	// at the end, go through m2's elements and add the ones which haven't been added.
	
	int num_elt = 0;
	
	for (int i = 0; i < n1; i++) {
		MatrixElement elt1 = (*m1)[i];
		MatrixElement elt2;
		int found = 0;
		for (int j = 0; j < n2; j++) {
			if ((*m2)[j].row == elt1.row && (*m2)[j].col == elt1.col) {
				found = 1;
				elt2 = (*m2)[j];
				break;
			}
		}
		if (found) elt1.val += elt2.val;
		(*result)[num_elt++] = elt1;
	}
	
	for (int i = 0; i < n2; i++) {
		MatrixElement elt = (*m2)[i];
		int found = 0;
		for (int j = 0; j < num_elt; j++) {
			if ((*result)[j].row == elt.row && (*result)[j].col == elt.col) {
				found = 1;
				break;
			}
		}
		if (!found) (*result)[num_elt++] = elt; 
	}
	
	return num_elt;
}

void print(SparseMatrix m, int n, int rows, int cols) {
	for (int i = 0; i < rows; i++) {
		printf("\t");
		for (int j = 0; j < cols; j++) {
			// find if such element exists
			int found = 0,  k;
			for (k = 0; k < n; k++) if (m[k].row == i && m[k].col == j) { found = 1; break; }
			int val = found ? m[k].val : 0;
			
			printf("%d\t", val);
		}
		printf("\n");
	}
}

int main() {
	int rows, cols;
	SparseMatrix m1, m2, result;
	int n1, n2, nr;
	printf("Enter the number of rows and columns for the matrices: ");
	scanf("%d %d", &rows, &cols);
	
	// Ask the user about the number of non-zero elements in each matrix.
	printf("Enter the number of non-zero elements in First matrix: ");
	scanf("%d", &n1);
	printf("Enter the number of non-zero elements in Second matrix: ");
	scanf("%d", &n2);
	
	// Input those values in the matrix
	printf("\n");
	printf("---- Taking input for the first matrix ----\n");
	printf("Enter %d non-zero elements\n", n1);
	for (int i = 0; i < n1; i++) {
		printf("\tEnter row, column, and value: ");
		scanf("%d %d %d", &m1[i].row, &m1[i].col, &m1[i].val);
	}
	printf("\n");
	printf("---- Taking input for the second matrix ----\n");
	printf("Enter %d non-zero elements\n", n2);
	for (int i = 0; i < n2; i++) {
		printf("\tEnter row, column, and value: ");
		scanf("%d %d %d", &m2[i].row, &m2[i].col, &m2[i].val);
	}
	printf("\n");
	
	// Call the function to add m1, m2 and put it in result
	nr = add(&m1, n1, &m2, n2, &result);
	
	// Print all three matrices
	printf("Adding Matrix\n");
	print(m1, n1, rows, cols);
	printf("and\n");
	print(m2, n2, rows, cols);
	printf("results in\n");
	print(result, nr, rows, cols);
}
