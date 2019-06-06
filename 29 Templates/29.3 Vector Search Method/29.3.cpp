/*
3. Write a search method that takes a vector, of any type, and a value, of any type, and returns
true if the value is in the vector, or false if it is not.
*/


#include <iostream>
#include <vector>
#include <string>

template<typename T>
bool exists(std::vector<T> vec, T value)
{
	for (typename std::vector<T>::iterator itr = vec.begin(), end = vec.end(); itr != end; ++itr)
	{
		if (*itr == value)
		{
			return 1;
		}
	}

	return 0;
}

int main()
{
	std::vector<int> vec;
	std::vector<std::string> vec2;

	for (int i = 0; i < 10; i++)
	{
		vec.push_back(i * 11);
		vec2.push_back(std::to_string(i * 9));
	}

	std::cout << exists(vec, 44) << " " << exists(vec, 65);
	std::cout << exists(vec2, std::to_string(44)) << " " << exists(vec2, std::to_string(18));

	int exit;
	std::cin >> exit;
	return exit;
}