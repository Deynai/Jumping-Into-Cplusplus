#include <iostream>
#include <string>

/*
4. Implement a two player tic-tac-toe game. First use a linked list to represent the board. Then use
an array. Which is easier? Why?
*/

/*
1 2 3
4 5 6
7 8 9
*/

struct cell
{
	int pos;
	int state;
	cell* p_next;
};

cell* initBoard(cell* p_board)
{
	for (size_t i = 0; i < 9; i++)
	{
		cell* newCell = new cell;
		newCell->pos = 9-i; // reverse order so 1 is at the start of the list
		newCell->state = 0;
		newCell->p_next = p_board;
		p_board = newCell;
	}
	return p_board;
}

cell* findCell(cell* p_board, int move)
{
	cell* currentCell = p_board;

	if (move <= 0 || move > 9) // must pick a number from 1 to 9
	{
		return NULL;
	}

	if (move == 1)
	{
		return currentCell;
	}

	for (size_t i = 0; i < move-1; i++)
	{
		currentCell = currentCell->p_next;
	}
	return currentCell;
}

cell* makeMove(cell* p_board, bool currentPlayer)
{
	int move;
	cell* foundCell = NULL;
	
	std::cin >> move;
	foundCell = findCell(p_board, move); // set foundCell to the corresponding position of move, if possible;

	while (foundCell == NULL || foundCell->state != 0) // if the given move is invalid or has already been played then it's not legal, must pick another
	{
		std::cout << "\nInvalid move, Pick again\n";
		std::cin >> move;
		foundCell = findCell(p_board, move);
	}

	foundCell->state = currentPlayer + 1;

	return p_board;
}

bool checkWinner(cell* p_board, bool currentPlayer)
{
	// horizontal
	if ((findCell(p_board,1) != 0 && findCell(p_board, 1)->state == findCell(p_board, 2)->state && findCell(p_board, 1)->state == findCell(p_board, 3)->state) || (findCell(p_board, 4)->state != 0) && (findCell(p_board, 4)->state == findCell(p_board, 5)->state && findCell(p_board, 4)->state == findCell(p_board, 6)->state) || (findCell(p_board, 7)->state != 0) && (findCell(p_board, 7)->state == findCell(p_board, 8)->state && findCell(p_board, 7)->state == findCell(p_board, 9)->state))
	{
		std::cout << "\nPlayer " << currentPlayer+1 << " wins!";
		return 1;
	}

	// vertical
	if ((findCell(p_board, 1)->state != 0) && (findCell(p_board, 1)->state == findCell(p_board, 4)->state && findCell(p_board, 1)->state == findCell(p_board, 7)->state) || (findCell(p_board, 2)->state != 0) && (findCell(p_board, 2)->state == findCell(p_board, 5)->state && findCell(p_board, 2)->state == findCell(p_board, 6)->state) || (findCell(p_board, 3)->state != 0) && (findCell(p_board, 3)->state == findCell(p_board, 6)->state && findCell(p_board, 3)->state == findCell(p_board, 9)->state))
	{
		std::cout << "\nPlayer " << currentPlayer+1 << " wins!";
		return 1;
	}

	// diagonal
	if ((findCell(p_board, 1)->state != 0) && (findCell(p_board, 1)->state == findCell(p_board, 5)->state && findCell(p_board, 1)->state == findCell(p_board, 9)->state) || (findCell(p_board, 3)->state != 0) && (findCell(p_board, 3)->state == findCell(p_board, 5)->state && findCell(p_board, 3)->state == findCell(p_board, 7)->state))
	{
		std::cout << "\nPlayer " << currentPlayer+1 << " wins!";
		return 1;
	}

	// is there still a spot to play?
	cell* currentLink = p_board;

	for (size_t i = 0; i < 9; i++)
	{
		if (currentLink->state == 0)
		{
			return 0; // yes! keep playing
		}
		currentLink = currentLink->p_next;
	}

	std::cout << "\nDraw!";
	return 1; // couldn't find a winner and couldn't find a spot to play, game must be a draw. 
	
	// For a fixed 3x3 tic tac toe board we could skip this draw check in place of a counter in the main loop, after 9 total moves without a winner the game by default is a draw as there's only 9 places to play which is probably more efficient.
}

void printBoard(cell* p_board)
{
	cell* currentCell = p_board;
	std::string piece;

	for (size_t i = 0; i < 3; i++)
	{
		std::cout << "\n| ";
		for (size_t j = 0; j < 3; j++)
		{
			switch (currentCell->state) // convert 0/1/2 states into _/X/O
			{
			case 0: 
				piece = " ";
				break;
			case 1:
				piece = "X";
				break;
			case 2:
				piece = "O";
				break;
			default:
				break;
			}

			std::cout << piece << " | ";
			currentCell = currentCell->p_next;
		}
	}
}

int main()
{
	cell* p_board = NULL;
	p_board = initBoard(p_board);

	bool currentPlayer = 1;
	bool isGameFinished = 0;
	int move;

	std::cout << "1 | 2 | 3\n4 | 5 | 6\n7 | 8 | 9"; // print the numbered board positions

	while (isGameFinished == 0)
	{
		currentPlayer = !currentPlayer; // swap active player

		std::cout << "\n\nPlayer " << currentPlayer + 1 << "\n"; // declare which player is playing

		p_board = makeMove(p_board, currentPlayer); // let active player make a move

		isGameFinished = checkWinner(p_board, currentPlayer); // check the board state to see if the game has finished with a winner or a draw

		printBoard(p_board); // print the updated board
	}

	int exitprogram;
	std::cout << "\nExiting.";
	std::cin >> exitprogram;
	return 0;
}