namespace rowan {

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
		linkedList * _p_head;
		linkedList *_p_tail;
		int _currentSize;
		void generateLinkedList();
	};

}