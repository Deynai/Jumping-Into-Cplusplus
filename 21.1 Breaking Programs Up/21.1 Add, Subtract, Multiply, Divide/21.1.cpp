#include "21.1.h"
#include <iostream>

int calcAdd(int &a, int &b)
{
	return a + b;
}

int calcSubtract(int &a, int &b)
{
	return a - b;
}

int calcMultiply(int &a, int&b)
{
	return a * b;
}

int calcDivide(int &a, int &b)
{
	if (b == 0)
	{
		return 0;
	}
	return a / b;
}

int main()
{
	int one, two;
	std::cout << "Enter Two Numbers: ";
	std::cin >> one >> two;

	std::cout << "\n\nAdd: " << calcAdd(one, two) << "\n";
	std::cout << "Subtract: " << calcSubtract(one, two) << "\n";
	std::cout << "Multiply: " << calcMultiply(one, two) << "\n";
	std::cout << "Divide: " << calcDivide(one, two);

	std::cin >> one;
	return 0;
}