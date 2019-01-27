#include <iostream>
#include <time.h>
#include "BinaryTreeUtility.h"


node* CreateTree(node* p_tree, int size)
{
	for (int i = 0; i < size; i++)
	{
		p_tree = add_node(p_tree, rand() % 100);
	}
	return p_tree;
}

void print_tree(node* p_tree, int level)
{
	level += 1;

	for (size_t i = 0; i < level - 1; i++)
	{
		std::cout << "\t";
	}

	if (p_tree == NULL)		
	{
		std::cout << "\\\n";
		return;
	}

	std::cout << "\\-- " << p_tree->value << "\n";

	print_tree(p_tree->left, level);
	print_tree(p_tree->right, level);

	return;
}

void print_tree_sorted(node* p_tree)
{
	if (p_tree == NULL)
	{
		return;
	}

	print_tree_sorted(p_tree->left);
	std::cout << p_tree->value << "\n";
	print_tree_sorted(p_tree->right);

	return;
}

void print_tree_sorted_invert(node* p_tree)
{
	if (p_tree == NULL)
	{
		return;
	}

	print_tree_sorted_invert(p_tree->right);
	std::cout << p_tree->value << "\n";
	print_tree_sorted_invert(p_tree->left);

	return;
}

int main()
{
	srand(time(NULL));

	node* p_tree = NULL; // Initialise Tree.
	int size = 10; // Size of Tree
	
	p_tree = CreateTree(p_tree, size);

	int tree_level = 0;

	// print tree positioning
	print_tree(p_tree, tree_level);

	// print in ascending order
	print_tree_sorted(p_tree);

	std::cout << "\n\n";

	// print in descending order
	print_tree_sorted_invert(p_tree);


	int exitprogram;
	std::cout << "\nExiting.";
	std::cin >> exitprogram;
	return 0;
}


