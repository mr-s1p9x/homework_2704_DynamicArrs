#include <iostream>
using namespace std;

// Функция для создания двумерного массива
int** createMatrix(int rows, int cols)
{
	int** matrix = new int* [rows]; // выделяем память под массив указателей
	for (int i = 0; i < rows; i++)
	{
		matrix[i] = new int[cols]; // выделяем память под каждый столбец
	}
	return matrix;
}

// Функция для удаления двумерного массива
void deleteMatrix(int** matrix, int rows)
{
	for (int i = 0; i < rows; i++)
	{
		delete[] matrix[i]; // удаляем каждый столбец
	}
	delete[] matrix; // удаляем массив указателей
}

// Функция для добавления столбца в двухмерный массив
// matrix - ссылка на двухмерный массив, cols - на кол-во столбцов
// rows - кол-во строк, colIndex - позиция, куда добавляется новый столбец
void addColumn(int**& matrix, int& cols, int rows, int colIndex)
{
	int** newMatrix = createMatrix(rows, cols + 1); // создаем новую матрицу с доп столбцом

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0, newCol = 0; j < cols + 1; j++)
		{
			if (j == colIndex)
			{
				newMatrix[i][j] = 0; // Инициализируем столбец нулями
			}
			else
			{
				newMatrix[i][j] = matrix[i][newCol++]; // копируем старые значения
			}
		}
	}

	deleteMatrix(matrix, rows); // удаляем старую матрицу
	matrix = newMatrix; // Назначаем новую матрицу
	cols++; // Увеличиваем кол-во столбцов
}

void removeColumn(int**& matrix, int& cols, int rows, int colIndex1)
{
	if (colIndex1 < 0 || colIndex1 >= cols) return; // Проверка корректности индекса

	int** newMatrix = createMatrix(rows, cols - 1); // Создаем новую матрицу с меньшим кол-вом столбцов

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0, newCol = 0; j < cols; j++)
		{
			if (j != colIndex1)
			{
				newMatrix[i][newCol++] = matrix[i][j]; // копируем значения, исключая удаляемый столбец
			}
		}
	}

	deleteMatrix(matrix, rows);
	matrix = newMatrix;
	cols--; // Уменьшаем кол-во столбцов
}

// Функция вывода матрицы
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
	int rows = 3, cols = 3;
	int** matrix = createMatrix(rows, cols);

	// Заполнение матрицы примерными данными
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			matrix[i][j] = i + j;
		}
	}

	cout << "Original matrix:" << endl;
	printMatrix(matrix, rows, cols);

	// Добавление столбца
	int colIndex = 1; // добавляем столбец на вторую позицию
	int colIndex1 = 3; // удаляем столбец на третьей позиции

	addColumn(matrix, cols, rows, colIndex);

	cout << "Matrix after adding a column at index " << colIndex << ":" << endl;
	printMatrix(matrix, rows, cols);

	cout << endl; 

	removeColumn(matrix, cols, rows, colIndex1);
	cout << "Matrix after deleting a column at index " << colIndex1 << ":" << endl;
	printMatrix(matrix, rows, cols);

	// Освобождение памяти
	deleteMatrix(matrix, rows);

	return 0;
}