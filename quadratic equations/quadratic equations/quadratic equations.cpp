#include "stdafx.h"
#include <iostream>
#include <string.h>

using namespace std;

int main()
{
	int len, k = 0;
	double z = 0, b = 0, c = 0, D, x1, x2;
	char a[100], t, temp[100];
	bool notSkip = true;
	cout << "Type in equation: " << endl;
	gets_s(a);

	len = strlen(a);


	//убираем пробелы
	for (int i = 0; i < len; i++)
	{
		if (a[i] == ' ')
		{
			for (int j = i; j < len; j++)
			{
				t = a[j];
				a[j] = a[j + 1];
				a[j + 1] = a[j];
			}
			i--;
		}
	}

	//ищем кооф. перед x^2
	for (int i = 0; i < len; i++)
	{
		if (a[i] == 'x' && a[i + 1] == '^')
		{
			
			if (i == 0 || a[i - 1] == '+')
			{
				z = 1;
				break;
			}

			if (a[i - 1] == '-')
			{
				z = -1;
				break;
			}

			for (int j = i; j > 0 && a[j] != '+' && a[j] != '-'; j--)
			{
				temp[k] = a[j - 1];
				k++;
			}

			temp[k] = '\0';
			_strrev(temp);
			z = atoi(temp);
			temp[k] = ' ';
			k = 0;
			break;
		}
	}

	//кооф. перед x
	for (int i = 0; i < len; i++)
	{
		if (a[i] == 'x' && a[i + 1] != '^')
		{
			
			if (i == 0 || a[i - 1] == '+')
			{
				b = 1;
				break;
			}

			if (a[i - 1] == '-')
			{
				b = -1;
				break;
			}

			for (int j = i; j > 0 && a[j] != '+' && a[j] != '-'; j--)
			{
				temp[k] = a[j - 1];
				k++;
			}

			temp[k] = '\0';
			_strrev(temp);
			b = atoi(temp);
			temp[k] = ' ';
			k = 0;
			break;
		}
	}

	_strrev(a);
	strcat_s(a, " ");
	_strrev(a);

	len = strlen(a);

	//свободный кооф.
	for (int i = len - 1; i > 0; i--)
	{
		if (( a[i + 1] == '\0' || a[i + 1] == '-' || a[i + 1] == '+') && (a[i] == '1' || a[i] == '2' || a[i] == '3' || a[i] == '4' || a[i] == '5' || a[i] == '6' || a[i] == '7' || a[i] == '8' || a[i] == '9' || a[i] == '0'))
		{
			if (i > 1 && a[i - 1] == '^')
			{
				continue;
			}


			for (int j = i; j > 0; j--)
			{

				temp[k] = a[j];
				k++;

				if (a[j] == '+' || a[j] == '-' || a[j] == ' ')
				{
					break;
				}
			}

			temp[k] = '\0';
			_strrev(temp);
			c = atoi(temp);
			temp[k] = ' ';
			k = 0;
			break;
		}
	}
	
	//cout << "a: " << z << endl << "b: " << b << endl << "c: " << c << endl;

	D = b * b - 4 * z*c;

	if (D<0)
	{
		cout << "D < 0" << endl;
	}

	else
	{
		if (D == 0)
		{
			x1 = -b / (2 * z);
			cout << "x: " << x1 << endl;
		}

		else
		{
			x1 = (-b + sqrt(D)) / (2 * z);
			x2 = (-b - sqrt(D)) / (2 * z);
			cout << "x1: " << x1 << endl << "x2: " << x2 << endl;
		}
	}

    return 0;
}