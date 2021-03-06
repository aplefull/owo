// Обратная матрица
#include "stdafx.h"
#include <iostream>

using namespace std;

int det4(int **a) {
	return a[0][0] * a[1][1] - a[1][0] * a[0][1];
}

int det(int **, int);

int main()
{
	int size, d1 = 0, d2 = 0;
	double determinant;
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

	determinant = det(a, size);

	cout << endl << "determinant: " << determinant << endl;

	if (determinant == 0)
	{
		cout << "There is no ivrerse matrix." << endl;

		for (int i = 0; i < size; i++)
		{
			delete a[i];
		}
		delete[] a;

		return 0;
	}

	//матрица c для алг. дополнений
	double **c = new double*[size];
	for (int i = 0; i < size; i++)
	{
		c[i] = new double[size];
	}

	//матрица d для миноров
	int **d = new int*[size - 1];
	for (int i = 0; i < size - 1; i++)
	{
		d[i] = new int[size - 1];
	}

	//заполнение c
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			for (int k = 0; k < size; k++)
			{
				for (int n = 0; n < size; n++)
				{
					if (n != j && k != i)
					{
						d[d1][d2] = a[k][n];
						d2++;
					}
				}
				d2 = 0;
				if (k != i)
				{
					d1++;
				}
			}
			d1 = 0;

			if ((i + j) % 2 == 0)
			{
				c[j][i] = det(d, size - 1)/determinant;
			}
			else
			{
				c[j][i] = -det(d, size - 1)/determinant;
			}
		}
	}

	cout << "Inverse matrix: " << endl;

	//вывод с
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			cout << c[i][j] << " ";
		}
		cout << endl;
	}

	//удаление
	for (int i = 0; i < size; i++)
	{
		delete a[i];
	}
	delete[] a;

	for (int i = 0; i < size; i++)
	{
		delete c[i];
	}
	delete[] c;

	for (int i = 0; i < size - 1; i++)
	{
		delete d[i];
	}
	delete[] d;
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