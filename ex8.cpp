#include <iostream>
#include <cmath> // Для round();

using namespace std;

double calculate_row_y(double num)
{
	if (num == 0)
		return 1 / (1 + 1 / 2.0); // 2.0, чтобы вычисления производились с учетом FloatingPoint.;
	return (1 / (num + calculate_row_y(num - 1)));
}

double calculate_row_cycle_y(double num)
{
	double result = 1 / (1 + 1 / 2.0);

	for (int i = 1; i <= num; i++) {
		result = 1 / (i + result);
	}

	return (result);
}

double get_num()
{
	double num;

	do {
		cin >> num;

		if (cin.fail()) {
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "Only integer value, please, try again: ";

			return (get_num());
		}

		if (num < 0 || num > 43307) { //При значениях больше 43307 можно поймать segfautl.
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "Too big value, please, try again: ";

			return (get_num());
		}

		if (num - round(num) != 0) {
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "Only integer value, please, try again: ";

			return (get_num());
		}
		
		return (num);
	} while(1);
}

int main()
{
	cout << "Enter your integer for `n`: ";

	double n = get_num();
	double result = calculate_row_y(n);

	cout << endl << "The result of y(n) (recursion): " << result << endl;

	result = calculate_row_cycle_y(n);

	cout << endl << "The result of y(n) (cycle): " << result << endl;

	return (0);
}
