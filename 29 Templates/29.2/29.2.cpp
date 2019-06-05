/*
2. Modify the vector replacement class implemented as a practice problem in chapter 24, but
make it a template so that it is can store any type.
*/

#include "vectorOfT.h"
#include <iostream>
#include <string>

int main()
{
	// arbitrary code to test and debug the constructors, methods, etc of VectorOfT.

	vectorOfT<double> vecA(10);

	std::cout << vecA.size();

	for (int i = 0; i < vecA.size(); i++)
	{
		vecA.set(i, i * 10);
		std::cout << "\n" << vecA.get(i);
	}

	vecA.pushfront(100);
	vecA.pushback(200);

	std::cout << "\n\n" << vecA.size();

	for (int i = 0; i < vecA.size(); i++)
	{
		std::cout << "\n" << vecA.get(i);
	}

	vectorOfT<double> vecB = vecA;
	vectorOfT<double> vecC;
	vecC = vecA;

	std::cout << "\n\n";

	for (int i = 0; i < vecB.size(); i++)
	{
		std::cout << "\n" << vecB.get(i);
	}

	std::cout << "\n\n";

	for (int i = 0; i < vecC.size(); i++)
	{
		std::cout << "\n" << vecC.get(i);
	}

	// test strings
 
	vectorOfT<std::string> vecStr(10);

	std::cout << vecStr.size();

	for (int i = 0; i < vecStr.size(); i++)
	{
		vecStr.set(i, "HELLO WORLD");
	}

	vecStr.pushback("GOODBYE WORLD");
	vecStr.pushfront("STARTING MESSAGE");
	
	std::cout << "\n\n" << vecStr.size();

	for (size_t i = 0; i < vecStr.size(); i++)
	{
		std::cout << "\n" << vecStr.get(i);
	}

	vectorOfT<std::string> vecStr2 = vecStr;
	vectorOfT<std::string> vecStr3;
	vecStr3 = vecStr2;

	std::cout << "\n\n";

	for (size_t i = 0; i < vecStr2.size(); i++)
	{
		std::cout << "\n" << vecStr2.get(i);
	}

	for (size_t i = 0; i < vecStr3.size(); i++)
	{
		std::cout << "\n" << vecStr3.get(i);
	}

	int exit;
	std::cin >> exit;
	return 0;
}