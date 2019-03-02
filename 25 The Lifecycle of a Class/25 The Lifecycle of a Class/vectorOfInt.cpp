#include "vectorOfInt.h"
#include <stdlib.h>

// Constructors, Destructors, Assignment

vectorOfInt::vectorOfInt()
	: _currentSize(32)
{
	generateLinkedList();
}

vectorOfInt::vectorOfInt(const int size)
	: _currentSize(size)
{
	// for invalid size inputs, default to 32
	if (size < 1)
	{
		_currentSize = 32;
	}

	generateLinkedList();
}

vectorOfInt::vectorOfInt(const vectorOfInt &other)
	: _currentSize(0)
	, _p_head(NULL)
	, _p_tail(NULL)
{
	linkedList *p_itr = other._p_head;
	for (int i = 0; i < other._currentSize; i++)
	{
		this->pushback(p_itr->key);
		p_itr = p_itr->p_next;
	}
}

linkedList::~linkedList()
{
	delete p_next;
}

vectorOfInt::~vectorOfInt()
{
	delete _p_head;
}

vectorOfInt &vectorOfInt::operator= (const vectorOfInt &other)
{
	if (this == &other)
	{
		return *this;
	}

	// deletes whatever we had stored in this previously and sets the size to 0. this->pushback will count the size again, though really we could just let _currentSize = other._currentSize at the end. This is all very similar to the copy constructor.
	// delete _p_head, like our destructor, will recursively delete every element.
	delete _p_head;
	_currentSize = 0;
	_p_head = NULL;
	_p_tail = NULL;

	linkedList *p_itr = other._p_head;
	for (int i = 0; i < other._currentSize; i++)
	{
		this->pushback(p_itr->key);
		p_itr = p_itr->p_next;
	}
	return *this;
}

// Member Functions

int vectorOfInt::get(const int index)
{
	// reject attempts to access invalid index
	if (index < 0 || index > _currentSize)
	{
		// Error? 
		return -31212012;
	}

	linkedList *p_itr = _p_head;
	for (int i = 0; i < index; i++)
	{
		p_itr = p_itr->p_next;
	}

	return p_itr->key;
}

void vectorOfInt::set(const int index, const int number)
{
	// reject attempts to access invalid index
	if (index < 0 || index > _currentSize)
	{
		return;
	}

	linkedList *p_itr = _p_head;
	for (int i = 0; i < index; i++)
	{
		p_itr = p_itr->p_next;
	}
	
	p_itr->key = number;
	return;
}

void vectorOfInt::pushback(const int number)
{
	// need to create a node and set head and tail to it in the NULL case
	if (_p_head == NULL)
	{
		linkedList *p_temp = new linkedList;
		p_temp->key = number;
		p_temp->p_next = NULL;
		_p_head = p_temp;
		_p_tail = p_temp;
		_currentSize += 1;
		return;
	}

	// add a node on the end and adjust the tail pointer
	linkedList *p_temp = new linkedList;
	p_temp->key = number;
	p_temp->p_next = NULL;
	_p_tail->p_next = p_temp;
	_p_tail = p_temp;

	_currentSize += 1;
	return;
}

void vectorOfInt::pushfront(const int number)
{
	// same NULL case as pushback, could put this in a function of its own if we were to repeat it more than twice
	if (_p_head == NULL)
	{
		linkedList *p_temp = new linkedList;
		p_temp->key = number;
		p_temp->p_next = NULL;
		_p_head = p_temp;
		_p_tail = p_temp;
		_currentSize += 1;
		return;
	}

	// add a node on the front and adjust the head pointer
	linkedList *p_temp = new linkedList;
	p_temp->key = number;
	p_temp->p_next = _p_head;
	_p_head = p_temp;

	_currentSize += 1;
	return;
}

int vectorOfInt::size()
{
	return _currentSize;
}

// Helpers

void vectorOfInt::generateLinkedList() // creates an uninitialised linkedlist of size _currentSize, effectively an uninitialised array
{
	linkedList *p_new = new linkedList;
	p_new->p_next = NULL;
	_p_head = p_new;
	_p_tail = p_new;

	for (int i = 0; i < _currentSize - 1; i++)
	{
		linkedList *p_temp = new linkedList;
		p_temp->p_next = NULL;
		_p_tail->p_next = p_temp;
		_p_tail = p_temp;
	}
	return;
}