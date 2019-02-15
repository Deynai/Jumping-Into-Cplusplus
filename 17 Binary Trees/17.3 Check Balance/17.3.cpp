#include <iostream>
#include <time.h>
#include "BinaryTreeUtility.h"

// Write a program that checks whether a binary tree is properly balanced.

node* create_tree(node* p_tree, int size)
{
	for (size_t i = 0; i < size; i++)
	{
		p_tree = add_node(p_tree, rand() % 100);
	}
	return p_tree;
}

void findLastLevel(node* p_tree, int current_level, int &max_level)
{
	// base case
	if (p_tree == NULL)
	{
		return;
	}

	// update max_level based on how far down the tree we are, note we don't want to overwrite this if we already found a deeper branch
	if (current_level > max_level)
	{
		max_level = current_level;
	}

	// continue digging
	findLastLevel(p_tree->left, current_level + 1, max_level);
	findLastLevel(p_tree->right, current_level + 1, max_level);
}

void checkBalance(node* p_tree, int level, bool &is_balanced)
{
	// base case
	if (p_tree == NULL)
	{
		return;
	}

	// reset our max variables to the current level
	int max_level_left = level;
	int max_level_right = level;

	// find how deep our left and right branches go, and hand our max_level back.
	findLastLevel(p_tree->left, level + 1, max_level_left);
	findLastLevel(p_tree->right, level + 1, max_level_right);

	// find the difference between our left and right branches, if it's 2 or more then the tree is imbalanced
	if (abs(max_level_left - max_level_right) >= 2)
	{
		is_balanced = 0;
		// we can also stop looking further
		return;
	}

	// recurse by checking the balance starting from the left and right nodes.
	checkBalance(p_tree->left, level + 1, is_balanced);
	checkBalance(p_tree->right, level + 1, is_balanced);

	return;
}


int main()
{
	srand(time(NULL));
	node* p_tree = NULL;
	int size = 10;
	int balance_counter = 0;

//	for (size_t i = 0; i < 10000; i++)
//	{
//		p_tree = NULL;
		bool is_balanced = 1;

		p_tree = create_tree(p_tree, size);
		checkBalance(p_tree, 0, is_balanced);

		switch (is_balanced)
		{
		case 0: std::cout << "Tree is imbalanced!\n";
			break;
		default: std::cout << "Tree is balanced!\n";
//			balance_counter += 1;
			break;
		}

		wipe_tree(p_tree);
		
//	}

//	std::cout << "Number of balanced trees of size " << size << " out of 10000: " << balance_counter << "\n";

	int exitprogram;
	std::cout << "Exiting.\n";
	std::cin >> exitprogram;
	return 0;
}