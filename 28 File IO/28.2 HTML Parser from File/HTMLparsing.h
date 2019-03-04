#pragma once
#ifndef HTMLPARSING_RH
#define HTMLPARSING_RH

#include <string>
#include <fstream>
#include <iostream>

class htmltext
{
public:
	htmltext();
	htmltext(std::string filename);
	~htmltext();
	void loadText(std::string filename);
	void parse_all();
	void displayText();

private:
	std::string _text;
	std::ifstream _file;
	void parse_html();
	void parse_head();
	void parse_b();
	void parse_i();
	void parse_a();
};

#endif
