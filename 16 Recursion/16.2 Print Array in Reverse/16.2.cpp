#include <iostream>

/*
2. Write a recursive function that takes an array and displays the elements in reverse order
without starting the index of the array at the end. (In other words, don’t write the equivalent of
a loop that starts printing at the end of the array.)
*/

void printArray(int array[], int index)
{
	if (index == 49) // base case is the end of the array
	{
		std::cout << array[index] << "\n";
		return;
	}

	printArray(array, index + 1);
	std::cout << array[index] << "\n";
}

int main()
{
	int array[50];
	int index = 0;
	for (size_t i = 0; i < 50; i++) // initialise array, numbers 0 to 49
	{
		array[i] = i;
	}

	printArray(array, index);

	int exitprogram;
	std::cout << "\nExiting.";
	std::cin >> exitprogram;
	return 0;
}
