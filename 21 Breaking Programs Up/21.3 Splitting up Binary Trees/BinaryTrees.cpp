#include "BinaryTrees.h"
#include <iostream>
#include <algorithm>

node* addNode(node* p_tree, int number)
{
	// Base case, when we have reached the end of the tree and have an empty node, add our value.
	if (p_tree == NULL)
	{
		node* p_new = new node;
		p_new->value = number;
		p_new->left = NULL;
		p_new->right = NULL;
		return p_new;
	}

	// Decide whether to go left or right. Left for smaller numbers, right for larger numbers. 
	if (number <= p_tree->value)
	{
		p_tree->left = addNode(p_tree->left, number);
	}
	else
	{
		p_tree->right = addNode(p_tree->right, number);
	}
	return p_tree;
}

node* findLeast(node* p_tree, int &smallest)
{
	if (p_tree->left == NULL)
	{
		smallest = p_tree->value;
		return p_tree->right;
	}
	else
	{
		p_tree->left = findLeast(p_tree->left, smallest);
	}
	return p_tree;
}
node* deleteNode(node* p_tree, int number)
{
	if (p_tree == NULL)
	{
		return p_tree;
	}

	if (p_tree->value == number)
	{
		// 3 CASES:

		// case 1: no children
		if (p_tree->left == NULL && p_tree->right == NULL)
		{
			return NULL;
		}
		// case 2: one child
		if (p_tree->left == NULL && p_tree->right != NULL)
		{
			return p_tree->right;
		}

		if (p_tree->left != NULL && p_tree->right == NULL)
		{
			return p_tree->left;
		}
		// case 3: two children

		else
		{
			int smallest = 0;
			// find the smallest number on the right hand side of the tree, we are going to replace the node we want to delete with that value, and then delete the node that contained the least value from the right side of the tree.
			// note this is guaranteed to be either a zero or one child case. 
			p_tree->right = findLeast(p_tree->right, smallest);
			p_tree->value = smallest;
			return p_tree;
		}
	}

	if (p_tree->value > number)
	{
		p_tree->left = deleteNode(p_tree->left, number);
	}
	else
	{
		p_tree->right = deleteNode(p_tree->right, number);
	}
	return p_tree;
}

void deleteTree(node* p_tree)
{
	if (p_tree != NULL)
	{
		deleteTree(p_tree->left);
		deleteTree(p_tree->right);
		delete p_tree;
	}
	return;
}

node* searchTree(node* p_tree, int number)
{
	if (p_tree == NULL)
	{
		return NULL;
	}

	if (p_tree->value == number)
	{
		return p_tree;
	}

	if (p_tree->value > number)
	{
		p_tree = searchTree(p_tree->left, number);
	}

	else
	{
		p_tree = searchTree(p_tree->right, number);
	}

	return p_tree;
}

void printTree(node* p_tree, int level)
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

	printTree(p_tree->left, level);
	printTree(p_tree->right, level);

	return;
}

void printTreeSorted(node* p_tree)
{
	if (p_tree == NULL)
	{
		return;
	}

	printTreeSorted(p_tree->left);
	std::cout << p_tree->value << "\n";
	printTreeSorted(p_tree->right);

	return;
}

void countNodes(node* p_tree, int &counter)
{
	if (p_tree == NULL)
	{
		return;
	}

	counter += 1;
	countNodes(p_tree->left, counter);
	countNodes(p_tree->right, counter);

	return;
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

int findMax(node* p_tree)
{
	if (p_tree == NULL)
	{
		return -1; // arbitrary number lower than anyhting we know to be in the list
	}
	// find the maximum out of: current node value, the max of the left branch, and the max of the right branch.
	int maxi = std::max(findMax(p_tree->left), findMax(p_tree->right));
	return std::max(p_tree->value, maxi);
}
int findMin(node* p_tree)
{
	if (p_tree == NULL)
	{
		return 1024; // arbitrary number higher than anything we know to be in the list
	}
	int mini = std::min(findMin(p_tree->left), findMin(p_tree->right));
	return std::min(p_tree->value, mini);
}
bool checkSorted(node* p_tree)
{
	// this function will return 1 for sorted and 0 for unsorted.

	if (p_tree == NULL)
	{
		return 1;
	}

	// Recurse checking left and right, and if we have already found one that is unsorted then ignore checking further nodes.
	// -- Assuming we only need to know if it is sorted or not. In practice if we were trying to fix the sorting, I think finding the first unsorted node is more important and then working down. This does it in reverse.
	if (checkSorted(p_tree->left) == 0 || checkSorted(p_tree->right) == 0)
	{
		return 0;
	}

	// Find the maximum value in the entire left branch, if it's greater than the current node then the tree must be unsorted
	if (findMax(p_tree->left) > p_tree->value)
	{
		std::cout << "Node with value " << p_tree->left->value << " is not correctly sorted.\n";
		return 0;
	}

	// do the same, this time the minimum value in the entire right branch.
	if (findMin(p_tree->right) <= p_tree->value)
	{
		std::cout << "Node with value " << p_tree->right->value << " is not correctly sorted.\n";
		return 0;
	}

	// otherwise if everything is fine
	return 1;
}