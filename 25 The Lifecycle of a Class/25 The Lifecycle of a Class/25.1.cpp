/*
1. Implement a vector replacement that operates only on integers, vectorOfInt (you don't need to
use templates like the normal STL). Your class should have the following interface:
• A no-argument constructor that allocates a 32 element vector
• A constructor that takes an initial size as the argument
• A method get, taking an index as returning the value at that index
• A method set, that takes an index and a value, and sets the value at that index
• A method pushback that adds an element to the end of the array, resizing if necessary
• A method pushfront that adds an element to the beginning of the array
• A Copy constructor and assignment operator
Your class should not leak memory; any memory it allocates must be deleted. Try to think carefully
about how your class can be misused, and how you should handle them. What do you do if a user gives
a negative initial size? What about accessing a negative index?
*/

#include "vectorOfInt.h"
#include <iostream>

int main()
{
	// arbitrary code to test and debug the constructors, methods, etc of VectorOfInt.

	vectorOfInt vecA(10);

	std::cout << vecA.size();
	
	for (size_t i = 0; i < vecA.size(); i++)
	{
		vecA.set(i, i * 10);
		std::cout << "\n" << vecA.get(i);
	}

	vecA.pushfront(100);
	vecA.pushback(200);

	std::cout << "\n\n" << vecA.size();

	for (size_t i = 0; i < vecA.size(); i++)
	{
		std::cout << "\n" << vecA.get(i);
	}

	vectorOfInt vecB = vecA;
	vectorOfInt vecC;
	vecC = vecA;

	std::cout << "\n\n";

	for (size_t i = 0; i < vecB.size(); i++)
	{
		std::cout << "\n" << vecB.get(i);
	}

	std::cout << "\n\n";

	for (size_t i = 0; i < vecC.size(); i++)
	{
		std::cout << "\n" << vecC.get(i);
	}

	int exit;
	std::cin >> exit;
	return 0;
}