#include <iostream>
#include <time.h>
#include "BinaryTreeUtility.h"

node* create_tree(node* p_tree, int size)
{
	for (size_t i = 0; i < size; i++)
	{
		p_tree = add_node(p_tree, rand()%100);
	}
	return p_tree;
}

void count_nodes(node* p_tree, int &counter)
{
	if (p_tree == NULL)
	{
		return;
	}

	counter += 1;
	count_nodes(p_tree->left, counter);
	count_nodes(p_tree->right, counter);
	
	return;
}

int main()
{
	srand(time(NULL));
	node* p_tree = NULL;
	int size = 300;
	int counter = 0;

	p_tree = create_tree(p_tree, size);
	count_nodes(p_tree, counter);

	std::cout << "Number of nodes counter: " << counter << "\n";

	int exitprogram;
	std::cout << "\nExiting.";
	std::cin >> exitprogram;
	return 0;
}



