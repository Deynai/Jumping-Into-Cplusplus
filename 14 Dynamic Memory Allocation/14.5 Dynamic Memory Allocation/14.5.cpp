#include <iostream>

/*
5. Write a two-player game of "connect 4"31 where the user can set the width and height of the
board and each player gets a turn to drop a token into the slot. Display the board using + for one
side, x for the other, and _ to indicate blank spaces.
*/

int x = 4;
int y = 4;

void select_size(int &x, int &y)
{
	std::cout << "Select width:\n";
	std::cin >> x;
	std::cout << "Select height:\n";
	std::cin >> y;
	return;
}

enum player
{
	Player_1, Player_2
};

void print_board(int **pp_board)
{
	for (size_t i = 0; i < y; i++)
	{
		std::cout << "\n";
		for (size_t j = 0; j < x; j++)
		{
			switch (pp_board[j][y-1 - i])
			{
			case 0: std::cout << " _ ";
				break;
			case 1: std::cout << " X ";
				break;
			case 2: std::cout << " O ";
			default:
				break;
			}
		}
	}
}

bool check_finish(int **pp_board)
{
	// check horizontal
	for (size_t j = 0; j < y; j++)
	{
		for (size_t i = 0; i < x-3; i++)
		{
			if (pp_board[i][j] == pp_board[i+1][j] && pp_board[i][j] == pp_board[i+2][j] && pp_board[i][j] == pp_board[i+3][j] && pp_board[i][j] != 0)
			{
				switch (pp_board[i][j])
				{
				case 1: std::cout << "\n\nPlayer X wins!";
					return 1;
					break;
				case 2:	std::cout << "\n\nPlayer O wins!";
					return 1;
					break;
				default:
					break;
				}
			}
		}
	}

	// check vertical
	for (size_t i = 0; i < x; i++)
	{
		for (size_t j = 0; j < y-3; j++)
		{
			if (pp_board[i][j] == pp_board[i][j+1] && pp_board[i][j] == pp_board[i][j+2] && pp_board[i][j] == pp_board[i][j+3] && pp_board[i][j] != 0)
			{
				switch (pp_board[i][j])
				{
				case 1: std::cout << "\n\nPlayer X wins!";
					return 1;
					break;
				case 2:	std::cout << "\n\nPlayer O wins!";
					return 1;
					break;
				default:
					break;
				}
			}
		}
	}
	
	// check diagonal
	for (size_t i = 0; i < x-3; i++)
	{
		for (size_t j = 0; j < y-3; j++)
		{
			if (pp_board[i][j] == pp_board[i + 1][j + 1] && pp_board[i][j] == pp_board[i + 2][j + 2] && pp_board[i][j] == pp_board[i + 3][j + 3] && pp_board[i][j] != 0)
			{
				switch (pp_board[i][j])
				{
				case 1: std::cout << "\n\nPlayer X wins!";
					return 1;
					break;
				case 2:	std::cout << "\n\nPlayer O wins!";
					return 1;
					break;
				default:
					break;
				}
			}

			if (pp_board[x-1 - i][j] == pp_board[x-1 - i - 1][j+1] && pp_board[x-1 - i][j] == pp_board[x-1 - i - 2][j+2] && pp_board[x - 1 - i][j] == pp_board[x - 1 - i - 3][j+3] && pp_board[x - 1 - i][j] != 0)
			{
				switch (pp_board[i][j])
				{
				case 1: std::cout << "\n\nPlayer X wins!";
					return 1;
					break;
				case 2:	std::cout << "\n\nPlayer O wins!";
					return 1;
					break;
				default:
					break;
				}
			}
		}
	}

	return 0;
}

void make_move(player player_turn, int **pp_board)
{
	int piece;
	switch (player_turn)
	{
	case Player_1: piece = 1;
		break;
	case Player_2: piece = 2;
		break;
	default:
		break;
	}

	int move_column = 0;
	std::cout << "\nEnter move:\n";
	std::cin >> move_column;
	while (move_column < 0 || move_column >= y || pp_board[move_column][y-1] != 0)
	{
		std::cout << "\nInvalid move. Enter a number from 1 to " << y << ".\n";
		std::cin >> move_column;
	}

	//----

	for (int i = 0; i < y; i++)
	{
		if (pp_board[move_column-1][i] == 0)
		{
			pp_board[move_column-1][i] = piece;
			break;
		}
	}
}

int main()
{
	select_size(x, y);

	// initialise board
	int **pp_board = new int*[x];
	for (size_t i = 0; i < x; i++)
	{
		pp_board[i] = new int[y];
	}
	for (size_t i = 0; i < x; i++)
	{
		for (size_t j = 0; j < y; j++)
		{
			pp_board[i][j] = 0;
		}
	}
	// ----

	bool game_over = 0;
	player player_turn = Player_2; // player_turn: 0 = player 1, 1 = player 2

	while (game_over == 0)
	{
		switch (player_turn)
		{
		case Player_1: player_turn = Player_2;
			std::cout << "\nIt is O's turn.";
			break;
		case Player_2: player_turn = Player_1;
			std::cout << "\nIt is X's turn.";
			break;
		}

		make_move(player_turn, pp_board);

		print_board(pp_board);

		game_over = check_finish(pp_board);
	}
	
	// delete board and free memory
	for (size_t i = 0; i < x; i++)
	{
		delete[] pp_board[i];
		pp_board[i] = NULL;
	}

	delete[] pp_board;
	pp_board = NULL;

	int exitprogram;
	std::cout << "\n\nExiting.";
	std::cin >> exitprogram;
	return 0;
}