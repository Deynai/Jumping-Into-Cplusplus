#include <iostream>

/*
2. Write a function that takes 3 arguments, a length, width and height, dynamically allocates a 3-
dimensional array with those values and fills the 3-dimensional array with multiplication tables.
Make sure to free the array when you are done.
*/

void create_table(int z, int y, int x)
{
	int ***p_p_p_table = new int**[x]; // create pointer to pointers to pointers (3d array)
	
	for (size_t i = 0; i < x; i++)
	{
		p_p_p_table[i] = new int*[y]; // create ith pointer to pointers
		for (size_t j = 0; j < y; j++)
		{
			p_p_p_table[i][j] = new int[z]; // create [i][j]th pointer to array
		}
	}

	for (size_t i = 0; i < x; i++)
	{
		std::cout << "\n\n";
		for (size_t j = 0; j < y; j++)
		{
			std::cout << "\n";
			for (size_t k = 0; k < z; k++)
			{
				p_p_p_table[i][j][k] = (i + 1)*(j + 1)*(k + 1); // initialise with multiplication table
				std::cout << p_p_p_table[i][j][k] << "\t"; // print value one by one as they are initialised
			}
		}
	}

	for (size_t i = 0; i < x; i++) 
	{
		for (size_t j = 0; j < y; j++) // delete [i][j]th pointers to arrays
		{
			delete[] p_p_p_table[i][j];
			p_p_p_table[i][j] = NULL;
		}
		delete[] p_p_p_table[i]; // delete [i]th pointers to pointers
		p_p_p_table[i] = NULL;
	}

	delete[] p_p_p_table; // delete pointer to pointers to pointers
	p_p_p_table = NULL;
}

void set_dimensions(int& x, int& y, int& z)
{
	std::cout << "Enter 3 Dimensions.";
	std::cin >> x >> y >> z;
	return;
}

int main()
{
	int x = 1, y = 1, z = 1;
	
	set_dimensions(x, y, z);

	create_table(x, y, z);

	int exitprogram;
	std::cout << "\n\nExiting.";
	std::cin >> exitprogram;
	return 0;
}