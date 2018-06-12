#include <iostream>
#include <string>

/*
1. Write a program to remove an element from a linked list; the remove function should take just
the element to be removed.Is this function easy to write—and will it be fast ? Could this be
made easier or faster by adding an additional pointer to the list ?
*/

struct linky // arbitrary struct to use for the linked list
{
	std::string name;
	int num;
	linky* p_nextLinky;
};

linky* removeLink(std::string name, linky* p_sLinky)
{
	if (p_sLinky == NULL) // if the list is empty and there's nothing to remove, return NULL
	{
		std::cout << "\nList is already empty!\n";
		return p_sLinky;
	}

	linky* currentLinky = p_sLinky; // two consecutive pointers will traverse the list
	linky* currentLinky2 = p_sLinky->p_nextLinky;

	if (currentLinky->name == name) // if the removal target is the first item on the list then we need not connect the previous node to the following node
	{
		p_sLinky = p_sLinky->p_nextLinky; // important to set p_sLinky before deleting currentLinky, otherwise p_sLinky->p_nextLinky will be reading from deleted memory (I think)
		delete currentLinky; // delete the removal target from memory
		return p_sLinky;
	}

	while (currentLinky2 != NULL)
	{
		if (currentLinky2->name == name)
		{
			currentLinky->p_nextLinky = currentLinky2->p_nextLinky; // connect previous node nextLinky to point to the node following the removal target
			delete currentLinky2; // delete the removal target from memory
			return p_sLinky;
		}
		currentLinky = currentLinky->p_nextLinky; // iterate both pointers one place further down the list
		currentLinky2 = currentLinky2->p_nextLinky;
	}

	std::cout << "\nCould not find that name in the list.\n"; // if the name isn't found, there's nothing to do, return the untouched p_sLinky;
	return p_sLinky;
}

linky* addLink(linky* p_sLinky) 
{
	linky* newLink = new linky;
	newLink->p_nextLinky = p_sLinky; // set p_nextLinky to be the (old) start of the list, as we are adding newLink to the front

	std::cout << "\nEnter name:\n";
	std::cin >>  newLink->name;
	std::cout << "\nEnter num:\n";
	std::cin >> newLink->num;

	return newLink; // return newLink, the new start of the list, to the caller (so p_sLinky can be updated, we can't do this inside the function as p_sLinky is local, would need a **pp_sLinky, then *pp_sLinky could be updated?)
}

void printLinks(linky* p_sLinky) // prints the list, self explanatory.
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
	linky* p_sLinky = NULL; // initialise the pointer to the start of the list
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
			std::cout << "\nEnter name of link to remove.\n"; // putting this here instead of inside the function to satisfy the function taking the element to delete (open to interpretation from the question I guess)
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