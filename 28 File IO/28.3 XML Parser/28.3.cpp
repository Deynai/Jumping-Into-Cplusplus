#include "XMLparser.h"

void XML(xmlnode *p_node, xmlparser &xml)
{
	if (xml.eof())
	{
		return;
	}

	// read in text until the next node start/end
	xml.nodeTextRead(p_node);

	// find next < from current point
	xml.findNext();

	// if we find a node end, i.e "</", return out of current child
	if (xml.nodeEnd())
	{
		return;
	}

	xmlnode *p_child = NULL;
	p_child = xml.nodeStart(p_node);
	XML(p_child, xml); // enter the child node
	XML(p_node, xml); // repeat until we hit a "</" relevant to p_node so we can find multiple child nodes (and read in disjointed text split by child nodes) 

	return;
}




int main()
{
	xmlnode *p_base = new xmlnode;
	p_base->_name = "Container Node";

	xmlparser xmldoc_parser("file.xml");
	XML(p_base, xmldoc_parser);

	xmldoc_parser.displayTree(p_base, 0);

	delete p_base;

	int exit;
	std::cin >> exit;
	return 0;
}