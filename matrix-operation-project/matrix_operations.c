#include <stdio.h>

#define MAX 10 // Maximum size for the 2D arrays to easily pass them to functions

// --- Function Prototypes ---
void inputMatrix(int mat[MAX][MAX], int r, int c, char name);
void printMatrix(int mat[MAX][MAX], int r, int c);
void addMatrices(int m1[MAX][MAX], int m2[MAX][MAX], int res[MAX][MAX], int r, int c);
void multiplyMatrices(int m1[MAX][MAX], int m2[MAX][MAX], int res[MAX][MAX], int r1, int c1, int r2, int c2);
void transposeMatrix(int mat[MAX][MAX], int res[MAX][MAX], int r, int c);

int main() {
    int choice;
    int mat1[MAX][MAX], mat2[MAX][MAX], result[MAX][MAX];
    int r1, c1, r2, c2;

    printf("--- Matrix Operations Menu ---\n");
    printf("1. Matrix Addition\n");
    printf("2. Matrix Multiplication\n");
    printf("3. Transpose of a Matrix\n");
    printf("Enter your choice (1-3): ");
    scanf("%d", &choice);

    switch (choice) {
        case 1: // Addition
            printf("\nEnter rows and columns for the matrices (e.g., 2 2): ");
            scanf("%d %d", &r1, &c1);
            inputMatrix(mat1, r1, c1, 'A');
            inputMatrix(mat2, r1, c1, 'B');
            
            addMatrices(mat1, mat2, result, r1, c1);
            
            printf("\nResult of Matrix Addition:\n");
            printMatrix(result, r1, c1);
            break;

        case 2: // Multiplication
            printf("\nEnter rows and columns for Matrix A: ");
            scanf("%d %d", &r1, &c1);
            printf("Enter rows and columns for Matrix B: ");
            scanf("%d %d", &r2, &c2);
            
            // Mathematical rule for matrix multiplication
            if (c1 != r2) {
                printf("\nError: Multiplication not possible. Columns of A (%d) must equal Rows of B (%d).\n", c1, r2);
            } else {
                inputMatrix(mat1, r1, c1, 'A');
                inputMatrix(mat2, r2, c2, 'B');
                
                multiplyMatrices(mat1, mat2, result, r1, c1, r2, c2);
                
                printf("\nResult of Matrix Multiplication:\n");
                printMatrix(result, r1, c2);
            }
            break;

        case 3: // Transpose
            printf("\nEnter rows and columns for the Matrix: ");
            scanf("%d %d", &r1, &c1);
            inputMatrix(mat1, r1, c1, 'A');
            
            transposeMatrix(mat1, result, r1, c1);
            
            printf("\nTransposed Matrix:\n");
            // Note: For printing the transposed result, rows and columns are swapped (c1, r1)
            printMatrix(result, c1, r1); 
            break;

        default:
            printf("\nInvalid choice. Please run the program again.\n");
            break;
    }

    return 0;
}

// --- Function Definitions ---

void inputMatrix(int mat[MAX][MAX], int r, int c, char name) {
    printf("\nEnter elements of Matrix %c (%d x %d):\n", name, r, c);
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            printf("Element [%d][%d]: ", i, j);
            scanf("%d", &mat[i][j]);
        }
    }
}

void printMatrix(int mat[MAX][MAX], int r, int c) {
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            printf("%d\t", mat[i][j]);
        }
        printf("\n"); // Newline after each row
    }
}

void addMatrices(int m1[MAX][MAX], int m2[MAX][MAX], int res[MAX][MAX], int r, int c) {
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            res[i][j] = m1[i][j] + m2[i][j];
        }
    }
}

void multiplyMatrices(int m1[MAX][MAX], int m2[MAX][MAX], int res[MAX][MAX], int r1, int c1, int r2, int c2) {
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            res[i][j] = 0; // Initialize element to 0 before accumulating
            for (int k = 0; k < c1; k++) {
                res[i][j] += m1[i][k] * m2[k][j];
            }
        }
    }
}

void transposeMatrix(int mat[MAX][MAX], int res[MAX][MAX], int r, int c) {
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            res[j][i] = mat[i][j]; // Swap rows and columns
        }
    }
}