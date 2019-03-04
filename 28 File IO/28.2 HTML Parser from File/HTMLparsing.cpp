#include "HTMLparsing.h"

htmltext::htmltext(std::string filename)
	:_text("")
{
	loadText(filename);
}

htmltext::htmltext()
	:_text("")
{
}

htmltext::~htmltext()
{
	_file.close();
}

void htmltext::loadText(std::string filename)
{
	_file.open(filename);
	if (!_file.is_open())
	{
		std::cout << "Could not open file";
		return;
	}
	std::string temp;
	while (getline(_file, temp))
	{
		_text += temp;
		_text += "\n";
	}
	return;
}

void htmltext::parse_all()
{
	this->parse_html();
	this->parse_head();
	this->parse_b();
	this->parse_i();
	this->parse_a();
	return;
}

void htmltext::displayText()
{
	/*
	for (int i = 0; i < _text.length(); i++)
	{
		std::cout << _text[i];
	}
	return;
	*/
	std::cout << "\n\n" << _text;
	return;
}

// private

void htmltext::parse_html()
{
	std::string html = "<html>";
	std::string html2 = "</html>";

	// iterate through data finding each instance of " <html> ", i will denote the position of "<"
	for (int i = _text.find(html, 0); i != std::string::npos; i = _text.find(html, i + 1))
	{
		// delete <html>
		_text.erase(i, html.length() + 1);

		// if following </html> exists then find and delete that too
		if (_text.find(html2, i) != std::string::npos)
		{
			_text.erase(_text.find(html2, i), html2.length() + 1);
		}
	}
	return;
}

void htmltext::parse_head()
{
	std::string head("<head>");
	std::string head2("</head>");
	int length_to_delete;

	for (int i = _text.find(head, 0); i != std::string::npos; i = _text.find(head, i + 1))
	{
		// find the length from the start of <head> to the end of </head>
		length_to_delete = _text.find(head2, i) - i + head2.length() + 1;
		// and delete the whole lot!
		_text.erase(_text.find(head, i), length_to_delete);
	}
	return;
}

void htmltext::parse_b()
{
	std::string b("<b>");
	std::string b2("</b>");

	for (int i = _text.find(b, 0); i != std::string::npos; i = _text.find(b, i + 1))
	{
		// similar to htmlParser, except instead of erasing we are replacing both <b> and </b> with '*'
		_text.replace(i, 3, "*");
		if (_text.find(b2, i) != std::string::npos)
		{
			_text.replace(_text.find(b2, i), 4, "*");
		}
	}
	return;
}

void htmltext::parse_i()
{
	std::string b("<i>");
	std::string b2("</i>");

	for (int i = _text.find(b, 0); i != std::string::npos; i = _text.find(b, i + 1))
	{
		// identical to bParser, replacing <i> and </i> with '_'
		_text.replace(i, 3, "_");
		if (_text.find(b2, i) != std::string::npos)
		{
			_text.replace(_text.find(b2, i), 4, "_");
		}
	}
	return;
}

void htmltext::parse_a()
{
	// <a href="linkurl">link text</a>   ->   link text (linkurl)
	std::string a("<a href=");
	std::string a2("</a>");
	std::string linkurl;
	std::string linktext;

	// iterate through data finding each instance of " <a href=" ", 'i' will denote the position of "<"
	for (int i = _text.find(a, 0); i != std::string::npos; i = _text.find(a, i + 1))
	{
		// assign linkurl
		linkurl.assign(_text, i + 8, _text.find('>', i) - (i + 8));
		// assign linktext: starting at pos">", with length pos"<" - pos">" - 1
		linktext.assign(_text, _text.find('>', i) + 1, _text.find('<', i + 1) - _text.find('>', i) - 1);
		// now replace the whole thing from <a href=" ... to </a> with linktext (linkurl)
		_text.replace(i, _text.find('>', i + a.length() + linkurl.length() + 3) - i + 1, linktext + " (" + linkurl + ")");
	}
	return;
}