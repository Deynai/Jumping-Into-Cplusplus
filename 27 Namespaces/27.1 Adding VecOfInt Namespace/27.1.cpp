/*
1. Take your implementation of a vector from the practice problem at the end of chapter 24 and
add it to a namespace.
*/

#include "vectorOfInt.h"
#include <iostream>

int main()
{
	// arbitrary code to test and debug the constructors, methods, etc of VectorOfInt.

	rowan::vectorOfInt vecA(10);

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

	rowan::vectorOfInt vecB = vecA;
	rowan::vectorOfInt vecC;
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