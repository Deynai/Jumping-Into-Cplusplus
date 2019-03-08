#ifndef XMLPARSER_RH
#define XMLPARSER_RH

#include "XMLnode.h"
#include <string>
#include <fstream>
#include <iostream>
#include <vector>

class xmlparser
{
public:
	xmlparser(std::string filename);
	~xmlparser();
	xmlnode* nodeStart(xmlnode *p_parent);
	void nodeTextRead(xmlnode *p_node);
	bool nodeEnd();
	bool eof(); // returns true if there are no more node declarations
	void findNext(); // finds next node declaration, i.e updates i with next "<"
	void displayTree(xmlnode* p_base, int level); // display tree, level helps keep track of child node depth to help with formatting

private:
	std::ifstream _file;
	std::string _text;
	int i; // index for text searching
	void loadText();
	void attributeRead(xmlnode *p_node, int j);
};

#endif