/*
1. Take the structure from the practice problem at the end of the last chapter (representing a tic
tac toe board) and reimplement it using a class, marking the publicly useful methods as public
and marking the data and any helper methods as private. How much of your code did you have
to change?
*/


#include <iostream>
#include "TicTac.h"

int main()
{
	tictac ttt;
	ttt.init();
	int x = 0, y = 0;

	while (ttt.checkWin() == ACTIVE)
	{
		ttt.display();

		switch (ttt.getPlayer())
		{
		case PT_O: std::cout << "\nPlayer O's turn. "; break;
		case PT_X: std::cout << "\nPlayer X's turn. "; break;
		default: break;
		}

		// 1 1 corresponds to top left, 3 3 corresponds to bottom right, 3 1 corresponds to top right
		std::cout << "Enter your move X Y\n";
		std::cin >> x >> y;

		while (!ttt.isValidMove(x, y))
		{
			std::cout << "Invalid move, please enter another move: ";
			std::cin >> x >> y;
		}

		ttt.makeMove(x, y);
	}

	std::cout << "\n\n";
	ttt.display();

	switch (ttt.checkWin())
	{
	case X_WIN: std::cout << "\nX wins"; break;
	case O_WIN: std::cout << "\nO wins"; break;
	case DRAW: std::cout << "\nDraw"; break;
	default: break;
	}

	int exit;
	std::cin >> exit;
	return 0;
}