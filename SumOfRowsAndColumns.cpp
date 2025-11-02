#include <stdio.h>

int main() {
    int matrix[10][10];
    int row, col, i, j;
    int rowSum, colSum;

    printf("Enter number of rows: ");
    scanf("%d", &row);
    printf("Enter number of columns: ");
    scanf("%d", &col);

    printf("Enter elements of the matrix:\n");
    for (i = 0; i < row; i++) {
        for (j = 0; j < col; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
    printf("\nMatrix:\n");
    for (i = 0; i < row; i++) {
        for (j = 0; j < col; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\nSum of each row:\n");
    for (i = 0; i < row; i++) {
        rowSum = 0;
        for (j = 0; j < col; j++) {
            rowSum += matrix[i][j];
        }
        printf("Sum of Row %d = %d\n", i + 1, rowSum);
    }
    printf("\nSum of each column:\n");
    for (j = 0; j < col; j++) {
        colSum = 0;
        for (i = 0; i < row; i++) {
            colSum += matrix[i][j];
        }
        printf("Sum of Column %d = %d\n", j + 1, colSum);
    }
}

