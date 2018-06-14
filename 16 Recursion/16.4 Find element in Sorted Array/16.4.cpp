#include <iostream>

/*
Write a recursive function that takes a sorted array and a target element and finds that element
in the array (returning the index, or -1 if the element isn’t in the array). How fast can you make
this search? Can you do better than having to look at every element?
*/

int splitArray(int list[], int element, int low, int high)
{
	if (high - low == 1) // when the bounds are one index apart, one of the bounds is the element required (or neither are). Because of int rounding down and setting the midpoint to lower bound if there is equality, this is likely to be the lower bound.
	{
		if (list[low] == element)
		{
			return low;
		}
		if (list[high] == element)
		{
			return high;
		}
		else
		{
			return -1; // if the element isn't in the list, return -1
		}
	}

	// this splitting algo should find the element in [log x / log 2] steps, where x is the size of the list.
	// this utilises ints truncating by default: 6.5 -> 6 (little bit dodgy maybe)
	if (list[(high+low)/2] <= element)
	{
		splitArray(list, element, (high + low) / 2, high); // midpoint = new lower bound, same upper
	}
	else
	{
		splitArray(list, element, low, (high + low) / 2); // midpoint = new upper bound, same lower
	}
}

int main()
{
	int list[300];
	for (size_t i = 0; i < 300; i++)
	{
		list[i] = (i * 3) + (i*i) - 40; // initialise with arbitrary sorted values
	}

	int element = 0;
	std::cout << "Find element: ";
	std::cin >> element;

	std::cout << "\n\nIndex is: " << splitArray(list, element, 0, sizeof(list) / sizeof(*list)) << "\n";

	int exitprogram;
	std::cout << "\nExiting.";
	std::cin >> exitprogram;
	return 0;
}