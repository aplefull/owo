// Determinant
#include "stdafx.h"
#include <iostream>

using namespace std;

int det4(int **a) {
	return a[0][0] * a[1][1] - a[1][0] * a[0][1];
}

int det(int **, int);

int main()
{
	int size;

	cout << "Size of the matrix (>1): ";
	cin >> size;
	int **a = new int *[size];
	for (int i = 0; i < size; i++)
	{
		a[i] = new int[size];
	}

	//ввод матрицы a
	cout << "Type in all elements: ";
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			cin >> a[i][j];
		}
	}

	//вывод a
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;

	cout << det(a, size) << endl;

	//удаление
	for (int i = 0; i < size; i++)
	{
		delete a[i];
	}
	delete[] a;

	return 0;
}


//рекурсией вызывать матрицы размером n-1 ¯\_(ツ)_/¯
int det(int **a, int size) {

	int sum = 0, b1 = 0, b2 = 0;

	int **b = new int*[size - 1];
	for (int i = 0; i < size - 1; i++)
	{
		b[i] = new int[size - 1];
	}

	if (size > 2)
	{
		for (int i = 0; i < size; i++)
		{
			for (int j = 1; j < size; j++)
			{
				for (int k = 0; k < size; k++)
				{
					if (k != i)
					{
						b[b1][b2] = a[j][k];
						b2++;
					}
				}
				b2 = 0;
				b1++;
			}
			b1 = 0;

			if (i % 2 == 0)
			{
				sum += a[0][i] * det(b, size - 1);
			}
			else
			{
				sum -= a[0][i] * det(b, size - 1);
			}
		}
	}

	else {
		sum = det4(a);
	}

	for (int i = 0; i < size - 1; i++)
	{
		delete b[i];
	}
	delete[] b;

	return sum;
}
