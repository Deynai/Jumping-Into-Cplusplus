#include <iostream>

/*
3. Write a recursive algorithm to remove elements from a linked list. Write a recursive algorithm to
add elements into a linked list. Try writing the same algorithms using iteration. Do the recursive
implementations or the iterative implementations feel more natural?
*/

struct node
{
	int num;
	node* p_next;
};

// add num elements (1 to num) to list recursively
node* addRecursion(node* list, int num)
{
	node* newNode = new node;
	newNode->num = num;

	if (num == 1)
	{
		newNode->p_next = list; 
		return newNode;
	}

	newNode->p_next = addRecursion(list, num - 1);;
	return newNode;
}

// remove all elements and free memory from list recursively
node* removeRecursion(node* list)
{
	if (list->p_next != NULL) 
	{
		removeRecursion(list->p_next); // base case = 1 node left and the only one to be deleted
	}
	delete list;
	list = NULL;
	return list;
}

// add num elements (1 to num) to list iteratively
node* addIterative(node* list, int num)
{
	for (size_t i = 1; i < num+1; i++)
	{
		node* newNode = new node;
		newNode->num = i;
		newNode->p_next = list;
		list = newNode;
	}
	return list;
}

// remove all elements and free memory from list iteratively
node* removeIterative(node* list)
{
	node* currentNode = list;

	while (list != NULL)
	{
		currentNode = list->p_next;
		delete list;
		list = currentNode;
	}
	return list;
}

// print list to keep track of what's in list
void printList(node* list)
{
	if (list == NULL)
	{
		return;
	}
	else
	{
		std::cout << "\n" << list->num;
		printList(list->p_next);
		return;
	}
}

int main()
{
	int menu;
	bool exit = 0;
	int num = 0;
	node* list = NULL;


	std::cout << "Choose option:\n\t1. Add Recursion\n\t2. Remove Recursion\n\t3. Add Iterative\n\t4. Remove Iterative\n\t5. Print List";
	while (exit == 0)
	{
		std::cout << "\n";
		std::cin >> menu;
		switch (menu)
		{
		case 1:
			std::cout << "\nChoose number to add: ";
			std::cin >> num;
			list = addRecursion(list, num);
			break;
		case 2:
			list = removeRecursion(list);
			break;
		case 3:
			std::cout << "\nChoose number to add: ";
			std::cin >> num;
			list = addIterative(list, num);
			break;
		case 4:
			list = removeIterative(list);
			break;
		case 5:
			printList(list);
		default:
			break;
		}
	}

	int exitprogram;
	std::cout << "\nExiting.";
	std::cin >> exitprogram;
	return 0;
}