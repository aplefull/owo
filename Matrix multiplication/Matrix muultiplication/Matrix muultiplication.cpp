// Matrix multiplication
#include "stdafx.h"
#include <iostream>

using namespace std;

int main()
{
	int rows1, cols1, rows2, cols2, rows3, cols3, sum = 0, k = -1;


	cout << "Size of the 1st matrix: ";
	cin >> rows1 >> cols1;
	int **a = new int *[rows1];
	for (int i = 0; i < rows1; i++)
	{
		a[i] = new int[cols1];
	}

	cout << "Size of the 2nd matrix: ";
	cin >> rows2 >> cols2;
	int **b = new int *[rows2];
	for (int i = 0; i < rows2; i++)
	{
		b[i] = new int[cols2];
	}
	
	if (cols1 != rows2)
	{
		cout << "Matris have incomtatible sizes";
		for (int i = 0; i < rows1; i++)
		{
			delete a[i];
		}
		for (int i = 0; i < rows2; i++)
		{
			delete b[i];
		}
		delete[] a;
		delete[] b;
		return 1;
	}

	rows3 = rows1;
	cols3 = cols2;
	int **c = new int *[rows3];
	for (int i = 0; i < rows3; i++)
	{
		c[i] = new int[cols3];
	}

	//ввод матрицы a
	cout << "Type in all elements: ";
	for (int i = 0; i < rows1; i++)
	{
		for (int j = 0; j < cols1; j++)
		{
			cin >> a[i][j];
		}
	}

	//ввод b
	cout << "Type in all elements: ";
	for (int i = 0; i < rows2; i++)
	{
		for (int j = 0; j < cols2; j++)
		{
			cin >> b[i][j];
		}
	}

	//вывод a
	for (int i = 0; i < rows1; i++)
	{
		for (int j = 0; j < cols1; j++)
		{
			cout << a[i][j] << " ";
		}
		cout << endl;
	}

	cout << endl;

	//вывод b
	for (int i = 0; i < rows2; i++)
	{
		for (int j = 0; j < cols2; j++)
		{
			cout << b[i][j] << " ";
		}
		cout << endl;
	}

	for (int i = 0; i < rows1; i++)
	{
		for (int n = 0; n < cols2; n++)
		{
			for (int j = 0; j < cols1; j++)
			{
				sum += a[i][j] * b[j][k + 1];
			}
			k++;
			c[i][k] = sum;
			sum = 0;
		}
		k = -1;
	}
	
	cout << endl;
	for (int i = 0; i < rows3; i++)
	{
		for (int j = 0; j < cols3; j++)
		{
			cout << c[i][j] << " ";
		}
		cout << endl;
	}

	for (int i = 0; i < rows1; i++)
	{
		delete a[i];
	}
	for (int i = 0; i < rows2; i++)
	{
		delete b[i];
	}
	for (int i = 0; i < rows3; i++)
	{
		delete c[i];
	}
	delete[] a;
	delete[] b;
	delete[] c;
	return 0;
}