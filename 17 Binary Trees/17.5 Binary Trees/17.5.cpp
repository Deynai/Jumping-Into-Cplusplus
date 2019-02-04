#include <iostream>
#include <time.h>
#include "BinaryTreeUtility.h"

// 5. Write a program that deletes all of the nodes in a binary tree without using recursion.

void delete_node(node* p_tree)
{
	node* p_prev = p_tree;
	int direction = -1;

	// We are only going to delete leaves (nodes with no children), so we will loop through the tree updating our p_tree pointer to p_tree->left or p_tree->right until we find one.
	// We will also keep track of the previous node with a separate pointer p_prev, and the direction of the node we are deleting, so we can update p_prev->left or p_prev->right to point to NULL after it's deleted.
	while (p_tree->left != NULL || p_tree->right != NULL)
	{ 
		if (p_tree->left != NULL)
		{
			p_prev = p_tree;
			p_tree = p_tree->left;
			direction = 0;
		}

		if (p_tree->right != NULL)
		{
			p_prev = p_tree;
			p_tree = p_tree->right;
			direction = 1;
		}
	}
	// once ->left and ->right are NULL, we know we are at a leaf and can delete it.
	delete p_tree;

	// then depending on direction we update the previous node to no longer point to it.
	switch (direction)
	{
	case 0: p_prev->left = NULL;
		break;
	case 1: p_prev->right = NULL;
		break;
	default:
		break;
	}
	return;
}

node* create_tree(node* p_tree, int size) {
	for (size_t i = 0; i < size; i++)
	{
		p_tree = add_node(p_tree, rand() % 100);
	}
	return p_tree;
}

int main()
{
	srand(time(NULL));
	node* p_tree = NULL;
	int size = 10;

	p_tree = create_tree(p_tree, size);

	while (p_tree->left != NULL || p_tree->right != NULL)
	{
		delete_node(p_tree);
	}
	delete p_tree;

	std::cout << "\nTree Deleted!";

	int exitprogram;
	std::cout << "\nExiting.";
	std::cin >> exitprogram;
	return 0;
}