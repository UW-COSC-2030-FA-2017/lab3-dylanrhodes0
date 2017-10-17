// #############
// Dylan Rhodes
// COSC 2030
// lab03-drhodes3.cpp
// #############

#include <iostream>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::getline;

// short int sum : 255 is last number that computes correctly.
	// Meaning an n of 256 will cause an overflow. 
	// Shown by the negative numbers that come up.

// long int sum: 65535 is last number that computes correctly.
	// Meaning an n of 65536 will cause an overflow.
	// Shown by the negative numbers that come up.

// float factorial: 34 is last number that computes correctly.
	// Meaning an n of 35 will cause overflow.
	// Shown but a result of "inf". 

// double factorial: 170 is last number that computes correctly.
	// Meaning an n of 171 will cause overflow.
	// Shown but a result of "inf". 

// puzzle with float: 
	// Float puzzle : 
	// i = : 3.4
	// i = : 3.6
	// i = : 3.8
	// i = : 4
	// i = : 4.2
	// i = : 4.4 ##### This line is extra/not present in the double computation.

// puzzle with double:
	// Double puzzle : 
	// i = : 3.4
	// i = : 3.6
	// i = : 3.8
	// i = : 4
	// i = : 4.2

template <typename T>
void sumfunc(T n, T sum) {
	do {
		cout << "255 is last correctly computed number for short" << endl;
		cout << "65535 is last correctly computed number for long" << endl;
		cout << "Please enter a number for n: ";
		cin >> n;
	} while (n <= 0);

	for (int i = 0; i <= n; i++) {
		sum += i;
	}

	//cout << "Performed " << n << " times..." << endl;
	cout << "Sum is: " << sum << endl << endl;
}

template <typename T>
void factorialfunc(long int n, T product) {
	do {
		cout << "34 is last correctly computed number for float" << endl;
		cout << "170 is last correctly computed number for double" << endl;
		cout << "Please enter a number for n: ";
		cin >> n;
	} while (n <= 0);

	for (int i = 1; i <= n; i++) {
		product *= i;
	}

	//cout << "Performed " << n << " times..." << endl;
	cout << "Factorial is: " << product << endl << endl;
}

template <typename T>
T strangesumfunc(int n, T sum) {
	T temp = 0.0;
	for (double i = 1; i <= n; i++) {
		temp = 1 / i;
		sum += temp;
	}

	return sum - 1.0;
}

template <typename T>
void puzzlefunc(T t) {
	for (T i = 3.4; i < 4.4; i += 0.2) {
		cout << "i = : " << i << endl;
	}
}

int main() {
	do {
		cin.clear();
		fflush(stdin);

		string type;
		cout << "s for short int sum, l for long int sum" << endl;
		cout << "f for float factorial, d for double factorial" << endl;
		cout << "w for strange (weird) sum, p for puzzle func" << endl;
		cout << "Please enter a type (e for exit): ";
		do {
			getline(cin, type);
		} while (type == "");
		cout << endl;

		if (type == "s" || type == "short") {
			short int n = 0;
			short int sum = 0;
			sumfunc(n, sum);
		} else if (type == "l" || type == "long") {
			long int n = 0;
			long int sum = 0;
			sumfunc(n, sum);
		} else if (type == "f" || type == "float") {
			long int n = 0;
			float product = 1.0;
			factorialfunc(n, product);
		} else if (type == "d" || type == "double") {
			long int n = 0;
			double product = 1.0;
			factorialfunc(n, product);
		}
		else if (type == "w" || type == "weird") {
			int n = 0;

			do {
				cout << "Please enter a number for n: ";
				cin >> n;
			} while (n <= 0);

			float sum1 = 0.0;
			cout << "Float sum : " << strangesumfunc(n, sum1) << endl;

			double sum2 = 0.0;
			cout << "Double sum: " << strangesumfunc(n, sum2) << endl;
		} else if (type == "p" || type == "puzzle") {
			float tempfloat = 0.0;
			cout << "Float puzzle : " << endl;
			puzzlefunc(tempfloat);
			cout << endl;

			double tempdouble = 0.0;
			cout << "Double puzzle: " << endl;
			puzzlefunc(tempdouble);
			cout << endl;
		} else if (type == "e" || type == "exit") {
			exit(0);
		}
	} while (true);

	return 0;
}