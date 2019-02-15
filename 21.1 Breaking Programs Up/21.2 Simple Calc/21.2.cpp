#include <iostream>
#include "SimpleCalc.h"

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