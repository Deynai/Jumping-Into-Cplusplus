// 1. Implement a small address book program that allows users to enter names and email addresses, remove or change entries, and list the entries in their address book. Don’t worry about saving the address book to disk; it’s ok to lose the data when the program exits

#include <iostream>
#include <map>
#include <string>
#include <fstream>

void addContact(std::map<std::string, std::string> &address_book, std::string name, std::string address)
{
	address_book[name] = address;
	return;
}

void removeContact(std::map<std::string, std::string> &address_book)
{
	std::string name;
	std::cout << "\nEnter Name to Delete:\n";
	std::cin >> name;

	address_book.erase(name);
	return;
}

void findContact(std::map<std::string, std::string> address_book)
{
	std::string name;
	std::cout << "\nEnter Name to Find:\n";
	std::cin >> name;
	
	std::map<std::string, std::string>::iterator address = address_book.find(name);
	if (address != address_book.end())
	{
		std::cout << "\n" << address->first << " - " << address->second << "\n";
	}
	return;
}

void displayBook(std::map<std::string, std::string> address_book)
{
	for (std::map<std::string, std::string>::iterator i = address_book.begin(), end = address_book.end(); i != end; ++i)
	{
		std::cout << "\n" << i->first << " - " << i->second;
	}
	std::cout << "\n";
	return;
}

void saveBook(std::map<std::string, std::string> address_book)
{
	std::ofstream file;
	file.open("addressBook.txt");

	for (std::map<std::string, std::string>::iterator i = address_book.begin(), end = address_book.end(); i != end; ++i)
	{
		// save each entry in the map to a line of the form "name address" in a text file
		file << i->first << " " << i->second << "\n";
	}

	file.close();
	return;
}

std::map<std::string, std::string> loadBook()
{
	std::string input;
	std::map<std::string, std::string> address_book;

	std::ifstream file;
	file.open("addressBook.txt");
	if (file.is_open())
	{
		while (std::getline(file, input))
		{
			// substr(starting character, length)
			// let 'name' be the start of the line to the first space
			std::string name = input.substr(0, input.find(" "));
			// let 'address' be the character AFTER the first space to the end of the line
			std::string address = input.substr(input.find(" ") + 1, input.length() - input.find(" "));
			addContact(address_book, name, address);
		}
		file.close();
	}
	return address_book;
}

int main()
{
	// load address_book from file
	std::map<std::string, std::string> address_book = loadBook();

	bool exit = 0;
	int menu = 0;
	
	std::string name;
	std::string address;

	while (!exit)
	{
		std::cout << "\nMenu:\n1. Add Contact\n2. Remove Contact\n3. Update Contact\n4. Find Contact\n5. Display All Contacts\n6. Exit\n\n";
		std::cin >> menu;
		system("CLS");
		switch (menu)
		{
		case 1:	
			std::cout << "\nEnter Name:\n";
			std::cin >> name;
			std::cout << "\nEnter Address:\n";
			std::cin >> address;
			addContact(address_book, name, address);
			break;
		case 2: removeContact(address_book);
			break;
		case 3:		
			std::cout << "\nEnter Name:\n";
			std::cin >> name;
			std::cout << "\nEnter Address:\n";
			std::cin >> address;
			addContact(address_book, name, address);
			break;
		case 4: findContact(address_book);
			break;
		case 5: displayBook(address_book);
			break;
		case 6: 
			exit = 1;
			saveBook(address_book); // actually let's save it
			break;
		default:
			break;
		}
	}

	std::cout << "\nExiting.";
	std::cin >> exit;
	return 0;
}