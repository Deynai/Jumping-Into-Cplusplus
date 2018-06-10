#include <iostream>
#include <cstdlib>

struct mazecell
{
	bool visited; // has this cell been visited before?
	bool s; // is there a south wall?
	bool e; // is there an east wall?
	int last; // which direction did we enter this cell from?
};

struct location
{
	int x;
	int y;
};

void select_size(int &x, int &y)
{
	std::cout << "Select width:\n";
	std::cin >> x;
	std::cout << "Select height:\n";
	std::cin >> y;
	x += 2;
	y += 2;
	return;
}

void initialise_board(mazecell **pp_board, int x, int y)
{
	// initialise all cells to unvisited and all walls to true
	for (size_t i = 0; i < x; i++)
	{
		for (size_t j = 0; j < y; j++)
		{
			pp_board[i][j].visited = 0;
			pp_board[i][j].s = 1;
			pp_board[i][j].e = 1;
			pp_board[i][j].last = 0;
		}
	}

	// define boundary on first and last row/colums of the board that has been visited so the algo doesn't try to leave
	for (size_t i = 0; i < x; i++)
	{
		pp_board[i][0].visited = 1;
		pp_board[i][y - 1].visited = 1;
	}

	for (size_t j = 0; j < y; j++)
	{
		pp_board[0][j].visited = 1;
		pp_board[x - 1][j].visited = 1;
	}
	
}

int pick_direction(mazecell **pp_board, location loc)
{
	bool valid_dir[4];
	int pick_dir;
	int sum_valid = 0;
	// create temporary array to store whether a direction is valid
	valid_dir[0] = !pp_board[loc.x][loc.y - 1].visited;
	valid_dir[1] = !pp_board[loc.x][loc.y + 1].visited;
	valid_dir[2] = !pp_board[loc.x - 1][loc.y].visited;
	valid_dir[3] = !pp_board[loc.x + 1][loc.y].visited;

	for (size_t i = 0; i < 4; i++)
	{
		if (valid_dir[i] == 1)
		{
			sum_valid += 1;
		}
	}
	if (sum_valid == 0)
	{
		return -1;
	}

	// pick a random number from 0 to total number of valid directions
	pick_dir = rand() % sum_valid;

	int counter = 0;

	// associate the random pick to a specific direction and return it to the caller
	for (size_t i = 0; i < 4; i++)
	{
		if (pick_dir == counter && valid_dir[i] == 1)
		{
			return i;
		}

		if (valid_dir[i] == 1)
		{
			counter += 1;
		}
	}
	return -1;
}

bool move_direction(mazecell **pp_board, location &loc, int dir)
{
	switch (dir)
	{
		// remove wall in direction of new cell
		// change location to new cell
		// change visited to true on new cell
		// define direction of previous cell

	case 0: // go north
		pp_board[loc.x][loc.y - 1].s = 0;
		loc.y -= 1;
		pp_board[loc.x][loc.y].visited = 1;
		pp_board[loc.x][loc.y].last = 1;
		return 1;
		break;
	case 1: // go south
		pp_board[loc.x][loc.y].s = 0;
		loc.y += 1;
		pp_board[loc.x][loc.y].visited = 1;
		pp_board[loc.x][loc.y].last = 2;
		return 1;
		break;
	case 2: // go west
		pp_board[loc.x - 1][loc.y].e = 0;
		loc.x -= 1;
		pp_board[loc.x][loc.y].visited = 1;
		pp_board[loc.x][loc.y].last = 3;
		return 1;
		break;
	case 3: // go east
		pp_board[loc.x][loc.y].e = 0;
		loc.x += 1;
		pp_board[loc.x][loc.y].visited = 1;
		pp_board[loc.x][loc.y].last = 4;
		return 1;
		break;
	default: // failed to move forward
		return 0;
		break;
	}
}

bool move_back(mazecell **pp_board, location &loc)
{
	// .last stores the direction of the previous cell
	switch (pp_board[loc.x][loc.y].last)
	{
	case 1: loc.y += 1;
		return 0;
		break;
	case 2: loc.y -= 1;
		return 0;
		break;
	case 3: loc.x += 1;
		return 0;
		break;
	case 4: loc.x -= 1;
		return 0;
		break;
	default:
		return 1;
		break;
	}
}

void generate_maze(mazecell **pp_board, int x, int y)
{
	bool maze_finished = 0;

	// initalise a location to keep track of where we are in the maze
	location loc;
	loc.x = 1, loc.y = 1;
	pp_board[1][1].visited = 1; 

	while (maze_finished == 0)
	{
		
		// find and pick a valid moment at random (uniform)
		int dir = pick_direction(pp_board, loc);

		// if no valid movement, move back to previous cell, then repeat
		if (move_direction(pp_board, loc, dir) == 0)
		{
			maze_finished = move_back(pp_board, loc);
		}
	}
}

void print_maze(mazecell **pp_board, int x, int y)
{
	// create an exit in south east corner
	pp_board[x - 2][y - 2].s = 0;
	std::cout << "\n  ";

	// top border, with entrance in north west
	for (size_t i = 2; i < x-1; i++)
	{
		std::cout << " _";
	}

	// print maze based on each cells .s (south) and .e (east) facing walls
	for (size_t j = 1; j < y-1; j++)
	{
		std::cout << "\n|";
		for (size_t i = 1; i < x-1; i++)
		{
			if (pp_board[i][j].s == 1)
			{
				std::cout << "_";
			}
			else
			{
				std::cout << " ";
			}
			if (pp_board[i][j].e == 1)
			{
				std::cout << "|";
			}
			else
			{
				std::cout << " ";
			}
		}
	}
}


int main()
{
	int x = 1;
	int y = 1;
	select_size(x, y);

	mazecell **pp_board = new mazecell*[x];
	for (size_t i = 0; i < x; i++)
	{
		pp_board[i] = new mazecell[y];
	}

	initialise_board(pp_board, x, y);

	generate_maze(pp_board, x, y);

	print_maze(pp_board, x, y);

	// delete maze and free memory
	for (size_t i = 0; i < x; i++)
	{
		delete[] pp_board[i];
		pp_board[i] = NULL;
	}

	delete[] pp_board;
	pp_board = NULL;
	//-------

	int exitprogram;
	std::cout << "\n\nExiting.";
	std::cin >> exitprogram;
	return 0;
}