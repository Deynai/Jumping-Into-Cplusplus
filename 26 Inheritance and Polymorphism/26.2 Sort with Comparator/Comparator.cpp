#include "Comparator.h"
#include <map>

// Comparator

Comparator::Comparator()
{}

Comparator::~Comparator()
{}

int Comparator::compare(const std::string &lhs, const std::string &rhs)
{
	if (lhs == rhs)
	{
		return 0;
	}
	if (lhs < rhs)
	{
		return -1;
	}
	return 1;
}

// CaseInsensitiveSort

CaseInsensitiveSort::CaseInsensitiveSort()
{}

CaseInsensitiveSort::~CaseInsensitiveSort()
{}

void CaseInsensitiveSort::sort(std::vector<std::string> &strings)
{
	// sort without case sensitivity
	bool sorted = 0;
	std::string temp;
	while (sorted == 0)
	{
		sorted = 1; // assume list is sorted
		for (std::vector<std::string>::iterator itr = strings.begin(), end = strings.end(); (itr + 1) != end; ++itr)
		{
			switch (compare(_toLower(*itr), _toLower(*(itr + 1))))
			{
			case 1: // since we are comparing strings, Z > A, and we want lowest first, so we will swap them if first > second, i.e when compare returns 1 rather than -1.
				temp = *itr;
				*itr = *(itr + 1);
				*(itr + 1) = temp;
				sorted = 0; // if we swap anything then let's say it's not sorted (even though it might be if it was the last swap). This means we don't need a separate "check if sorted" function, we just keep going until we do a full loop with no change.
				break;
			default: // otherwise do nothing
				break;
			}
		}
	}
}

std::string CaseInsensitiveSort::_toLower(const std::string text)
{
	std::string copyoftext = text;
	std::map<std::string, std::string> upperlowermap = { {"A","a"},{"B","b"},{"C","c"},{"D","d"},{"E","e"},{"F","f"},{"G","g"},{"H","h"},{"I","i"},{"J","j"},{"K","k"},{"L","l"},{"M","m"},{"N","n"},{"O","o"},{"P","p"},{"Q","q"},{"R","r"},{"S","s"},{"T","t"},{"U","u"},{"V","v"},{"W","w"},{"X","x"},{"Y","y"},{"Z","z"} };
	for (std::map<std::string,std::string>::iterator itr = upperlowermap.begin(), end = upperlowermap.end(); itr != end; ++itr)
	{
		for (int i = copyoftext.find(itr->first, 0); i != std::string::npos; i = copyoftext.find(itr->first, i+1))
		{
			copyoftext.replace(i, 1, itr->second);
		}
	}
	return copyoftext;
}

// InverseSort

InverseSort::InverseSort()
{}

InverseSort::~InverseSort()
{}

void InverseSort::sort(std::vector<std::string> &strings)
{
	// sort inversely (Z->A)
	bool sorted = 0;
	std::string temp;
	while (sorted == 0)
	{
		sorted = 1; // assume list is sorted
		for (std::vector<std::string>::iterator itr = strings.begin(), end = strings.end(); (itr + 1) != end; ++itr)
		{
			switch (compare(*itr, *(itr+1)))
			{
			case -1: // -1 for the inverse sort.
				temp = *itr;
				*itr = *(itr + 1);
				*(itr + 1) = temp;
				sorted = 0; // if we swap anything then let's say it's not sorted (even though it might be if it was the last swap). This means we don't need a separate "check if sorted" function, we just keep going until we do a full loop with no change.
				break;
			default: // otherwise do nothing
				break;
			}
		}
	}
}