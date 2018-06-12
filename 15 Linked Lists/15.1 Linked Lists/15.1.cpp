#include <iostream>
#include <string>

/*
1. Write a program to remove an element from a linked list; the remove function should take just
the element to be removed.Is this function easy to write—and will it be fast ? Could this be
made easier or faster by adding an additional pointer to the list ?
*/

struct linky
{
	std::string name;
	int num;
	linky* p_nextLinky;
};

linky* removeLink(std::string name, linky* p_sLinky)
{
	if (p_sLinky == NULL)
	{
		std::cout << "\nList is already empty!\n";
		return p_sLinky;
	}

	linky* currentLinky = p_sLinky;
	linky* currentLinky2 = p_sLinky->p_nextLinky;

	if (currentLinky->name == name)
	{
		currentLinky2 = p_sLinky->p_nextLinky;
		delete currentLinky;
		return currentLinky2;
	}

	while (currentLinky2 != NULL)
	{
		if (currentLinky2->name == name)
		{
			currentLinky->p_nextLinky = currentLinky2->p_nextLinky;
			delete currentLinky2;
			return p_sLinky;
		}
		currentLinky = currentLinky->p_nextLinky;
		currentLinky2 = currentLinky2->p_nextLinky;
	}

	std::cout << "\nCould not find that name in the list.\n";
	return p_sLinky;
}

linky* addLink(linky* p_sLinky)
{
	linky* newLink = new linky;
	newLink->p_nextLinky = p_sLinky;

	std::cout << "\nEnter name:\n";
	std::cin >>  newLink->name;
	std::cout << "\nEnter num:\n";
	std::cin >> newLink->num;

	return newLink;
}

void printLinks(linky* p_sLinky)
{
	linky* currentLinky = p_sLinky;

	std::cout << "\nName\t\tNumber\n";
	
	while (currentLinky != NULL)
	{
		std::cout << currentLinky->name << "\t\t" << currentLinky->num << "\n";
		currentLinky = currentLinky->p_nextLinky;
	} 
}

int main()
{
	linky* p_sLinky = NULL;
	int menu = 0;
	bool exit = 0;
	std::string name = "";

	while (exit == 0)
	{
		std::cout << "\nChoose option:\n\t1.Add Link\n\t2.Remove Link\n\t3.View links\n\t4.Exit\n";
		std::cin >> menu;
		switch (menu)
		{
		case 1: 
			p_sLinky = addLink(p_sLinky);
			break;
		case 2: 
			std::cout << "\nEnter name of link to remove.\n";
			std::cin >> name;
			p_sLinky = removeLink(name, p_sLinky);
			break;
		case 3:
			printLinks(p_sLinky);
			break;
		case 4:
			exit = 1;
			break;
		default:
			break;
		}
	}

	int exitprogram;
	std::cout << "\nExiting.";
	std::cin >> exitprogram;
	return 0;
}