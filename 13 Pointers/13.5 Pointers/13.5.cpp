#include <iostream>

/*
5. Write a program that compares the memory addresses of two different variables on the stack and
prints out the order of the variables by numerical order of their addresses.
*/

int main()
{
	int x;
	int y;
	
	if (&x > &y)
	{
		std::cout << "x: " << &x << "\ny: " << &y;
	}
	else
	{
		std::cout << "y: " << &y << "\nx: " << &x;
	}

	int exitprogram;
	std::cout << "\n\nExiting.\n";
	std::cin >> exitprogram;
	return 0;
}