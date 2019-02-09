#include <iostream>
#include <time.h>
#include <string>

/* 6. Implement a simple map, in the form of a binary tree, that holds an address book; the key for the map should be a person's name and the value should be the person's email address.
You should provide the ability to:
* add email addresses to the map
* remove email addresses
* update email addresses
* find email addresses.
* clean up your address book when your program shuts down.

*/

struct node {
	std::string name;
	std::string address;
	node* left;
	node* right;
};

node* add_address(node* p_book, std::string name, std::string address) {
	if (p_book == NULL)
	{
		node* p_new = new node;
		p_new->name = name;
		p_new->address = address;
		p_new->left = NULL;
		p_new->right = NULL;
		p_book = p_new;
		return p_book;
	}

	if (p_book->name >= name)
	{
		p_book->left = add_address(p_book->left, name, address);
	}
	else
	{
		p_book->right = add_address(p_book->right, name, address);
	}
	return p_book;
}

node* find_least(node* p_book, node &smallest)
{
	// if p_book->left == NULL then we must be at the node with the lowest key value. so let's save the name and address in our "smallest" node, create a temporary pointer to attach the previous node to anything in the right branch (it may be NULL)
	if (p_book->left == NULL)
	{
		// let's create a temporary pointer to attach the previous node to anything in the right branch (it may be NULL)
		node* p_temp = p_book->right;
		// save the name and address in our "smallest" node so we can overwrite the values in the node we are deleting
		smallest.name = p_book->name;
		smallest.address = p_book->address;
		// delete the node we have taken the name and address from (like Ctrl+X Cut)
		delete p_book;
		// and return the temporary right branch pointer to the previous node (which may be NULL)
		return p_temp;
	}
	else
	{
		// if there's a node to the left, then it must be smaller than our current node. 
		p_book->left = find_least(p_book->left, smallest);
	}
	return p_book;
}

node* remove_address(node* p_book, std::string name) {
	
	if (p_book == NULL)
	{
		return NULL;
	}

	if (p_book->name == name)
	{
		// 3 CASES:
		std::cout << "Deleted " << name;
		// case 1: no children
		if (p_book->left == NULL && p_book->right == NULL)
		{
			return NULL;
		}
		// case 2: one child
		if (p_book->left == NULL && p_book->right != NULL)
		{
			node* p_book_right = p_book->right;
			delete p_book;
			return p_book_right;
		}

		if (p_book->left != NULL && p_book->right == NULL)
		{
			node* p_book_left = p_book->left;
			delete p_book;
			return p_book->left;
		}
		// case 3: two children

		else
		{
			node smallest;
			// find the smallest name in the right branch of the node, we are going to replace the node we want to delete with that name+address, and then delete the node that contained the smallest name from the right branch.
			// note this is guaranteed to be either a zero or one child case. 
			p_book->right = find_least(p_book->right, smallest);
			p_book->name = smallest.name;
			p_book->address = smallest.address;
			return p_book;
		}
	}

	// search the tree for the name we are deleting
	if (p_book->name >= name)
	{
		p_book->left = remove_address(p_book->left, name);
	}
	else
	{
		p_book->right = remove_address(p_book->right, name);
	}

	return p_book;
}

node* find_address(node* p_book, std::string name) {

	if (p_book == NULL)
	{
		return NULL;
	}
	// if we find the name, return the node it's at
	if (p_book->name == name)
	{
		return p_book;
	}
	// search the tree
	if (p_book->name > name)
	{
		p_book = find_address(p_book->left, name);
	}
	else
	{
		p_book = find_address(p_book->right, name);
	}

	return p_book;
}

node* update_address(node* p_book, std::string name, std::string address) {
	// we already have a function for finding the node of a given name, so let's just use that 
	p_book = find_address(p_book, name);
	
	if (p_book != NULL)
	{
		p_book->address = address;
	}

	return p_book;
}

void clear_book(node* p_book) {
	if (p_book != NULL)
	{
		clear_book(p_book->left);
		clear_book(p_book->right);
		delete p_book;
	}
	return;
}

int main()
{
	int menu = 0;
	node* p_book = NULL;
	node* p_temp = NULL;
	int exit = 0;
	std::string temp_name = "";
	std::string temp_address = "";

	while (!exit)
	{
		std::cout << "\n\nMenu:\n1. Add Address\n2. Remove Address\n3. Update Address\n4. Find Address\n5. Exit.";
		std::cin >> menu;
		switch (menu)
		{
		case 1: // Add Address
			std::cout << "\nEnter Name:\n";
			std::cin >> temp_name;
			std::cout << "\nEnter Address:\n";
			std::cin >> temp_address;
			p_book = add_address(p_book, temp_name, temp_address);
			break;
		case 2: // Remove Address
			std::cout << "\nEnter Name:\n";
			std::cin >> temp_name;
			p_book = remove_address(p_book, temp_name);
			break;
		case 3: // Update Address
			std::cout << "\nEnter Name:\n";
			std::cin >> temp_name;
			std::cout << "\nEnter Address:\n";
			std::cin >> temp_address;
			update_address(p_book, temp_name, temp_address);
			break;
		case 4: // Find Address
			std::cout << "\nEnter Name:\n";
			std::cin >> temp_name;
			p_temp = find_address(p_book, temp_name);
			if (p_temp != NULL)
			{
				std::cout << "Found " << p_temp->name << " with address: " << p_temp->address;
			}
			else
			{
				std::cout << "Could not find anyone with name: " << temp_name;
			}
			break;
		case 5: // Exit
			clear_book(p_book);
			delete p_temp;
			exit = 1;
			break;
		default:
			break;
		}
	}

	std::cout << "\nExiting.";
	std::cin >> exit;
	return 0;
}