/*
3. Implement a logging method that an interface class, StringConvertable, with a method
toString that converts the resulting object into a string representation of itself. The logging
method should print out the date and time as well as the object itself. (You can find information
on getting the date at http://www.cplusplus.com/reference/clibrary/ctime/). Again notice how
we are able to reuse our logging method simply by implementing an interface.
*/

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