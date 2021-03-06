// Matrix to the power
#include "stdafx.h"
#include <iostream>

using namespace std;

int main()
{
	int size, sum = 0, k = -1, times, temp;


	cout << "Size of the matrix: ";
	cin >> size;
	int **a = new int *[size];
	for (int i = 0; i < size; i++)
	{
		a[i] = new int[size];
	}

	int **b = new int *[size];
	for (int i = 0; i < size; i++)
	{
		b[i] = new int[size];
	}

	int **c = new int *[size];
	for (int i = 0; i < size; i++)
	{
		c[i] = new int[size];
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

	cout << "Power to raise to(>1): ";
	cin >> times;
	times--;

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

	for (int i = 0; i < size; i++)
	{
		for (int  j = 0; j < size; j++)
		{
			b[i][j] = a[i][j];
		}
	}

	for (int t = 0; t < times; t++)
	{

		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				for (int n = 0; n < size; n++)
				{
					sum += a[i][n] * b[n][k + 1];
				}
				c[i][j] = sum;
				sum = 0;
				k++;
			}
			k = -1;
		}

		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				b[i][j] = c[i][j];
			}
		}
	}

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			cout << c[i][j] << " ";
		}
		cout << endl;
	}

	for (int i = 0; i < size; i++)
	{
		delete a[i];
	}
	delete[] a;

	for (int i = 0; i < size; i++)
	{
		delete b[i];
	}
	delete[] b;

	for (int i = 0; i < size; i++)
	{
		delete c[i];
	}
	delete[] c;
	return 0;
}