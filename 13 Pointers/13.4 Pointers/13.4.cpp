#include <iostream>

/* 
4. Write a function that takes two input arguments and provides two separate results to the caller, one
that is the result of multiplying the two arguments, the other the result of adding them. Since you can
directly return only one value from a function, you'll need the second value to be returned through a
pointer or reference parameter.
*/

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