// Problem 1: Issues with exponents
#include <iostream>

using namespace std;

int exponent(int base, int exp)
{
	int running_value = 1;
	for (int i = 0; i < exp; i++)
	{
		running_value *= base;
	}
	//return base;
	return running_value;
}

int main()
{
	int base;
	int exp;
	cout << "Enter a base value: ";
	cin >> base;
	cout << "Enter an exponent: ";
	cin >> exp;
	//base = exponent(exp, base);
	base = exponent(base, exp);
	std::cout << "\n" << base;

	int exit;
	std::cin >> exit;
	return 0;
}