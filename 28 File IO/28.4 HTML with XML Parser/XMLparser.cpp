#include "XMLparser.h"

// PUBLIC

xmlparser::xmlparser(std::string filename)
	:_file(filename)
	, _text("")
{
	if (!_file.is_open())
	{
		std::cout << "Could not open file.";
	}
	this->loadText();
}

xmlparser::~xmlparser()
{
}

xmlnode* xmlparser::nodeStart(xmlnode *p_parent)
{
	xmlnode *p_newnode = new xmlnode;

	std::string name;
	int j; // temp index

	if (_text.find(" ", i) < _text.find(">", i))
	{
		j = _text.find(" ", i) + 1;
		attributeRead(p_newnode, j);
	}
	else
	{
		j = _text.find(">", i) + 1;
	}

	name.assign(_text, i + 1, j - i - 2);

	p_newnode->_name = name;
	i = _text.find(">", i);

	p_parent->_children.push_back(p_newnode);

	return p_newnode;
}

void xmlparser::nodeTextRead(xmlnode *node)
{
	if (i == 0)
	{
		return;
	}

	std::string data;

	// read in text until the next <
	if (_text.find("<", i) - i - 1 > 0)
	{
		data.assign(_text, i + 1, _text.find("<", i) - i - 1);

		// we don't want to add single new line characters to data, if that's all we find then return without adding
		if (data == "\n")
		{
			return;
		}
		node->_data += data;
	}

	return;
}

bool xmlparser::nodeEnd()
{
	// if our next < is followed by a /, then it must be an end of node, so update i to the end of </node> and return true
	if (_text[i + 1] == '/')
	{
		i = _text.find(">", i);
		return 1;
	}

	return 0;
}

bool xmlparser::eof()
{
	return (_text.find("<", i) == std::string::npos);
}

void xmlparser::findNext()
{
	i = _text.find("<", i);
	return;
}

void xmlparser::displayTree(xmlnode *p_base, int level)
{
	int counter = 1;

	for (std::vector<xmlnode*>::iterator itr = p_base->_children.begin(), end = p_base->_children.end(); itr != end; ++itr)
	{
		// spacing
		for (int j = 0; j < level; j++)
		{
			std::cout << "\t";
		}

		std::cout << (*itr)->_name;

		if ((*itr)->_attribute != "")
		{
			std::cout << " -" << (*itr)->_attribute;
		}

		std::cout << "\n";

		//spacing
		for (int j = 0; j < level; j++)
		{
			std::cout << "\t";
		}

		if (p_base->_name == "ul" && (*itr)->_name == "li")
		{
			std::cout << "* ";
		}
		if (p_base->_name == "nl" && (*itr)->_name == "li")
		{
			std::cout << counter << ". ";
			counter++;
		}

		if ((*itr)->_data != "")
		{
			std::cout << (*itr)->_data << "\n";
		}
		std::cout << "\n";

		// recurse on lower level
		displayTree(*itr, level + 1);
	}
	return;
}

// PRIVATE

void xmlparser::loadText()
{
	std::string temp;
	while (getline(_file, temp))
	{
		_text += temp;
		_text += "\n";
	}
	return;
}

void xmlparser::attributeRead(xmlnode *node, int j)
{
	std::string attribute;

	j = _text.find('"', j);
	// assign entire line of ' attribute="xxx" ', we may want to change this to just 'xxx', or split into 'attribute' and 'xxx' in both attribute and value fields later.
	attribute.assign(_text, j + 1, _text.find('"', j + 1) - j - 1);

	node->_attribute = attribute;
	return;
}