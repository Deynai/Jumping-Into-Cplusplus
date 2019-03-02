#include "Comparable.h"

// Comparable

Comparable::Comparable()
{
}

Comparable::~Comparable()
{
}

int Comparable::compare(Comparable &other)
{
	if (this->getValue() == other.getValue())
	{
		if (this->getString() == other.getString())
		{
			return 0;
		}
		else if (this->getString() > other.getString())
		{
			return -1;
		}
		else
		{
			return 1;
		}
	}
	else if (this->getValue() < other.getValue())
	{
		return -1;
	}
	else
	{
		return 1;
	}
}

// Highscore Element

HighscoreElement::HighscoreElement()
	: _score(0)
	, _name("")
{
}

HighscoreElement::~HighscoreElement()
{
}

HighscoreElement::HighscoreElement(int score, std::string name)
	: _score(score)
	, _name(name)
{
}

int HighscoreElement::getValue()
{
	return _score;
}

std::string HighscoreElement::getString()
{
	return _name;
}