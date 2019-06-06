/* 
1. Write a program that reads in two strings, a "needle" and a "haystack" and counts the number
of times the "needle" appears in the "haystack".
*/

#include <iostream>
#include <string>

int findNeedle(const std::string &haystack, const std::string &needle)
{
	int counter = 0;

	// i is a number corresponding to position in the string
	// haystack.find(needle,0) finds the position of the first character of needle STARTING FROM 0.
	// so i = start of first needle, to the end of the string, incrementing by the next occurence of needle starting from i + needle.sizeof().
	for (int i = haystack.find(needle, 0); i != std::string::npos; i = haystack.find(needle,i+needle.size()))
	{
		counter++;
	}
	return counter;
}

int main()
{
	const std::string haystack = "testestestest test test testest";
	const std::string needle = "test";
	int number_of_needles = 0;

	number_of_needles = findNeedle(haystack, needle);

	// display what we counted to
	std::cout << number_of_needles;

	int exit;
	std::cin >> exit;
	return 0;
}