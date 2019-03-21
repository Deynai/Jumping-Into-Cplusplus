#ifndef XMLNODE_RH
#define XMLNODE_RH

#include <string>
#include <vector>

class xmlnode
{
public:
	xmlnode();
	~xmlnode();

	std::string _name;
	std::string _attribute;
	std::string _data;
	std::vector<xmlnode*> _children;
};

#endif