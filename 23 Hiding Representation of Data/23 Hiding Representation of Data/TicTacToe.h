
#ifndef tictactoe_RH
#define tictactoe_RH

enum tictacPiece { EMPTY, X, O };
enum playerTurn { PT_X, PT_O };
enum result { X_WIN, O_WIN, DRAW, ACTIVE};

struct tictac
{
	tictacPiece board[3][3];
	playerTurn whoseTurn;
	result status; 

	// public
	void init(); // initialise empty board
	bool isValidMove(int x, int y); // check if the square is empty, return 1 or 0
	void makeMove(int x, int y); // places playerTurns piece
	result checkWin(); // returns if X or O has won, if it's a draw, or if it is unfinished
	void display(); // print board
	playerTurn getPlayer(); // return PT_X for X's turn and PT_O for O's turn

	// Private
	result updateStatus();
};

void tictac::init()
{
	for (size_t i = 0; i < 3; i++)
	{
		for (size_t j = 0; j < 3; j++)
		{
			board[i][j] = EMPTY;
		}
	}
	whoseTurn = PT_X;
	status = ACTIVE;
	return;
}

bool tictac::isValidMove(int x, int y)
{
	if (x < 1 || x > 3 || y < 1 || y > 3)
	{
		return 0;
	}
	if (board[x-1][y-1] == EMPTY)
	{
		return 1;
	}
	return 0;
}

void tictac::makeMove(int x, int y)
{
	tictacPiece piece;
	if (whoseTurn == PT_O)
	{
		piece = O;
		whoseTurn = PT_X;
	}
	else
	{
		piece = X;
		whoseTurn = PT_O;
	}

	board[x-1][y-1] = piece;
	this->updateStatus();
	return;
}

result tictac::checkWin()
{
	return status;
}

void tictac::display ()
{
	std::cout << "\n";
	for (size_t j = 0; j < 3; j++)
	{
		for (size_t i = 0; i < 3; i++)
		{
			switch (board[i][j])
			{
			case EMPTY: std::cout << "_ "; break;
			case X: std::cout << "X "; break;
			case O: std::cout << "O "; break;
			default: std::cout << "? "; break;
			}
		}
		std::cout << "\n";
	}
	return;
}

playerTurn tictac::getPlayer()
{
	return whoseTurn;
}

result tictac::updateStatus()
{
	// check horizontal
	for (size_t i = 0; i < 3; i++)
	{
		if (board[0][i] != EMPTY && board[0][i] == board[1][i] && board[0][i] == board[2][i])
		{
			switch (board[0][i])
			{
			case X: return X_WIN; break;
			case O: return O_WIN; break;
			}
		}
	}
	// check vertical
	for (size_t i = 0; i < 3; i++)
	{
		if (board[i][0] != EMPTY && board[i][0] == board[i][1] && board[i][0] == board[i][2])
		{
			switch (board[i][0])
			{
			case X: return X_WIN; break;
			case O: return O_WIN; break;
			}
		}
	}
	// check diagonal
	if (board[0][0] != EMPTY && board[0][0] == board[1][1] && board[0][0] == board[2][2])
	{
		switch (board[0][0])
		{
		case X: return X_WIN; break;
		case O: return O_WIN; break;
		}
	}
	if (board[2][0] != EMPTY && board[2][0] == board[1][1] && board[2][0] == board[0][2])
	{
		switch (board[2][0])
		{
		case X: return X_WIN; break;
		case O: return O_WIN; break;
		}
	}
	// check draw
	for (size_t i = 0; i < 3; i++)
	{
		for (size_t j = 0; j < 3; j++)
		{
			if (board[i][j] == EMPTY)
			{
				return ACTIVE;
			}
		}
	}
	return DRAW;
}

#endif