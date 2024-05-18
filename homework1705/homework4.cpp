#include <iostream>
using namespace std;

// Фукнция вывода матрицы 
void printMatrix(int** matrix, int M, int N)
{
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
}

// Функция циклического сдвига строк в матрице
void shiftRows(int** matrix, int M, int N, int shift, bool toRight)
{
	while (shift--) // повторить сдвиг указанное кол-во раз
	{
		if (toRight)
		{
			for (int i = 0; i < M; i++)
			{
				int temp = matrix[i][N - 1]; // сохранить последний элемент строки
				for (int j = N - 1; j > 0; j--)
				{
					matrix[i][j] = matrix[i][j - 1]; // Сдвиг элементов строки вправо
				}
				matrix[i][0] = temp; // Переместить последний элемент в начало строки
			}
		}
		else
		{
			for (int i = 0; i < N; i++)
			{
				int temp = matrix[i][0]; // Сохранить первый элемент строки
				for (int j = 0; j < N - 1; j++)
				{
					matrix[i][j] = matrix[i][j + 1]; // Сдвиг элементов строки влево
				}
				matrix[i][N - 1] = temp; // Переместить первый элемент в конец строки
			}
		}
	}
}

// Функция циклического сдвига столбцов в матрице
void shiftColumns(int** matrix, int M, int N, int shift, bool toDown)
{
	while (shift--) // повторить сдвиг указанное кол-во раз
	{
		if (toDown)
		{
			for (int j = 0; j < N; j++)
			{
				int temp = matrix[M - 1][j]; // Сохранить последний элемент столбца
				for (int i = M - 1; i > 0; i--)
				{
					matrix[i][j] = matrix[i - 1][j]; // Сдвиг элементов столбца вниз
				}
				matrix[0][j] = temp; // Переместить последний элемент в начало столбца
			}
		}
		else 
		{
			for (int j = 0; j < N; j++)
			{
				int temp = matrix[0][j]; // сохранить первый элемент столбца
				for (int i = 0; i < M - 1; i++)
				{
					matrix[i][j] = matrix[i + 1][j]; // Сдвиг элементов столбца вверх
				}
				matrix[M - 1][j] = temp;
			}
		}
	}
}

int main()
{
	int M, N, shift;
	bool toRight, toDown;

	cout << "Enter number of rows (M): ";
	cin >> M;
	cout << "Enter number of columns (N): ";
	cin >> N;

	int** matrix = new int* [M]; // Выделение памяти для матрицы
	for (int i = 0; i < M; i++)
	{
		matrix[i] = new int[N];
		for (int j = 0; j < N; j++)
		{
			cout << "Enter element [" << i << "][" << j << "]: ";
			cin >> matrix[i][j];
		}
	}

	cout << "Enter number of shifts: ";
	cin >> shift;
	cout << "Shift rows to the right? (1 for yes, 0 for no): ";
	cin >> toRight;
	shiftRows(matrix, M, N, shift, toRight); // Циклический сдвиг строк

	cout << "Shift columns down? (1 for yes, 0 for no): ";
	cin >> toDown;
	shiftColumns(matrix, M, N, shift, toDown); // Циклический сдвиг столбцов

	cout << "Resulting Matrix:\n";
	printMatrix(matrix, M, N); // Вывод результата

	for (int i = 0; i < M; i++)
	{
		delete[] matrix[i];
	}
	delete[] matrix;

	return 0;
} 
