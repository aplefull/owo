// a0 = 0, a_n = a_n-1 - n if a_n-1 - n > 0 and not already in the sequence, else a_n = a_n-1 + n

#include "stdafx.h"
#include <iostream>

using namespace std;

int recoman(int n, int *arr) {

	if (n == 0)
	{
		arr[n] = 0;
		return 0;
	}

	int a = arr[n - 1] - n;

	if (a > 0)
	{
		bool ret = true;
		for (int i = 0; i <= n - 1; i++)
		{
			if (arr[i] == a) {
				ret = false;
				break;
			}
		}

		if (ret)
		{
			arr[n] = a;
			return a;
		}

	}

	arr[n] = a + 2 * n;
	return a + 2 * n;

}

//max depth ~4000
int recoman_rec(int n, int *arr) {

	if (n == 0)
	{
		arr[n] = 0;
		return 0;
	}

	int a = recoman_rec(n - 1, arr) - n;

	if (a > 0)
	{
		bool ret = true;
		for (int i = 0; i <= n - 1; i++)
		{
			if (arr[i] == a) {
				ret = false;
				break;
			}
		}

		if (ret)
		{
			arr[n] = a;
			return a;
		}

	}

	arr[n] = a + 2 * n;
	return a + 2 * n;

}

int main()
{
	int n;
	cout << "1 - range. \n2 - exact value. \n";
	cin >> n;
	int *a;

	switch (n)
	{
	case 1:
		cout << "n: ";
		cin >> n;
		a = new int[n - 1];
		for (int i = 0; i < n; i++)
		{
			cout << recoman(i, a) << " ";
		}
		cout << endl;
		break;

	case 2:
		cout << "n: ";
		cin >> n;
		a = new int[n - 1];
		cout << recoman_rec(n - 1, a) << endl;
		break;
	}

    return 0;
}

