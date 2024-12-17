#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define N 6

void inputMatrix(double mat[N][N], int *rows, int *cols);
void printMatrix(double mat[N][N], int rows, int cols);
void addMatrices(double A[N][N], double B[N][N], double result[N][N], int rows, int cols);
void subtractMatrices(double A[N][N], double B[N][N], double result[N][N], int rows, int cols);
void multiplyMatrices(double A[N][N], int r1, int c1, double B[N][N], int r2, int c2, double result[N][N]);
int inverseMatrix(double mat[N][N], double inverse[N][N], int n);
void gaussianElimination(double mat[N][N], int rows, int cols);

int main() {
    double A[N][N], B[N][N], result[N][N];
    int rowsA, colsA, rowsB, colsB, choice;

    while (1) {
        printf("\nChoose operation:\n");
        printf("1. +\n");
        printf("2. -\n");
        printf("3. *\n");
        printf("4. A^(-1)\n");
        printf("5. stairs\n");
        printf("6. exit\n");
        printf("Choose: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Input first matrix:\n");
                inputMatrix(A, &rowsA, &colsA);
                printf("Input second matrix:\n");
                inputMatrix(B, &rowsB, &colsB);
                if (rowsA != rowsB || colsA != colsB) {
                    printf("SIZE Error!\n");
                } else {
                    addMatrices(A, B, result, rowsA, colsA);
                    printf("Result + :\n");
                    printMatrix(result, rowsA, colsA);
                }
                break;

            case 2:
                printf("Input first matrix:\n");
                inputMatrix(A, &rowsA, &colsA);
                printf("Input second matrix:\n");
                inputMatrix(B, &rowsB, &colsB);
                if (rowsA != rowsB || colsA != colsB) {
                    printf("Error: Matrices sizes must match!\n");
                } else {
                    subtractMatrices(A, B, result, rowsA, colsA);
                    printf("Result of subtraction:\n");
                    printMatrix(result, rowsA, colsA);
                }
                break;

            case 3:
                printf("Input first matrix:\n");
                inputMatrix(A, &rowsA, &colsA);
                printf("Input second matrix:\n");
                inputMatrix(B, &rowsB, &colsB);
                if (colsA != rowsB) {
                    printf("Error: Number of columns in the first matrix must equal the number of rows in the second!\n");
                } else {
                    multiplyMatrices(A, rowsA, colsA, B, rowsB, colsB, result);
                    printf("Result of multiplication:\n");
                    printMatrix(result, rowsA, colsB);
                }
                break;

            case 4:
                printf("Input square matrix:\n");
                inputMatrix(A, &rowsA, &colsA);
                if (rowsA != colsA) {
                    printf("Error: The matrix must be square!\n");
                } else if (inverseMatrix(A, result, rowsA)) {
                    printf("Inverse matrix:\n");
                    printMatrix(result, rowsA, rowsA);
                } else {
                    printf("The matrix is singular, inverse does not exist.\n");
                }
                break;

            case 5:
                printf("Input matrix:\n");
                inputMatrix(A, &rowsA, &colsA);
                gaussianElimination(A, rowsA, colsA);
                printf("Matrix after Gaussian elimination:\n");
                printMatrix(A, rowsA, colsA);
                break;

            case 6:
                exit(0);

            default:
                printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}

void inputMatrix(double mat[N][N], int *rows, int *cols) {
    printf("Enter the number of rows and columns: ");
    scanf("%d %d", rows, cols);
    if (*rows > 6 || *cols > 6)
    {
        printf("TOO MANY COLS OR ROWS");
        exit(1);
    }
    
    printf("Enter the matrix elements:\n");
    for (int i = 0; i < *rows; i++)
        for (int j = 0; j < *cols; j++)
            scanf("%lf", &mat[i][j]);
}

void printMatrix(double mat[N][N], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%8.3lf ", mat[i][j]);
        }
        printf("\n");
    }
}

void addMatrices(double A[N][N], double B[N][N], double result[N][N], int rows, int cols) {
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            result[i][j] = A[i][j] + B[i][j];
}

void subtractMatrices(double A[N][N], double B[N][N], double result[N][N], int rows, int cols) {
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            result[i][j] = A[i][j] - B[i][j];
}

void multiplyMatrices(double A[N][N], int r1, int c1, double B[N][N], int r2, int c2, double result[N][N]) {
    for (int i = 0; i < r1; i++)
        for (int j = 0; j < c2; j++) {
            result[i][j] = 0;
            for (int k = 0; k < c1; k++)
                result[i][j] += A[i][k] * B[k][j];
        }
}

void gaussianElimination(double mat[N][N], int rows, int cols) {
    for (int k = 0; k < rows; k++) {
        int maxRow = k;
        for (int i = k + 1; i < rows; i++) {
            if (fabs(mat[i][k]) > fabs(mat[maxRow][k])) {
                maxRow = i;
            }
        }

        for (int j = 0; j < cols; j++) {
            double temp = mat[k][j];
            mat[k][j] = mat[maxRow][j];
            mat[maxRow][j] = temp;
        }

        if (fabs(mat[k][k]) < 1e-9) {
            printf("Matrix is singular or nearly singular.\n");
            return;
        }

        double pivot = mat[k][k];
        for (int j = k; j < cols; j++) {
            mat[k][j] /= pivot;
        }

        for (int i = k + 1; i < rows; i++) {
            double factor = mat[i][k];
            for (int j = k; j < cols; j++) {
                mat[i][j] -= factor * mat[k][j];
            }
        }
    }
}

int inverseMatrix(double mat[N][N], double inverse[N][N], int n) {
    double aug[N][2 * N];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            aug[i][j] = mat[i][j];
            aug[i][j + n] = (i == j) ? 1 : 0;
        }
    }

    for (int k = 0; k < n; k++) {
        double diag = aug[k][k];
        if (diag == 0) 
        return 0;

        for (int j = 0; j < 2 * n; j++)
            aug[k][j] /= diag;

        for (int i = 0; i < n; i++) {
            if (i != k) {
                double factor = aug[i][k];
                for (int j = 0; j < 2 * n; j++)
                    aug[i][j] -= factor * aug[k][j];
            }
        }
    }

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            inverse[i][j] = aug[i][j + n];

    return 1;
}
