#include <iostream>
#include <string>

int products(int* x, int y)
{
	*x += y; // set the pointer variable to the sum of the two numbers
	return ((*x - y) * y); // return the product of the two numbers to the caller
}

int main()
{
	int x;
	int y;
	int *p_x = &x;
	
	std::cout << "Enter first number:\n";
	std::cin >> *p_x;
	std::cout << "\nEnter second number:\n";
	std::cin >> y;

	y = products(p_x, y); 

	std::cout << "\n\n" << *p_x << " and " << y; // print sum and product

	int exitprogram;
	std::cout << "\n\nExiting.";
	std::cin >> exitprogram;
	return 0;
}