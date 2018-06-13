#include <iostream>
#include <time.h>

/*
2. Write a program that adds elements to a linked list in sorted order, rather than at the beginning.
*/

struct linky
{
	int num;
	linky* p_next;
};

linky* addNumber(linky* p_numbers, int number)
{
	linky *p_currentLinky = p_numbers;
	linky *p_previousLinky = NULL;

	while (true)
	{
		if (p_currentLinky == NULL || p_currentLinky->num >= number) // if we have reached the end of the list without finding any link larger than our number, or if the following link is larger, then our number must be placed here
		{
			linky* p_newLink = new linky;
			p_newLink->num = number;

			if (p_previousLinky != NULL) // if we didn't insert our new number at the front of the list we need to connect the previous and following links
			{
				p_newLink->p_next = p_previousLinky->p_next;
				p_previousLinky->p_next = p_newLink;
				return p_numbers;
			}
			else // if we inserted our new number at the front of the list
			{
				p_newLink->p_next = p_numbers;
				return p_newLink;
			}
		}
		p_previousLinky = p_currentLinky;
		p_currentLinky = p_currentLinky->p_next;
	}
}

linky* addRandom(linky* p_numbers)
{
	int number;
	for (size_t i = 0; i < 5; i++)
	{
		number = rand() % 10000;
		p_numbers = addNumber(p_numbers, number);
	}
	return p_numbers;
}

void printNumbers(linky* p_numbers)
{
	linky* p_currentlinky = p_numbers;

	while (p_currentlinky != NULL)
	{
		std::cout << "\n\t" << p_currentlinky->num;
		p_currentlinky = p_currentlinky->p_next;
	}
	return;
}

int main()
{
	int menu = 0;
	bool exit = 0;
	linky* p_numbers = NULL;
	srand(time(NULL));

	while (exit == 0)
	{
		std::cout << "\nChoose option:\n\t1. Add Number\n\t2. Print Numbers\n\t3. Add 5 random numbers\n\t4. Exit";
		std::cin >> menu;
		switch (menu)
		{
		case 1:
			int number;
			std::cout << "\nEnter number:\n";
			std::cin >> number;
			p_numbers = addNumber(p_numbers, number);
			break;
		case 2:
			printNumbers(p_numbers);
			break;
		case 3:
			p_numbers = addRandom(p_numbers); // for easier testing mainly
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