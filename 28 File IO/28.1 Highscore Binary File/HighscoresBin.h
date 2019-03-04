#pragma once

#ifndef HIGHSCORESBIN_RH
#define HIGHSCORESBIN_RH

#include <fstream>
#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>

class highscoresBin
{
public:
	highscoresBin(std::string filename);
	~highscoresBin();
	bool insertScore(int score); // insert a score into the highscore list
	bool printScores(); // display the highscore list
	bool empty(); // calling this will empty the highscore list

private:
	std::string _filename;
	std::fstream _file;
	bool addScore(int &score, std::streampos pos);
	bool addScore(std::vector<int> &scores, std::streampos pos);
	
};

#endif