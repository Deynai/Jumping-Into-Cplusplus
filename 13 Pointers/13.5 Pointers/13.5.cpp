#include <iostream>

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