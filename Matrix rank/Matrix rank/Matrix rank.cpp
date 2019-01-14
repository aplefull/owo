// Matrix rank
#include "stdafx.h"
#include <iostream>

using namespace std;

void toZeros(int, int, double **);

int main()
{
	int rows, cols;

	cout << "rows: ";
	cin >> rows;
	cout << "cols: ";
	cin >> cols;

	double **a = new double*[rows];
	for (int i = 0; i < rows; i++)
	{
		a[i] = new double[cols];
	}

	//ввод
	cout << "Type in all elements: ";
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cin >> a[i][j];
		}
	}

	//вывод
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cout << a[i][j] << " ";
		}
		cout << endl;
	}

	toZeros(rows, cols, a);

	double **b = new double*[rows - 1];
	for (int i = 0; i < rows; i++)
	{
		b[i] = new double[cols - 1];
	}

	for (int i = 0; i < rows - 1; i++)
	{
		for (int j = 0; j < cols - 1; j++)
		{
			b[i][j] = a[i + 1][j + 1];
		}
	}

	cout << endl;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cout << a[i][j] << " ";
		}
		cout << endl;
	}

	cout << endl;
	for (int i = 0; i < rows - 1; i++)
	{
		for (int j = 0; j < cols - 1; j++)
		{
			cout << b[i][j] << " ";
		}
		cout << endl;
	}

	//удаление
	for (int i = 0; i < rows; i++)
	{
		delete[] a[i];
	}
	delete[] a;

    return 0;
}

void toZeros(int cols, int rows, double **a) {

	double divisor;
	bool getOut = false;

	for (int i = 0; i < cols; i++)
	{
		for (int j = 0; j < rows; j++)
		{
			if (a[j][i] != 0)
			{
				divisor = a[j][i];
				for (int k = i; k < cols; k++)
				{
					a[j][k] = a[j][k] / divisor;
				}

				if (j != 0)
				{
					double *temp;
					temp = a[j];
					a[j] = a[0];
					a[0] = temp;
				}

				getOut = true;
				break;
			}
		}

		if (getOut == true)
		{
			getOut = false;
			break;
		}
	}

	for (int i = 1; i < rows; i++)
	{
		divisor = a[i][0];
		for (int j = 0; j < cols; j++)
		{
			a[i][j] -= a[0][j] * divisor;
		}
	}

	return;
}