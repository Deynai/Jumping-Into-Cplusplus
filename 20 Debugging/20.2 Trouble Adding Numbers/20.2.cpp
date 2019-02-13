// Problem 2: Trouble adding numbers

#include <iostream>

using namespace std;

int sumValues(int *values, int n)
{
	//int sum;
	int sum = 0;

	//for (int i = 0; i <= n; i++)
	for(int i = 0; i < n; i++)
	{
		sum += values[i];
	}
	return sum;
}

int main()
{
	int size;
	cout << "Enter a size: ";
	cin >> size;
	int *values = new int[size];

	//int i;
	int i = 0;

	while (i < size)
	{
		cout << "Enter value to add: ";
		//cin >> values[++i];
		cin >> values[i++];
	}
	cout << "Total sum is: " << sumValues(values, size);

	int exit;
	std::cin >> exit;
	return 0;
}