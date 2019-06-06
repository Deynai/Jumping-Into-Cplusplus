/*
3. Create a simple XML parser. XML is a basic formatting language, similar to HTML. The document is a
tree structure of nodes, of the form <node>[data]</node>, where [data] is either some text or another
nested node. XML nodes may have attributes, of the form <node attribute=”value”></node>. (The true
XML specification includes many more details, but that would be a lot more work to implement.) Your
parser should accept an interface class with several methods that it calls when something interesting
happens:
1) Whenever a node is read, it calls a method nodeStart, with the name of the node.
2) Whenever an attribute is read, it calls a method, attributeRead; this method should always
be called immediately after the nodeStart method for the node with which the attribute is
associated.
3) Whenever a node has body text, call nodeTextRead, with the content of the text, as a string. If
you have a situation like this <node>text<sub-node>text</sub-node>more text</node>, there
should be separate calls to nodeTextRead for the text before to the sub- node and the text
after the sub-node.
4) Whenever an end-node is read, call nodeEnd, with the name of the node.
5) You may treat any < or > character as the start of a node. If an XML author wants < or > to
appear in the text, it should be written as &lt; or &gt; (for less-than and greater-than). Since
ampersands must also be escaped, they must appear as &amp;. You do not need to perform
translation of &lt; and &gt; or &amp; in your code, however.
*/

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