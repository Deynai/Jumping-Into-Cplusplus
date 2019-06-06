#pragma once
#include <stdlib.h>

template <typename K>
class linkedList
	{
	public:
		~linkedList();
		K key;
		linkedList<K> *p_next; // linkedlist now requires a type
	};

template <typename T>
class vectorOfT
	{
	public:
		vectorOfT();
		vectorOfT(const int size);
		~vectorOfT();
		vectorOfT& operator= (const vectorOfT &other);
		vectorOfT(const vectorOfT &other);

		T get(const int index); // should return T
		void set(const int index, const T value); // should take const int index and const T value
		void pushback(const T value); // should take const T value
		void pushfront(const T value); // should take const T value
		int size();

	private:
		linkedList<T> * _p_head; // linkedlist now requires a type
		linkedList<T> *_p_tail;
		int _currentSize;
		void generateLinkedList();
	};

/// Since this is now a template class we cannot have a separate .cpp with definitions, all templates must be defined here.

// Constructors, Destructors, Assignment 

template<typename T> vectorOfT<T>::vectorOfT()
	: _currentSize(32)
{
	generateLinkedList();
}

template<typename T> vectorOfT<T>::vectorOfT(const int size)
	: _currentSize(size)
{
	// for invalid size inputs, default to 32
	if (size < 1)
	{
		_currentSize = 32;
	}

	generateLinkedList();
}

template<typename T> vectorOfT<T>::vectorOfT(const vectorOfT &other)
	: _currentSize(0)
	, _p_head(NULL)
	, _p_tail(NULL)
{
	linkedList<T> *p_itr = other._p_head;
	for (int i = 0; i < other._currentSize; i++)
	{
		this->pushback(p_itr->key);
		p_itr = p_itr->p_next;
	}
}

template<typename K> linkedList<K>::~linkedList()
{
	delete p_next;
}

template<typename T> vectorOfT<T>::~vectorOfT()
{
	delete _p_head;
}

template<typename T> vectorOfT<T> &vectorOfT<T>::operator= (const vectorOfT &other)
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

	linkedList<T> *p_itr = other._p_head;
	for (int i = 0; i < other._currentSize; i++)
	{
		this->pushback(p_itr->key);
		p_itr = p_itr->p_next;
	}
	return *this;
}

// Member Functions

template<typename T> T vectorOfT<T>::get(const int index)
{
	// reject attempts to access invalid index
	if (index < 0 || index > _currentSize)
	{
		// Error? 
		//return -31212012;
		return NULL;
	}

	linkedList<T> *p_itr = _p_head;
	for (int i = 0; i < index; i++)
	{
		p_itr = p_itr->p_next;
	}

	return p_itr->key;
}

template<typename T> void vectorOfT<T>::set(const int index, const T value)
{
	// reject attempts to access invalid index
	if (index < 0 || index > _currentSize)
	{
		return;
	}

	linkedList<T> *p_itr = _p_head;
	for (int i = 0; i < index; i++)
	{
		p_itr = p_itr->p_next;
	}

	p_itr->key = value;
	return;
}

template<typename T> void vectorOfT<T>::pushback(const T value)
{
	// need to create a node and set head and tail to it in the NULL case
	if (_p_head == NULL)
	{
		linkedList<T> *p_temp = new linkedList<T>;
		p_temp->key = value;
		p_temp->p_next = NULL;
		_p_head = p_temp;
		_p_tail = p_temp;
		_currentSize += 1;
		return;
	}

	// add a node on the end and adjust the tail pointer
	linkedList<T> *p_temp = new linkedList<T>;
	p_temp->key = value;
	p_temp->p_next = NULL;
	_p_tail->p_next = p_temp;
	_p_tail = p_temp;

	_currentSize += 1;
	return;
}

template<typename T> void vectorOfT<T>::pushfront(const T value)
{
	// same NULL case as pushback, could put this in a function of its own if we were to repeat it more than twice
	if (_p_head == NULL)
	{
		linkedList<T> *p_temp = new linkedList<T>;
		p_temp->key = value;
		p_temp->p_next = NULL;
		_p_head = p_temp;
		_p_tail = p_temp;
		_currentSize += 1;
		return;
	}

	// add a node on the front and adjust the head pointer
	linkedList<T> *p_temp = new linkedList<T>;
	p_temp->key = value;
	p_temp->p_next = _p_head;
	_p_head = p_temp;

	_currentSize += 1;
	return;
}

template<typename T> int vectorOfT<T>::size()
{
	return _currentSize;
}

// Helpers

template<typename T> void vectorOfT<T>::generateLinkedList() // creates an uninitialised linkedlist of size _currentSize, effectively an uninitialised array
{
	linkedList<T> *p_new = new linkedList<T>;
	p_new->p_next = NULL;
	_p_head = p_new;
	_p_tail = p_new;

	for (int i = 0; i < _currentSize - 1; i++)
	{
		linkedList<T> *p_temp = new linkedList<T>;
		p_temp->p_next = NULL;
		_p_tail->p_next = p_temp;
		_p_tail = p_temp;
	}
	return;
}
