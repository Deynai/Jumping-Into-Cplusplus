/*
1. Write a function that takes a vector and sums all the values in the vector, no matter what type
of numerical data the vector holds.
*/

#include <iostream>
#include <vector>

template <typename T>
T vectorSum(std::vector<T> vec)
{
	T sum = 0;
	// Important to put typename before std::vector. Due to compiler not knowing if iterator exists for type T, it needs "typename" to say "It does exist and will work, promise"
	for (typename std::vector<T>::iterator iter = vec.begin(), end = vec.end(); iter != end; ++iter)
	{
		sum += *iter;
	}
	return sum;
}

int main()
{
	std::vector<int> intVector;
	std::vector<double> doubVector;

	for (size_t i = 1; i <= 100; i++)
	{
		intVector.push_back(i);
		doubVector.push_back(0.503);
	}

	std::cout << vectorSum(intVector) << "\n" << vectorSum(doubVector);


	int exit;
	std::cin >> exit;
	return exit;
}