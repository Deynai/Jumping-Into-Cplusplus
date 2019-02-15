#include "BinaryTrees.h"
#include <time.h>
#include <stdlib.h>
#include <iostream>

node* createTree(node* p_tree, int &size)
{
	for (int i = 0; i < size; i++)
	{
		p_tree = addNode(p_tree, rand() % 100);
	}
	return p_tree;
}

int main()
{
	srand(time(NULL));
	node* p_tree = NULL;
	int size = 10;

	p_tree = createTree(p_tree, size);

	bool is_balanced = 1;
	int level = 0;
	checkBalance(p_tree, level, is_balanced);
	std::cout << "Check Balance: " << is_balanced;

	std::cout << "\nCheck sorted: " << checkSorted(p_tree);

	int counted_nodes = 0;
	countNodes(p_tree, counted_nodes);
	std::cout << "\nCount Nodes: " << counted_nodes;

	std::cout << "\n\n";
	printTree(p_tree, 0);

	for (size_t i = 0; i < 5; i++)
	{
		deleteNode(p_tree, findMax(p_tree));
	}

	counted_nodes = 0;
	countNodes(p_tree, counted_nodes);
	std::cout << "\n\n\nCount Nodes after delete 5: " << counted_nodes;

	std::cout << "\n\n";
	printTree(p_tree, 0);

	deleteTree(p_tree);

	std::cin >> size;
	return 0;
}