#include <iostream>

/*
3. Write a program that prints out the memory addresses of each element in a 2-dimensional
array. Check to see if the values printed out make sense to you based on the way I explained it
before.
*/

void get_dimensions(int &x, int& y)
{
	std::cout << "Enter dimensions of array:\n";
	std::cin >> x >> y;
	return;
}

int** create_array(int x, int y)
{
	int** p_p_xy = new int*[x];
	for (size_t i = 0; i < x; i++)
	{
		p_p_xy[i] = new int[y];
	}
	
	for (size_t i = 0; i < x; i++)
	{
		for (size_t j = 0; j < y; j++)
		{
			p_p_xy[i][j] = 0;
		}
	}
	return p_p_xy;
}

void print_array_addresses(int** array, int x, int y)
{
	for (size_t i = 0; i < x; i++)
	{
		std::cout << "\n";
		for (size_t j = 0; j < y; j++)
		{
			std::cout << &array[i][j] << "\t";
		}
	}
}

void delete_array(int** array, int x, int y)
{
	for (size_t i = 0; i < x; i++)
	{
		delete[] array[i];
		array[i] = NULL;
	}

	delete[] array;
	array = NULL;
	return;
}

int main()
{
	int x;
	int y;

	get_dimensions(x, y); // request dimensions from user

	int** array = create_array(x,y); // create the array

	print_array_addresses(array, x, y); // print the array addresses

	delete_array(array, x, y); // delete array and set pointers to NULL

	int exitprogram;
	std::cout << "\n\nExiting.";
	std::cin >> exitprogram;
	return 0;
}