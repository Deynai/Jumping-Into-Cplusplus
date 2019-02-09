#include <iostream>
#include "BinaryTreeUtility.h"
#include <algorithm>
#include <time.h>

// 4. Write a program that checks if the binary tree is properly sorted so that all nodes to the left of a given node are less than the value of that node, and all nodes to the right are greater than the value of that node.

int find_max(node* p_tree)
{
	if (p_tree == NULL)
	{
		return -1; // arbitrary number lower than anyhting we know to be in the list
	}
	// find the maximum out of: current node value, the max of the left branch, and the max of the right branch.
	int maxi = std::max(find_max(p_tree->left), find_max(p_tree->right));
	return std::max(p_tree->value, maxi);
}

int find_min(node* p_tree)
{
	if (p_tree == NULL)
	{
		return 1024; // arbitrary number higher than anything we know to be in the list
	}
	int mini = std::min(find_min(p_tree->left), find_min(p_tree->right));
	return std::min(p_tree->value, mini);
}

bool check_node(node* p_tree)
{
	// this function will return 1 for sorted and 0 for unsorted.

	if (p_tree == NULL)
	{
		return 1;
	}

	// Recurse checking left and right, and if we have already found one that is unsorted then ignore checking further nodes.
	// -- Assuming we only need to know if it is sorted or not. In practice if we were trying to fix the sorting, I think finding the first unsorted node is more important and then working down. This does it in reverse.
	if (check_node(p_tree->left) == 0 || check_node(p_tree->right) == 0)
	{
		return 0;
	}

	// Find the maximum value in the entire left branch, if it's greater than the current node then the tree must be unsorted
	if (find_max(p_tree->left) > p_tree->value)
	{
		std::cout << "Node with value " << p_tree->left->value << " is not correctly sorted.\n";
		return 0;
	}

	// do the same, this time the minimum value in the entire right branch.
	if (find_min(p_tree->right) <= p_tree->value)
	{
		std::cout << "Node with value " << p_tree->right->value << " is not correctly sorted.\n";
		return 0;
	}

	// otherwise if everything is fine
	return 1;
}

node* create_unsorted(node* p_tree)
{
	// make the first node->value = 50 and node->left->value = 60
	node* p_new = new node;
	node* p_new2 = new node;
	p_new->value = 50;
	p_new->left = p_new2;
	p_new->right = NULL;
	p_tree = p_new;

	p_new2->value = 60;
	p_new2->left = NULL;
	p_new2->right = NULL;
	return p_tree;
}

node* create_tree(node* p_tree, int size)
{
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
	int size = 1040;

	// "Manually" create an unsorted tree

	//p_tree = create_unsorted(p_tree);

	p_tree = create_tree(p_tree, size);

	if (!check_node(p_tree))
	{
		std::cout << "Tree is not sorted correctly.";
	}
	else
	{
		std::cout << "Tree is sorted correctly.";
	}

	int exitprogram;
	std::cout << "\nExiting.\n";
	std::cin >> exitprogram;
	return 0;
}