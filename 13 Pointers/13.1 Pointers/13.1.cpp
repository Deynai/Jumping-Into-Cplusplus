#include <iostream>
#include <string>

/* Write a function that prompts the user to enter his or her first name and last name, as two separate
values. This function should return both values to the caller via additional pointer(or reference)
parameters that are passed to the function. */

void get_name(std::string* first, std::string* last)
{
	std::cout << "Enter first name.\n";
	std::cin >> *first;
	std::cout << "Enter last name.\n";
	std::cin >> *last;
	return;
}

int main()
{
	std::string x;
	std::string y;
	std::string *p_x = &x;
	std::string *p_y = &y;

	get_name(p_x,p_y);

	std::cout << *p_x << " " << *p_y << "\n"; // print first and last names

	int exitprogram;
	std::cin >> exitprogram;
	return 0;
}
