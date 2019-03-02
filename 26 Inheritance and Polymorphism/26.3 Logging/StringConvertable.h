#pragma once
#include <string>
#include <iostream>
#include <time.h>

class StringConvertable
{
public:
	StringConvertable();
	virtual ~StringConvertable();
	virtual std::string toString() = 0;
	void addLog();
};

class subclass1 : public StringConvertable
{
public:
	subclass1();
	~subclass1();
	std::string toString();
};

class subclass2 : public StringConvertable
{
public:
	subclass2();
	~subclass2();
	std::string toString();
};

class subclass3 : public StringConvertable
{
public:
	subclass3();
	~subclass3();
	std::string toString();
};

// StringConvertable &StringConvertable