#pragma once

struct node
{
	int value;
	node* left;
	node* right;
};

// add a node to the tree with given int value
node* addNode(node* p_tree, int number);

// delete a node with the given int value
node* findLeast(node* p_tree, int &smallest); 
node* deleteNode(node* p_tree, int number);

// delete the entire tree from memory
void deleteTree(node* p_tree);

// return a pointer to the node with value of given int
node* searchTree(node* p_tree, int number);

// graphically display an entire tree
void printTree(node* p_tree, int level); // we should be able to make this look prettier

// print the values stored in the tree from lowest to highest
void printTreeSorted(node* p_tree);

// count the total number of nodes, needs a counter = 0 initialised when first called
void countNodes(node* p_tree, int &counter); // need to remove &counter, this should count the nodes of a given tree without having to pass a variable to store the counting

// will check if the tree is efficiently balanced, needs a is_balanced = 1 initalised when first called
void findLastLevel(node* p_tree, int current_level, int &max_level);
void checkBalance(node* p_tree, int level, bool &is_balanced); // findLastLevel and checkBalance definitely need improvement, should not be needing to pass is_balanced or max_level through every recursion

// will check if the nodes are properly sorted (only smaller values to the left, only larger values to the right, for every node)
int findMax(node* p_tree);
int findMin(node* p_tree);
bool checkSorted(node* p_tree);