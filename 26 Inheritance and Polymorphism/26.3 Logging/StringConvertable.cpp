#include "StringConvertable.h"

// StringConvertable

StringConvertable::StringConvertable()
{
}

StringConvertable::~StringConvertable()
{
}

void StringConvertable::addLog()
{
	time_t rawtime = time(NULL); // grab current time as a raw number
	struct tm timeinfo; // this will store our time data 
	gmtime_s(&timeinfo, &rawtime); // function that fills the fields of timeinfo struct based on GMT
	std::cout << timeinfo.tm_hour << ":" << timeinfo.tm_min << ":" << timeinfo.tm_sec << " " << timeinfo.tm_mday << "/" << timeinfo.tm_mon + 1 << "/" << timeinfo.tm_year - 100; 

	std::cout << " -- " << this->toString() << "\n";
	return;
}

// subclass1

subclass1::subclass1()
{
}

subclass1::~subclass1()
{
}

std::string subclass1::toString()
{
	return "subclass1";
}


// subclass2

subclass2::subclass2()
{
}

subclass2::~subclass2()
{
}

std::string subclass2::toString()
{
	return "subclass2";
}


// subclass3

subclass3::subclass3()
{
}

subclass3::~subclass3()
{
}

std::string subclass3::toString()
{
	return "subclass3";
}