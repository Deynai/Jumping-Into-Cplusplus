/*
1. Implement a vector replacement that operates only on integers, vectorOfInt (you don't need to
use templates like the normal STL). Your class should have the following interface:
• A no-argument constructor that allocates a 32 element vector
• A constructor that takes an initial size as the argument
• A method get, taking an index as returning the value at that index
• A method set, that takes an index and a value, and sets the value at that index
• A method pushback that adds an element to the end of the array, resizing if necessary
• A method pushfront that adds an element to the beginning of the array
• A Copy constructor and assignment operator
Your class should not leak memory; any memory it allocates must be deleted. Try to think carefully
about how your class can be misused, and how you should handle them. What do you do if a user gives
a negative initial size? What about accessing a negative index?
*/

#pragma once
class linkedList
{
public:
	~linkedList();
	int key;
	linkedList *p_next;
};

class vectorOfInt
{
public:
	vectorOfInt();
	vectorOfInt(const int size);
	~vectorOfInt();
	vectorOfInt& operator= (const vectorOfInt &other);
	vectorOfInt(const vectorOfInt &other);

	int get(const int index);
	void set(const int index, const int number);
	void pushback(const int number);
	void pushfront(const int number);
	int size();

private:
	linkedList *_p_head;
	linkedList *_p_tail;
	int _currentSize;
	void generateLinkedList();
};


