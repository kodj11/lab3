#include <iostream>

using namespace std;

// Функция для сложения матриц
void addMatrices(int** matrixA, int** matrixB, int** result, int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            result[i][j] = matrixA[i][j] + matrixB[i][j];
        }
    }
}

// Функция для умножения матриц
void multiplyMatrices(int** matrixA, int** matrixB, int** result, int rowsA, int colsA, int colsB)
{
    for (int i = 0; i < rowsA; i++)
    {
        for (int j = 0; j < colsB; j++)
        {
            result[i][j] = 0;
            for (int k = 0; k < colsA; k++)
            {
                result[i][j] += matrixA[i][k] * matrixB[k][j];
            }
        }
    }
}

// Функция для транспонирования матрицы
void transposeMatrix(int** matrix, int** result, int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            result[j][i] = matrix[i][j];
        }
    }
}

// Функция для вывода матрицы
void printMatrix(int** matrix, int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
	setlocale(LC_ALL, "Russian");
	
    int rowsA, colsA, rowsB, colsB;

    wcout << L"Введите количество строк и столбцов первой матрицы: ";
    cin >> rowsA >> colsA;

    wcout << L"Введите количество строк и столбцов второй матрицы: ";
    cin >> rowsB >> colsB;

    if (colsA != rowsB)
    {
        wcout << L"Умножение матриц невозможно!";
        return 0;
    }

    // Выделение памяти под матрицы
    int** matrixA = new int*[rowsA];
    for (int i = 0; i < rowsA; i++)
    {
        matrixA[i] = new int[colsA];
    }

    int** matrixB = new int*[rowsB];
    for (int i = 0; i < rowsB; i++)
    {
        matrixB[i] = new int[colsB];
    }

    // Ввод первой матрицы
    wcout << L"Введите элементы первой матрицы:\n";
    for (int i = 0; i < rowsA; i++)
    {
        for (int j = 0; j < colsA; j++)
        {
            cin >> matrixA[i][j];
        }
    }

    // Ввод второй матрицы
    wcout << L"Введите элементы второй матрицы:\n";
    for (int i = 0; i < rowsB; i++)
    {
        for (int j = 0; j < colsB; j++)
        {
            cin >> matrixB[i][j];
        }
    }

    // Выделение памяти под результаты операций
    int** sumMatrix = new int*[rowsA];
    for (int i = 0; i < rowsA; i++)
    {
        sumMatrix[i] = new int[colsA];
    }

    int** productMatrix = new int*[rowsA];
    for (int i = 0; i < rowsA; i++)
    {
        productMatrix[i] = new int[colsB];
    }

    int** transposeMatrixA = new int*[colsA];
    for (int i = 0; i < colsA; i++)
    {
        transposeMatrixA[i] = new int[rowsA];
    }

    int** transposeMatrixB = new int*[colsB];
    for (int i = 0; i < colsB; i++)
    {
        transposeMatrixB[i] = new int[rowsB];
    }

    // Выполнение операций
    addMatrices(matrixA, matrixB, sumMatrix, rowsA, colsA);
    multiplyMatrices(matrixA, matrixB, productMatrix, rowsA, colsA, colsB);
    transposeMatrix(matrixA, transposeMatrixA, rowsA, colsA);
    transposeMatrix(matrixB, transposeMatrixB, rowsB, colsB);

    // Вывод результатов
    wcout << L"Сумма матриц:\n";
    printMatrix(sumMatrix, rowsA, colsA);

    wcout << L"Умножение матриц:\n";
    printMatrix(productMatrix, rowsA, colsB);

    wcout << L"Транспонирование первой матрицы:\n";
    printMatrix(transposeMatrixA, colsA, rowsA);

    wcout << L"Транспонирование второй матрицы:\n";
    printMatrix(transposeMatrixB, colsB, rowsB);

    return 0;
}