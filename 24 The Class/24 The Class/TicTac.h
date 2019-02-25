#ifndef tictac_RH
#define tictac_RH

#include <iostream>

enum tictacPiece { EMPTY, X, O };
enum playerTurn { PT_X, PT_O };
enum result { X_WIN, O_WIN, DRAW, ACTIVE };

class tictac
{
public:
	void init(); // initialise empty board
	bool isValidMove(int x, int y); // check if the square is empty, return 1 or 0
	void makeMove(int x, int y); // places playerTurns piece
	result checkWin(); // returns if X or O has won, if it's a draw, or if it is unfinished
	void display(); // print board
	playerTurn getPlayer(); // return PT_X for X's turn and PT_O for O's turn
private:
	result _updateStatus();
	playerTurn _whoseTurn;
	result _status;
	tictacPiece _board[3][3];
};

#endif