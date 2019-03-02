#include "StringConvertable.h"
#include <iostream>
#include <time.h>

int main()
{
	subclass1 event1;
	subclass2 event2;
	subclass3 event3;

	event1.addLog();
	event2.addLog();
	event3.addLog();

	int exit;
	std::cin >> exit;
	return 0;
}