/* 2. Use vectors to implement a high score list for a video game. Make it so that scores are updated
automatically, and new scores are added into the right place in the list. You may find the SGI
website listed above useful for finding more operations you can do on vectors.
*/

#include <iostream>
#include <vector>
#include <string>

struct score
{
	int value;
	std::string name;
};

void addScore(std::vector<score> &highscores, score entry)
{
	// find if our player is already in the highscores
	for (std::vector<score>::iterator i = highscores.begin(), end = highscores.end(); i != end; ++i)
	{
		if (i->name == entry.name)
		{
			// if we found our existing players score and the new score is better than the old one, erase the old one, and let our function continue to add a new one in the right place
			if (i->value < entry.value)
			{
				highscores.erase(i);
				break;
			}
			// if the new score is NOT better than the old one, nothing needs to be added or updated, so let's just return out of addScore.
			else
			{
				return;
			}
		}
	}

	// iterator through the highscores, we assume that it is already sorted
	for (std::vector<score>::iterator i = highscores.begin(), end = highscores.end(); i != end; ++i)
	{
		// if our entry is greater than the current score the iterator is pointing to, let's insert our entry in it's place (just before it)
		if (entry.value >= i->value)
		{
			highscores.insert(i, entry);
			return;
		}
	}

	// if our entry isn't greater than anything in the highscores (or if the highscores are empty), then add it to the end
	highscores.push_back(entry);
	return;
}

void displayScores(std::vector<score> highscores)
{
	
	for (std::vector<score>::iterator i = highscores.begin(), end = highscores.end(); i != end; ++i)
	{
		std::cout << i->value << " - " << i->name << "\n";
	}
	return;
}

int main()
{
	std::vector<score> highscores;
	bool exit = 0;
	int menu = 0;
	score entry;

	while (!exit)
	{
		std::cout << "\nMenu\n1. Add Score\n2. Display Scores\n3. Exit\n";
		std::cin >> menu;
		system("CLS");
		switch (menu)
		{
		case 1: 
			std::cout << "\nEnter Score:\n";
			std::cin >> entry.value;
			std::cout << "\nEnter Name:\n";
			std::cin >> entry.name;
			addScore(highscores, entry);
			break;
		case 2: displayScores(highscores);
			break;
		case 3: exit = 1;
			break;
		default:
			break;
		}
	}

	std::cout << "\nExiting.";
	std::cin >> exit;
	return 0;
}