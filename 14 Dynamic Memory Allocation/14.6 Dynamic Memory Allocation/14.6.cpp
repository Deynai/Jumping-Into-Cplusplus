#include <iostream>


void select_size(int &x, int &y)
{
	std::cout << "Select width:\n";
	std::cin >> x;
	std::cout << "Select height:\n";
	std::cin >> y;
	return;
}

int main()
{
	int x = 1;
	int y = 1;
	select_size(x, y);

	int **pp_board = new int*[x];
	for (size_t i = 0; i < x; i++)
	{
		pp_board[i] = new int[y];
	}








	int exitprogram;
	std::cout << "\nExiting.";
	std::cin >> exitprogram;
	return 0;
}