#include <iostream>

/*
1. Write a function that builds the multiplication table of arbitrary dimensions
*/

void build_board(int x, int y)
{
	int **p_p_board = new int*[x]; // create pointer to pointers;

	for (size_t i = 0; i < x; i++) // create pointers to arrays
	{
		p_p_board[i] = new int[y];
	}

	for (size_t i = 0; i < x; i++) // initialise board and print with multiplication table
	{
		std::cout << "\n";
		for (size_t j = 0; j < y; j++)
		{
			p_p_board[i][j] = (i+1)*(j+1);
			std::cout << p_p_board[i][j] << "\t";
		}
	}

	for (size_t i = 0; i < x; i++) // delete pointers to arrays
	{
		p_p_board[i] = NULL;
		delete [] p_p_board[i];
	}

	p_p_board = NULL;
	delete [] p_p_board; // delete pointer to pointers

	return;
}


void enter_dimensions()
{
	int x = 1;
	int y = 1;
	
	std::cout << "Enter integer dimensions.\n";
	std::cin >> x >> y;

	build_board(x, y);

	return;
}


int main()
{
	enter_dimensions();

	int exitprogram;
	std::cout << "\n\nExiting.";
	std::cin >> exitprogram;
	return 0;
}