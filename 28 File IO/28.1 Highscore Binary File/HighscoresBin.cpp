#include "HighscoresBin.h"

highscoresBin::~highscoresBin()
{
	_file.close();
}

highscoresBin::highscoresBin(std::string filename)
	: _filename(filename)
	, _file(filename, std::ios::binary | std::ios::in | std::ios::out)
{
}

bool highscoresBin::insertScore(int score)
{
	// code to find entry position

	_file.clear();
	_file.seekp(std::ios::beg);
	_file.seekg(std::ios::beg);
	std::streampos entrypos = std::ios::beg;

	int holder = 0;
	while (_file.read(reinterpret_cast<char*>(&holder), sizeof(holder)))
	{
		if (score > holder)
		{
			break;
		}
		entrypos = _file.tellg();
	}

	if ( _file.fail() && ! _file.eof() )
	{
		std::cout << "Bad score / finding entrypos\n";
		return 0;
	}

	_file.clear();

	// copy remaining values to vector

	_file.seekg(entrypos);

	std::vector<int> tempscores;
	while (_file.read(reinterpret_cast<char*>(&holder), sizeof(holder)))
	{
		tempscores.push_back(holder);
	}

	// enter score in the correct position (overwriting any previous values that were there)

	if (!addScore(score, entrypos))
	{
		std::cout << "Error writing score\n";
		return 0;
	}

	// add all the scores we saved to the vector again this time one position lower (overwriting any previous values that were there)
	if (!addScore(tempscores, _file.tellp()))
	{
		std::cout << "Error rewriting previous scores\n";
		return 0;
	}

	// if success
	return 1;
}

bool highscoresBin::printScores()
{
	std::vector<int> scores;
	int holder;
	// code to print scores
	_file.clear();
	_file.seekg(std::ios::beg);

	while( _file.read(reinterpret_cast<char*>(&holder), sizeof holder) )
	{
		scores.push_back(holder);
	}

	for (std::vector<int>::iterator itr = scores.begin(), end = scores.end(); itr != end; ++itr)
	{
		std::cout << *itr << "\n";
	}

	// if we didn't get the end of the file then something went wrong with printing everything
	if (! _file.eof() )
	{
		std::cout << "Failed to print all scores\n";
	}

	// if success
	return 1;
}

bool highscoresBin::empty()
{
	// opening with std::ios::trunc will wipe the contents of the file
	std::ofstream deletefile(_filename, std::ios::trunc);
	deletefile.close();

	return 1;
}
 
// ---- Private

bool highscoresBin::addScore(int &score, std::streampos pos)
{
	_file.clear();
	_file.seekp(pos);

	if (! _file.write(reinterpret_cast<char*>(&score), sizeof score))
	{
		return 0;
	}

	return 1;
}

bool highscoresBin::addScore(std::vector<int> &scores, std::streampos pos)
{
	_file.clear();
	_file.seekp(pos);

	for (std::vector<int>::const_iterator itr = scores.begin(), end = scores.end(); itr != end; ++itr)
	{
		// reinterpret_cast does not seem to like the vector iterator itr, let's just use a temp int to store the important part of what itr points to and cast that instead.
		int temp = *itr;
		if (! _file.write(reinterpret_cast<char*>(&temp), sizeof(temp)))
		{
			return 0;
		}
	}

	return 1;
}
