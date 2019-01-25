// Matrix rank
#include "stdafx.h"
#include <iostream>

using namespace std;

void toZeros(int, int, double **);

int main()
{
	int rows, cols, rank = 0, t = 0;
	bool getOut = false;

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
	cout << endl;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cout << a[i][j] << " ";
		}
		cout << endl;
	}

	toZeros(rows, cols, a);

	//вывод
	cout << "Transofrmed matrix: " << endl << endl;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cout << a[i][j] << " ";
		}
		cout << endl;
	}

	for (int i = rows - 1; i >= 0; i--)
	{
		for (int j = cols - 1; j >= 0; j--)
		{
			if (a[i][j] == 0)
			{
				t++;
			}

			else
			{
				t = 0;
				getOut = true;
				break;
			}
		}
		
		if (t == cols)
		{
			rank++;
			t = 0;
		}

		if (getOut == true)
		{
			break;
		}
	}

	cout << endl << "Matrix rank: " << rows - rank << endl;

	//удаление
	for (int i = 0; i < rows; i++)
	{
		delete[] a[i];
	}
	delete[] a;

    return 0;
}


void toZeros(int rows, int cols, double **a) {

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

	rows--;
	cols--;

	if (rows > 1 && cols > 1)
	{
		double **b = new double*[rows];
		for (int i = 0; i < rows; i++)
		{
			b[i] = new double[cols];
		}

		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				b[i][j] = a[i + 1][j + 1];
			}
		}

		toZeros(rows, cols, b);

		cout << endl;
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				a[i + 1][j + 1] = b[i][j];
			}
		}

		for (int i = 0; i < rows; i++)
		{
			delete b[i];
		}
		delete[] b;
	}

	return;
}