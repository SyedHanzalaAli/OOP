// You need to make a program that works like a Matrix Wizard. First, it will ask the user for
// the size of a 2D matrix and then create it using memory magic (dynamic allocation). Next,
// the program will fill the matrix with numbers given by the user. After that, it will show off
// by doing matrix addition, subtraction, and multiplication (only if the sizes match). Finally,
// it will display the results and clean up the memory like a good, tidy wizard.

#include <iostream>
using namespace std;

int **createMatrix(int rows, int cols)
{
    int **matrix = new int *[rows];
    for (int i = 0; i < rows; i++)
    {
        matrix[i] = new int[cols];
    }
    return matrix;
}

void inputMatrix(int **matrix, int rows, int cols)
{
    cout << "enter matrix elements : " << endl;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cin >> matrix[i][j];
        }
    }
}

void displayMatrix(int** matrix, int rows, int cols) {
    cout << "Matrix:" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int **addMatrices(int **A, int **B, int rows, int cols)
{
    int **result = createMatrix(rows, cols);
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            result[i][j] = A[i][j] + B[i][j];
        }
    }
    return result;
}

int** subractMatrices(int **A, int **B, int rows, int cols)
{
    int **result = createMatrix(rows, cols);
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            result[i][j] = A[i][j] - B[i][j];
        }
    }
    return result;
}

int **multiplyMatrices(int **A, int **B, int rowsA, int colsA, int colsB)
{
    int **result = createMatrix(rowsA, colsB);
    for (int i = 0; i < rowsA; i++)
    {
        for (int j = 0; j < colsB; j++)
        {
            result[i][j] = 0;
            for (int k = 0; k < colsA; k++)
            {
                result[i][j] += A[i][j] * B[i][j];
            }
        }
    }
    return result;
}

void deleteMatrix(int** matrix , int rows){
    for(int i =0 ; i < rows ; i++){
        delete[] matrix[i];
    }
    delete[] matrix;
}

int main() {
    int rowsA, colsA, rowsB, colsB;
    cout << "Enter the number of rows and columns for Matrix A: ";
    cin >> rowsA >> colsA;
    int** matrixA = createMatrix(rowsA, colsA);
    inputMatrix(matrixA, rowsA, colsA);
    
    cout << "Enter the number of rows and columns for Matrix B: ";
    cin >> rowsB >> colsB;
    int** matrixB = createMatrix(rowsB, colsB);
    inputMatrix(matrixB, rowsB, colsB);
    
    cout << "\nMatrix A:" << endl;
    displayMatrix(matrixA, rowsA, colsA);
    
    cout << "\nMatrix B:" << endl;
    displayMatrix(matrixB, rowsB, colsB);
    
    if (rowsA == rowsB && colsA == colsB) {
        int** sumMatrix = addMatrices(matrixA, matrixB, rowsA, colsA);
        cout << "\nMatrix A + Matrix B:" << endl;
        displayMatrix(sumMatrix, rowsA, colsA);
        deleteMatrix(sumMatrix, rowsA);
        
        int** diffMatrix = subractMatrices(matrixA, matrixB, rowsA, colsA);
        cout << "\nMatrix A - Matrix B:" << endl;
        displayMatrix(diffMatrix, rowsA, colsA);
        deleteMatrix(diffMatrix, rowsA);
    } else {
        cout << "\nAddition and subtraction not possible as matrix sizes do not match." << endl;
    }
    
    if (colsA == rowsB) {
        int** prodMatrix = multiplyMatrices(matrixA, matrixB, rowsA, colsA, colsB);
        cout << "\nMatrix A * Matrix B:" << endl;
        displayMatrix(prodMatrix, rowsA, colsB);
        deleteMatrix(prodMatrix, rowsA);
    } else {
        cout << "\nMultiplication not possible as column count of A does not match row count of B." << endl;
    }
    
    deleteMatrix(matrixA, rowsA);
    deleteMatrix(matrixB, rowsB);
    
    return 0;
}
