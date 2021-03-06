#include "stdafx.h"
#include <iostream>
#include <ctime>
#include <iomanip>

using namespace std;

double fib_rec(int n) {

	if (n == 1 || n == 2)
	{
		return 1;
	}

	return fib_rec(n - 1) + fib_rec(n - 2);
}

//non-recursive is fast af
double fib(int n) {

	double prev = 1, prev2 = 0, num = 1;

	for (int i = 1; i < n; i++)
	{
		num = prev + prev2;
		prev2 = prev;
		prev = num;
	}

	return num;
}

int main()
{
	int n, start, end;

	cout << "n: ";
	cin >> n;
	while (n <= 0)
	{
		cout << "Only  positives are allowed. \nn: ";
		cin >> n;
	}
	cout << fixed;
	cout.precision(0);

	start = clock();
	
	cout << fib(n) << endl;

	end = clock();

	cout << "time: " << end - start << "ms" << endl;
    return 0;
}

