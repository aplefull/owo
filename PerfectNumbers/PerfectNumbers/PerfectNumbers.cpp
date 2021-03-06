#include "stdafx.h"
#include <iostream>
#include <cmath>

using namespace std;

bool primeCheck(int num) {

	for (int i = 2; i < num; i++){

		if (num % i == 0){
			return false;
		}
	}

	return true;
}

void perfect1(double lim) {

	double sum = 0;

	for (int i = 1; i <= lim; i++) {

		for (int k = 1; k < i; k++) {
			if (i % k == 0) {
				sum += k;
			}
		}

		if (sum == i) {
			cout << i << endl;
		}

		if (i % 10000 == 0) {
			cout << "milestone: " << i << endl;
		}

		sum = 0;
	}

	return;
}

void perfect2(double lim) {

	for (int i = 2; (pow(2, i) - 1) * pow(2, i - 1) <= lim; i++){

		if (primeCheck(pow(2, i) - 1)){

			cout << (pow(2, i) - 1) * pow(2, i - 1) << endl;

		}

	}

	return;
}

int main()
{
	double lim;

	cout << "Limit: ";
	cin >> lim;

	perfect2(lim);

    return 0;
}

