#include "stdafx.h"
#include <iostream>
#include <ctime>
#include <iomanip>

using namespace std;

double fib(int n) {

	if (n < 0)
	{
		cout << "only positives are allowed" << endl;
		return -1;
	}

	if (n == 1 || n == 2)
	{
		return 1;
	}

	return fib(n - 1) + fib(n - 2);
}

int main()
{
	int n, *depth = 0, start, end;
	cout << "n: ";
	cin >> n;
	cout << fixed;

	start = clock();
	
	cout << fib(n) << endl;

	end = clock();

	cout << "time: " << end - start << "ms" << endl;
    return 0;
}

