#include <iostream>

/*
1. Write a recursive algorithm to compute the power function pow(x, y) = x^y
*/

int pow(int x, int y)
{
	if (y == 1) // base case, x^1 = x
	{
		return x;
	}
	else
	{
		return x * pow(x, y - 1); // x^y = x * x^(y-1) = x * x * x^(y-2) = .. etc
	}
}

int main()
{
	int x;
	int y;
	std::cout << "Enter x and y:";
	std::cin >> x >> y;

	std::cout << pow(x, y);

	int exitprogram;
	std::cout << "\nExiting.";
	std::cin >> exitprogram;
	return 0;
}