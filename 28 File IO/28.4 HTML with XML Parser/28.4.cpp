/*
4. Rewrite your HTML parser so that it uses your XML parser instead of the hand-coded parsing you had
before. Add support for displaying lists. You should be able to read the <ul> tag or the <nl> tag for
unordered and numbered lists. Each list item should be between <li> and </li> tags. The display for
<ul>
<li>first item</li>
<li>second item</li>
</ul>
Should be
* first item
* second item
And for
<nl>
<li>first item</li>
<li>second item</li>
</nl>
Should be
1. first item
2. second item
Make sure that you restart your numbering if a second numbered list appears!
*/

#include "XMLparser.h"

/*
this->parse_html();
this->parse_head();
this->parse_b();
this->parse_i();
this->parse_a();
*/

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