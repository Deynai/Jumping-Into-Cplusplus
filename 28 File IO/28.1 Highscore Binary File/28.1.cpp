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

