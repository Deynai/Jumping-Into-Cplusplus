/*
1. Reimplement the text file version of the high-score program that inserts into the correct file position,
but do it using a binary file format instead of a text file format. How can you tell if your program is
working? Create a program that displays the file as a text file.
*/

#include <fstream>
#include <iostream>
#include <cstdlib>
#include <vector>
#include "HighscoresBin.h"

int main()
{
	highscoresBin hsfile("highscores.bin");
	
	hsfile.empty();
	hsfile.printScores();
	std::cout << "\n";

	hsfile.insertScore(270);
	hsfile.insertScore(770);
	hsfile.insertScore(570);
	hsfile.insertScore(650);

	hsfile.printScores();

	int exit;
	std::cin >> exit;
	return 0;
}

