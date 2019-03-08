#include "XMLnode.h"

xmlnode::xmlnode()
	: _data("")
{
}

xmlnode::~xmlnode()
{
	for (std::vector<xmlnode*>::iterator itr = this->_children.begin(), end = this->_children.end(); itr != end; ++itr)
	{
		delete *itr;
	}
}