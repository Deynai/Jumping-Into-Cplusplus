#include <iostream>
#include <string>

/* 
3. Modify the program you wrote for exercise 1 so that instead of always prompting the user for a last
name, it does so only if the caller passes in a NULL pointer for the last name. 
*/

void get_name(std::string* first, std::string* last)
{
	std::cout << "Enter first name.\n";
	std::cin >> *first;
	if (last == NULL) // only prompt for a last name if the passed last name pointer is NULL, this makes no sense in this context in my opinion but I can see other uses for it.
	{
		std::cout << "Enter last name.\n\n";
		std::cin >> *last;
	}
	return;
}

int main()
{
	std::string x;
	std::string y;
	std::string *p_x = &x;
	std::string *p_y = &y;

	get_name(p_x, p_y);
	
	std::cout << *p_x << " " << *p_y << "\n\n"; // print first and last names 

	p_y = NULL; // set the last name pointer to NULL

	get_name(p_x, p_y);

	std::cout << *p_x << " " << *p_y << "\n\n"; // print first and last names

	int exitprogram;
	std::cin >> exitprogram;
	return 0;
}
