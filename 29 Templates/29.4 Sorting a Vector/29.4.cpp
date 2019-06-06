/*
4. Implement a sort function that takes a vector of any type and sorts the values by their natural
sort order (the order you get from using < or >).
*/

#include <iostream>
#include <vector>
#include <string>
#include <cmath>

template<typename T>
void sorter(std::vector<T> *vec)
{
	bool sorted = 0;
	T temp;

	while (sorted == 0)
	{
		sorted = 1;
		for (typename std::vector<T>::iterator itr = vec->begin(), end = vec->end(); itr+1 != end ; ++itr)
		{
			if (*itr > *(itr+1))
			{
				temp = *itr;
				*itr = *(itr + 1);
				*(itr + 1) = temp;
				sorted = 0;
			}
		}
	}

	return;
}

template<typename T>
void printVec(std::vector<T> *vec)
{
	for (typename std::vector<T>::iterator itr = vec->begin(), end = vec->end(); itr != end; ++itr)
	{
		std::cout << *itr << " ";
	}

	std::cout << "\n";
	return;
}

int main()
{
	std::vector<int> vec1;
	std::vector<std::string> vec2;

	for (int i = 0; i < 10; i++)
	{
		vec1.push_back(pow(-i, i));

	}

	vec2.push_back("abcdefgh"), vec2.push_back("hello"), vec2.push_back("testing"), vec2.push_back("abcabc"), vec2.push_back("aaaaa"), vec2.push_back("bbbbb"), vec2.push_back("ccccc"), vec2.push_back("aabbc");

	printVec(&vec1);
	sorter(&vec1);
	sorter(&vec2);
	printVec(&vec1);
	printVec(&vec2);

	int exit;
	std::cin >> exit;
	return exit;
}
