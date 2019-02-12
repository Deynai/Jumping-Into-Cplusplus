/*
2. Write a program that allows a user to type in tabular data similar to a CSV file, but instead of
using commas a separator, first prompt the user to enter the separator character, then let the
user type in the lines of tabular data. Provide a set of possible punctuation characters as options
by looking through the input for non-number, non-letter characters. Find characters that appear
on every single line, and choose those characters as the option. For example, if you see input
like this:
Alex Allain, webmaster@cprogramming.com
John Smith, john@nowhere.com
You should prompt the user to choose between comma, at sign, and period for the separator.
*/

#include <iostream>
#include <string>
#include <vector>

const std::string selectSeparator(const std::string &data)
{
	// list of all separators we will consider
	std::vector<char> separatorList = { '.', '!', '@', '#', '&', '(', ')', '–', '[', '{', '}', ']', ':', ';', '\'', ',', '?', '/', '*', '`', '~', '$', '^', '+', '=', '<', '>', '“' };

	// std::vector<char> foundseparators;
	/*
	for (std::vector<char>::const_iterator i = separatorList.begin(), end = separatorList.end(); i != end; ++i)
	{
		if (data.find(*i, 0) != std::string::npos)
		{
			foundseparators.push_back(*i);
		}
	}
	*/

	// we could create a second list of all separators we have found as above, but it's not really necessary, we can display anything we find as we go
	std::cout << "Please select a separator:\n";
	for (std::vector<char>::const_iterator i = separatorList.begin(), end = separatorList.end(); i != end; ++i)
	{
		if (data.find(*i, 0) != std::string::npos)
		{
			std::cout << *i;
		}
	}
	std::cout << "\n\n";

	// we could check that the selection is one of the separators we found earlier, but for now we will trust the user in selecting an appropriate one.
	std::string selection;
	std::cin >> selection;
	return selection;
}

const std::string inputData()
{
	std::string data = "";
	std::string line_input;
	std::cout << "Enter data, when finished, enter a blank line:\n";
	while (true)
	{
		std::getline(std::cin, line_input, '\n');
		if (line_input.size() == 0)
		{
			// if we enter a blank line, end data input and return
			break;
		}

		// construct one big string a line at a time
		data += "\n" + line_input;
	}
	return data;
}

const std::vector<std::vector<std::string> > constructVectorTable(const std::string &data, const std::string &separator)
{
	// let's make a 2d vector for our table
	std::vector<std::vector<std::string> > vectorTable;
	// and an emptyVector to push_back our 2d vector when we need a new row
	std::vector<std::string> emptyVector;

	int row = 0;
	std::string line; // temp line to read from data

	for (int i = 0; i != std::string::npos; i = data.find('\n', i+1))
	{
		// let's copy the first line to a new string to make this a bit simpler, and to save on a headache let's add a dummy character 'x' so we can take j+1 later instead of j and not worry about the special case of no separator at the start of the line.
		line = "x" + data.substr(i+1, data.find('\n', i+1) - (i+1));
		// expand our table with a new vector corresponding to a new row
		vectorTable.push_back(emptyVector);

		// let j be the start of the line, incrementing to the position of the next separator, until there are no more separators in the line
		for (int j = 0; j != std::string::npos; j = line.find(separator, j+1))
		{
			if (line.find(separator, j+1) != std::string::npos)
			{
				// if there is still a separator after our current position, let's push_back the substr starting from our current position+1 until the next separator to our vector
				vectorTable[row].push_back(line.substr(j+1, line.find(separator, j + 1) - (j+1)));
			}
			else
			{
				// if there are no more separators, instead push_back the substr starting from our current position+1 until the end of the line
				vectorTable[row].push_back(line.substr(j+1, line.size() - (j+1)));
			}
		}
		// increment the index of the vector we are adding values to
		row += 1;
	}

	return vectorTable;
}

void displayData(const std::vector<std::vector<std::string> > &data)
{
	// let's create an iterator for a vector with elements that are vectors of strings, i
	for (std::vector<std::vector<std::string> >::const_iterator i = data.begin(), end = data.end(); i != end; ++i)
	{
		// need to be a bit careful with exactly what we are iterating here: 
		// i is an iterator over the data (a vector of rows) but j is iterating over the elements in whatever row i is currently pointing to, and because of that the syntax changes from "data.begin()" to "i->begin()"
		for (std::vector<std::string>::const_iterator j = i->begin(), end2 = i->end(); j != end2; ++j)
		{
			std::cout << *j << "\t";
		}
		std::cout << "\n";
	}
	return;
}

int main()
{
	const std::string data = inputData();
	const std::string separator = selectSeparator(data);

	const std::vector<std::vector<std::string> > tabular_data = constructVectorTable(data, separator);

	displayData(tabular_data);

	int exit;
	std::cin >> exit;
	return 0;
}