#include <iostream>
#include <fstream>
#include <sstream>

// Функция транспонирования матрицы
void transposeMatrix(int** matrix, int rows, int columns, int** transposedMatrix) {
    for (int i = 0; i < columns; i++) {
        for (int j = 0; j < rows; j++) {
            transposedMatrix[i][j] = matrix[j][i];
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
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

int main() {
	setlocale(LC_ALL, "Russian");
	
    // Открываем файл для чтения
    std::ifstream input("input.txt");
    
    if (!input) {
        std::wcout << L"Не удалось открыть файл input.txt!" << std::endl;
        return 1;
    }
    
    // Читаем размеры матрицы
    int rows, columns;
    input >> rows >> columns;
    
    // Выделяем память для матрицы
    int** matrix = new int*[rows];
    for (int i = 0; i < rows; i++) {
        matrix[i] = new int[columns];
    }
    
    // Читаем элементы матрицы из файла
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            input >> matrix[i][j];
        }
    }
    
    // Закрываем файл
    input.close();
    
    // Выделяем память для транспонированной матрицы
    int** transposedMatrix = new int*[columns];
    for (int i = 0; i < columns; i++) {
        transposedMatrix[i] = new int[rows];
    }
    
    // Транспонируем матрицу
    transposeMatrix(matrix, rows, columns, transposedMatrix);
    
	std::wcout << L"Транспонированная матрица:" << std::endl;
	
	printMatrix(transposedMatrix, columns, rows);
	
	// Открываем файл для записи
    std::ofstream output("output.txt");
    
    if (!output) {
        std::cout << "Не удалось открыть файл output.txt!" << std::endl;
        return 1;
    }
    
    // Записываем размеры транспонированной матрицы
    output << columns << " " << rows << std::endl;
    
    // Записываем элементы транспонированной матрицы в файл
    for (int i = 0; i < columns; i++) {
        for (int j = 0; j < rows; j++) {
            output << transposedMatrix[i][j] << " ";
        }
        output << std::endl;
    }
    
    // Закрываем файл
    output.close();
	
    return 0;
}