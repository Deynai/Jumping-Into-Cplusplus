#pragma once
#include <string>

class Comparable
{
public:
	Comparable();
	~Comparable();

	int compare(Comparable &other); // we define our compare function in Comparable
	virtual int getValue() = 0; // we use virtual so each subclass can define which metric it wants to be sorted by. 
	virtual std::string getString() = 0; // string so we can sort by string metrics too. I think this slight mess can be solved with templates in the next chapter where we can define a generic variable type.
};

class HighscoreElement : public Comparable
{
public:
	HighscoreElement();
	~HighscoreElement();
	HighscoreElement(int score, std::string name);

	int getValue();
	std::string getString();

private:
	int _score;
	std::string _name;
};