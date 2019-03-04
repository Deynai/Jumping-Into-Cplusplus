#include <iostream>
#include "HTMLparsing.h"

int main()
{
	htmltext html_text("file.txt");

	html_text.displayText();
	html_text.parse_all();
	
	std::cout << "\n\n";
	html_text.displayText();

	int exit;
	std::cin >> exit;
	return 0;
}