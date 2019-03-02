#include "TicTac.h"
#include <iostream>

void tictac::init()
{
	for (size_t i = 0; i < 3; i++)
	{
		for (size_t j = 0; j < 3; j++)
		{
			_board[i][j] = EMPTY;
		}
	}
	_whoseTurn = PT_X;
	_status = ACTIVE;
	return;
}

bool tictac::isValidMove(int x, int y)
{
	if (x < 1 || x > 3 || y < 1 || y > 3)
	{
		return 0;
	}
	if (_board[x - 1][y - 1] == EMPTY)
	{
		return 1;
	}
	return 0;
}

void tictac::makeMove(int x, int y)
{
	tictacPiece piece;
	if (_whoseTurn == PT_O)
	{
		piece = O;
		_whoseTurn = PT_X;
	}
	else
	{
		piece = X;
		_whoseTurn = PT_O;
	}

	_board[x - 1][y - 1] = piece;
	_status = this->_updateStatus();
	return;
}

result tictac::checkWin()
{
	return _status;
}

void tictac::display()
{
	std::cout << "\n";
	for (size_t j = 0; j < 3; j++)
	{
		for (size_t i = 0; i < 3; i++)
		{
			switch (_board[i][j])
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
	return _whoseTurn;
}

result tictac::_updateStatus()
{
	// check horizontal
	for (size_t i = 0; i < 3; i++)
	{
		if (_board[0][i] != EMPTY && _board[0][i] == _board[1][i] && _board[0][i] == _board[2][i])
		{
			switch (_board[0][i])
			{
			case X: return X_WIN; break;
			case O: return O_WIN; break;
			}
		}
	}
	// check vertical
	for (size_t i = 0; i < 3; i++)
	{
		if (_board[i][0] != EMPTY && _board[i][0] == _board[i][1] && _board[i][0] == _board[i][2])
		{
			switch (_board[i][0])
			{
			case X: return X_WIN; break;
			case O: return O_WIN; break;
			}
		}
	}
	// check diagonal
	if (_board[0][0] != EMPTY && _board[0][0] == _board[1][1] && _board[0][0] == _board[2][2])
	{
		switch (_board[0][0])
		{
		case X: return X_WIN; break;
		case O: return O_WIN; break;
		}
	}
	if (_board[2][0] != EMPTY && _board[2][0] == _board[1][1] && _board[2][0] == _board[0][2])
	{
		switch (_board[2][0])
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
			if (_board[i][j] == EMPTY)
			{
				return ACTIVE;
			}
		}
	}
	return DRAW;
}
