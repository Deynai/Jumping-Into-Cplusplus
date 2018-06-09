#include <iostream>
#include <string>

/*
4. Write a program that lets users keep track of the last time they talked to each of their friends.
Users should be able to add new friends (as many as they want!) and store the number of days
ago that they last talked to each friend. Let users update this value (but don't let them put in
bogus numbers like negative values). Make it possible to display the list sorted by the names of
the friends of by how recently it was since they talked to each friend.
*/

struct contact
{
	std::string name;
	int time;
};

contact* increase_size(contact *p_list)
{
	int size = p_list[0].time;
	contact *p_list_new = new contact[p_list[0].time * 2];
	p_list_new[0].name = "Size";
	p_list_new[0].time = p_list[0].time * 2; // update size information in pointer

	for (size_t i = 1; i < p_list[0].time; i++)
	{
		p_list_new[i] = p_list[i]; // copy values in old array to the new one
	}
	for (size_t i = p_list[0].time; i < p_list[0].time * 2; i++)
	{
		p_list_new[i].name = "0";
		p_list_new[i].time = 0; // initialise remaining values in the new array
	}

	delete[] p_list;
	p_list = NULL; // delete old array and then update p_list to be the new one
	return p_list_new;
}

void sort_list(contact *p_list)
{
	contact temp_contact;
	bool isSorted = 0;

	while (isSorted == 0)
	{
		for (size_t i = 1; i < p_list[0].time - 1; i++)
		{
			if (p_list[i].time > p_list[i+1].time)
			{
				if (p_list[i + 1].name == "0")
				{
					isSorted = 1;
					break;
				}
				temp_contact = p_list[i];
				p_list[i] = p_list[i + 1];
				p_list[i + 1] = temp_contact;
				break;
			}
		}
	}
	return;
}

void print_list(contact *p_list)
{
	std::cout << "\n\tName\tDays since last chat";

	for (size_t i = 1; i < p_list[0].time; i++)
	{
		if (p_list[i].name == "0")
		{
			break; // stop printing when we reach the end of the names
		}
		std::cout << "\n\t" << p_list[i].name << "\t" << p_list[i].time;
	}
	return;
}

contact* update_friend(contact *p_list)
{
	contact temp_contact;

	std::cout << "\nEnter name of friend:\n";
	std::cin >> temp_contact.name;
	std::cout << "\nEnter days since last chat:\n";
	std::cin >> temp_contact.time;
	while (temp_contact.time < 0)
	{
		std::cout << "\nPlease enter non-negative time:\n";
		std::cin >> temp_contact.time;
	}

	while (true)
	{
		for (size_t i = 1; i < p_list[0].time; i++)
		{
			if (p_list[i].name == temp_contact.name || p_list[i].name == "0")
			{
				p_list[i] = temp_contact;
				// p_list[i].name = temp_contact.name;
				// p_list[i].time = temp_contact.time;
				return p_list; // if we added the friend or updated, return to the menu, else we ran out of space and need to increase the size
			}
		}
		p_list = increase_size(p_list);
	}
}

void menu(contact *p_list)
{
	bool exit = 0;
	int menu_option = 0;

	while (exit == 0)
	{
		std::cout << "\nSelect option: \n\t1. Update Friend \n\t2. Print List of Friends \n\t3. Exit.\n";
		std::cin >> menu_option;
		switch (menu_option)
		{
		case 1:
			p_list = update_friend(p_list);
			break;
		case 2:
			sort_list(p_list);
			print_list(p_list);
			break;
		case 3:
			exit = 1;
			break;
		default:
			break;
		}
	}

	return; // exiting
}

int main()
{
	contact *p_list = new contact[2];
	p_list[0].name = "Size";
	p_list[0].time = 2; // store information on the size of the pointer in the first entry
	p_list[1].name = "0";
	p_list[1].time = 0;

	menu(p_list);

	delete[] p_list;
	p_list = NULL;

	int exitprogram;
	std::cout << "\n\nExiting.";
	std::cin >> exitprogram;
	return 0;
}