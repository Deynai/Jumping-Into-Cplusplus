// Problem 4: Misreading and misreplaying a list

#include <iostream>
using namespace std;

struct Node
{
	int val;
	Node *p_next;
};
int main()
{
	int val;
	// Node *p_head;
	Node *p_head = NULL;
	while (1)
	{
		cout << "Enter a value, 0 to replay: " << endl;
		cin >> val;
		//if (val = 0)
		if (val == 0)
		{
			break;
		}

		Node *p_temp = new Node;

		//p_temp = p_head;
		p_temp->val = val;
		p_temp->p_next = p_head; //
		p_head = p_temp;
	}
	Node *p_itr = p_head;
	while (p_itr != NULL)
	{
		cout << p_itr->val << endl;
		p_head = p_itr; // 
		p_itr = p_itr->p_next;
		//delete p_itr;
		delete p_head;
	}

	int exit;
	std::cin >> exit;
	return 0;
}