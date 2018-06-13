#include <iostream>
#include <string>

/*
3. Write a program to find an element in a linked list by name.
*/

struct linky
{
	std::string name;
	int age;
	linky* p_next;
};

linky* addLinky(linky* p_list) 
{
	linky* newLink = new linky;
	newLink->p_next = p_list;

	std::cout << "\nEnter name:";
	std::cin >> newLink->name;
	std::cout << "\nEnter age:";
	std::cin >> newLink->age;
	return newLink;
}

linky* findLinky(linky* p_list, std::string name) // takes the list and the name to search for and returns a pointer to the entry with the same name. No support for duplicates, only finds the first entry of that name.
{
	linky* currentLinky = p_list;

	while (currentLinky != NULL)
	{
		if (currentLinky->name == name)
		{
			return currentLinky;
		}
		currentLinky = currentLinky->p_next;
	}

	std::cout << "\nCould not find that person in the list.";
	return NULL;
}

int main()
{
	linky* p_list = NULL;
	int menu = 0;
	bool exit = 0; 
	linky* person_of_interest; // we will return a pointer to the found person from our function and store it here
	std::string temp_name;

	std::cout << "Choose option:\n\t1. Add Person\n\t2. Find Person\n\t3. Exit";

	while (exit == 0)
	{
		std::cin >> menu;
		switch (menu)
		{
		case 1:
			p_list = addLinky(p_list);
			break;
		case 2:
			std::cout << "\nFind the age of:";
			std::cin >> temp_name;
			person_of_interest = findLinky(p_list, temp_name);
			std::cout << "\n\nName: " << person_of_interest->name << "\tAge: " << person_of_interest->age << "\n";
			break;
		case 3:
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