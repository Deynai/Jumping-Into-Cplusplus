#include <iostream>
#include <vector>
#include "Comparable.h"

void sortVec(std::vector<Comparable*> &list) // performs a simple bubble sort on a list of pointers to Comparables
{
	bool sorted = 0;
	Comparable *p_temp;
	while (sorted == 0)
	{
		sorted = 1; // assume list is sorted
		for (std::vector<Comparable*>::iterator itr = list.begin(), end = list.end(); (itr+1) != end; ++itr) // I initally wrote this with an itr2 instead of itr+1. Not sure if using itr+1 repeatedly is more costly than having a separate itr2 and incrementing both. Looks cleaner.
		{
			switch ((*itr)->compare(**(itr+1)))
			{
			case -1: // if compare method returns -1, first value is lower than the second, so let's swap them
				p_temp = *itr;
				*itr = *(itr+1);
				*(itr+1) = p_temp;
				sorted = 0; // if we swap anything then let's say it's not sorted (even though it might be if it was the last swap). This means we don't need a separate "check if sorted" function, we just keep going until we do a full loop with no change.
				break;
			default: // otherwise do nothing
				break;
			}
		}
	}
}

void addScore(std::vector<Comparable*> &list, int score, std::string name)
{
	list.push_back(new HighscoreElement(score, name)); 
	return;
}

void inputScore(std::vector<Comparable*> &list)
{
	int score;
	std::string name;
	std::cout << "Enter Score:\n";
	std::cin >> score;
	std::cout << "\nEnter Name:\n";
	std::cin >> name;
	addScore(list, score, name);
}

void printList(std::vector<Comparable*> &list)
{
	for (std::vector<Comparable*>::iterator itr = list.begin(), end = list.end(); itr != end; ++itr)
	{
		std::cout << (*itr)->getValue() << " - " << (*itr)->getString() << "\n";
	}
	return;
}

int main()
{
	std::vector<Comparable*> list;

	for (size_t i = 0; i < 5; i++) // let's just loop a few times to populate our list with user input
	{
		inputScore(list);
	}

	sortVec(list);

	printList(list);

	for (std::vector<Comparable*>::iterator itr = list.begin(), end = list.end(); itr != end; ++itr) // cleanup
	{
		delete *itr;
	}
	list.clear();

	int exit;
	std::cin >> exit;
	return 0;
}