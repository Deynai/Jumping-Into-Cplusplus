/*
2. Provide another implementation of your sort function, this time taking an interface called
Comparator, which has a method compare(const string& lhs, const string& rhs)
that follows similar rules to the previous compare method: return 0 if the two value are the
same, 1 if lhs > rhs or -1 if lhs < rhs. Write two different classes to do comparison: one
that does a case-insensitive comparison and one that sorts in reverse alphabetical order.
*/

#include <iostream>
#include "Comparator.h"
#include <vector>

void sort(std::vector<std::string> &list, Comparator* Sorter)
{
	Sorter->sort(list);
}

void printList(std::vector<std::string> list)
{
	for (std::vector<std::string>::iterator itr = list.begin(), end = list.end(); itr != end; ++itr)
	{
		std::cout << *itr << "\n";
	}
	return;
}

int main()
{
	std::vector<std::string> list;
	// populate our list with some arbitrary values so we can follow what's going on
	list.push_back("aAa");
	list.push_back("aAA");
	list.push_back("Aaa");
	list.push_back("bB");
	list.push_back("Bb");
	list.push_back("BB");
	list.push_back("AAa");
	list.push_back("AAA");
	list.push_back("b");
	list.push_back("B");
	list.push_back("A");

	std::cout << "Unsorted\n";
	printList(list);

	std::cout << "Case Insensitive Sort\n";
	Comparator *sorter = new CaseInsensitiveSort;
	sort(list, sorter);
	delete sorter;
	printList(list);

	std::cout << "Inverse Sort\n";
	sorter = new InverseSort;
	sort(list, sorter);
	delete sorter;
	printList(list);

	int exit;
	std::cin >> exit;
	return 0;
} 