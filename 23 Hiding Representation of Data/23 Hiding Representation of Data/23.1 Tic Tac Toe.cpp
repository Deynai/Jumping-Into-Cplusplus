/*
1. Write a structure that provides the interface to a tic-tac-toe board. Implement a two player tictac-
toe game with the methods on the structure. You should make it so that basic operations
like making a move and checking whether one player has won are part of the interface of the
structure.
*/

#include <iostream>
#include "TicTacToe.h"

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

		while (!ttt.isValidMove(x,y))
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