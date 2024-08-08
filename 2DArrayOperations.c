#include <stdio.h>

void inputMatrix(int matrix[][10], int rows, int cols, const char *name){
    printf("Enter elements of matrix %s (%dx%d):\n", name, rows, cols);
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            printf("%s[%d][%d] = ", name, i, j);
            scanf("%d", &matrix[i][j]);
        }
    }
}

void printMatrix(int matrix[][10], int rows, int cols){
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++)
            printf("%d\t", matrix[i][j]);
        printf("\n");
    }
}

void addMatrices(int mat1[][10], int mat2[][10], int result[][10], int rows, int cols){
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++)
            result[i][j] = mat1[i][j] + mat2[i][j];
    }
}

void subtractMatrices(int mat1[][10], int mat2[][10], int result[][10], int rows, int cols){
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++)
            result[i][j] = mat1[i][j] - mat2[i][j];
    }
}

void multiplyMatrices(int mat1[][10], int mat2[][10], int result[][10], int rows1, int cols1, int cols2){
    for(int i = 0; i < rows1; i++){
        for(int j = 0; j < cols2; j++){
            result[i][j] = 0;
            for(int k = 0; k < cols1; k++)
                result[i][j] += mat1[i][k] * mat2[k][j];
        }
    }
}

int main() {
    int rows1, cols1, rows2, cols2;
    
    printf("Enter the number of rows and columns for matrix 1: ");
    scanf("%d %d", &rows1, &cols1);
    
    int mat1[10][10];
    inputMatrix(mat1, rows1, cols1, "Matrix 1");

    printf("Enter the number of rows and columns for matrix 2: ");
    scanf("%d %d", &rows2, &cols2);
    
    int mat2[10][10];
    inputMatrix(mat2, rows2, cols2, "Matrix 2");
    
    if(rows1 == rows2 && cols1 == cols2){
        int result[10][10];
        addMatrices(mat1, mat2, result, rows1, cols1);
        printf("Matrix Addition:\n");
        printMatrix(result, rows1, cols1);

        subtractMatrices(mat1, mat2, result, rows1, cols1);
        printf("Matrix Subtraction:\n");
        printMatrix(result, rows1, cols1);
    } 
    else
        printf("Addition and Subtraction not possible: Matrices have different dimensions.\n");

    if(cols1 == rows2){
        int result[10][10];
        multiplyMatrices(mat1, mat2, result, rows1, cols1, cols2);
        printf("Matrix Multiplication:\n");
        printMatrix(result, rows1, cols2);
    }
    else
        printf("Multiplication not possible: Number of columns in Matrix 1 is not equal to number of rows in Matrix 2.\n");
    
    return 0;
}
