#include <stdio.h>

#define MAX 10

void inputMatrix(int matrix[MAX][MAX], int row, int col) {
    printf("Enter elements (only 0 or 1):\n");
    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++) {
            scanf("%d", &matrix[i][j]);
            if (matrix[i][j] != 0 && matrix[i][j] != 1) {
                printf("Invalid input! Only 0 or 1 allowed.\n");
                j--; // retry this element
            }
        }
}

void printMatrix(int matrix[MAX][MAX], int row, int col) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++)
            printf("%d ", matrix[i][j]);
        printf("\n");
    }
}

void booleanAND(int A[MAX][MAX], int B[MAX][MAX], int row, int col, int result[MAX][MAX]) {
    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            result[i][j] = A[i][j] && B[i][j];
}

void booleanOR(int A[MAX][MAX], int B[MAX][MAX], int row, int col, int result[MAX][MAX]) {
    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            result[i][j] = A[i][j] || B[i][j];
}

void booleanProduct(int A[MAX][MAX], int B[MAX][MAX], int r1, int c1, int c2, int result[MAX][MAX]) {
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            result[i][j] = 0;
            for (int k = 0; k < c1; k++) {
                result[i][j] = result[i][j] || (A[i][k] && B[k][j]);
            }
        }
    }
}

int main() {
    int A[MAX][MAX], B[MAX][MAX], result[MAX][MAX];
    int r1, c1, r2, c2;

    printf("Enter rows and columns for Matrix A: ");
    scanf("%d%d", &r1, &c1);
    inputMatrix(A, r1, c1);

    printf("Enter rows and columns for Matrix B: ");
    scanf("%d%d", &r2, &c2);
    inputMatrix(B, r2, c2);

    if (r1 == r2 && c1 == c2) {
        printf("\nBoolean AND:\n");
        booleanAND(A, B, r1, c1, result);
        printMatrix(result, r1, c1);

        printf("\nBoolean OR:\n");
        booleanOR(A, B, r1, c1, result);
        printMatrix(result, r1, c1);
    } else {
        printf("\nBoolean AND/OR not possible due to size mismatch.\n");
    }

    if (c1 == r2) {
        printf("\nBoolean PRODUCT:\n");
        booleanProduct(A, B, r1, c1, c2, result);
        printMatrix(result, r1, c2);
    } else {
        printf("\nBoolean PRODUCT not possible due to size mismatch.\n");
    }

    return 0;
}
