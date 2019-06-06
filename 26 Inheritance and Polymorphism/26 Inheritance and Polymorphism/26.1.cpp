/*
1. Implement a sort function that takes a vector of pointers to an interface class, Comparable,
that defines a method, compare(Comparable& other), and returns 0 if the objects are the
same, 1 if the object is greater than other, and -1 if the object is less than other. Create a class
that implements this interface, create several instances, and sort them. If you're looking for
some inspiration for what to create—try a HighScoreElement class that has a name and a
score, and sorts so that the top scores are first, but if two scores are the same, they are sorted
next by name.
*/

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