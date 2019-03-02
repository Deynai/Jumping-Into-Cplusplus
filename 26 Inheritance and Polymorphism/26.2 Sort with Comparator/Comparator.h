#ifndef Comparator_RH
#define Comparator_RH

#include <string>
#include <vector>

class Comparator
{
public:
	Comparator();
	virtual ~Comparator();
	virtual void sort(std::vector<std::string> &strings) = 0;
	int compare(const std::string &lhs, const std::string &rhs);

protected:
};

class CaseInsensitiveSort : public Comparator
{
public:
	CaseInsensitiveSort();
	~CaseInsensitiveSort();
	void sort(std::vector<std::string> &strings);
	
private:
	std::string _toLower(std::string);
};

class InverseSort : public Comparator
{
public:
	InverseSort();
	~InverseSort();
	void sort(std::vector<std::string> &strings);
};

#endif