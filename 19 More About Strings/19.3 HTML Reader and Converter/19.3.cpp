/*
3. Write a program that reads in HTML text that the user types in (don’t worry, we’ll cover how to
read from a file later). It should support the following HTML tags: <html>, <head>, <body>, <b>,
<i>, and <a>. Each HTML tag has an open tag, e.g. <html>, and a closing tag which has a forwardslash
at the start: </html>. Inside the tag is text that is controlled by that tag: <b>text to be
bolded</b> or <i>text to be italicized</i>. The <head> </head> tags control text that is
metadata, and the <body></body> tags surround text that is to be displayed. <a> tags are used
for hyperlinks, and have an URL in the following format: <a href=URL>text</a>.

Once your program has read in some HTML, it should simply ignore <html>. It should remove
any text from the <head> section so that it doesn't show up when you output it. It should then
display all text in the body, modifying it so that any text between a <b> and a </b> will show up
with asterisks (*) around it, any text inside <i> and </i> will show up with underscores (_)
around it, and any text with a <a href=linkurl>link text</a> tag shows up as link text (linkurl).
*/

#include <iostream>
#include <string>

void htmlParser(std::string &data)
{
	std::string html = "<html>";
	std::string html2 = "</html>";

	// iterate through data finding each instance of " <html> ", i will denote the position of "<"
	for (int i = data.find(html, 0); i != std::string::npos; i = data.find(html, i+1))
	{
		// delete <html>
		data.erase(i, html.length()+1);

		// if following </html> exists then find and delete that too
		if (data.find(html2, i) != std::string::npos)
		{
			data.erase(data.find(html2, i), html2.length()+1); 
		}
	}
	return;
}

void headParser(std::string &data)
{
	std::string head("<head>");
	std::string head2("</head>");
	int length_to_delete;

	for (int i = data.find(head, 0); i != std::string::npos; i = data.find(head, i + 1))
	{
		// find the length from the start of <head> to the end of </head>
		length_to_delete = data.find(head2, i) - i + head2.length() + 1;
		// and delete the whole lot!
		data.erase(data.find(head, i), length_to_delete);
	}
	return;
}

void bParser(std::string &data)
{
	std::string b("<b>");
	std::string b2("</b>");

	for (int i = data.find(b, 0); i != std::string::npos; i = data.find(b, i + 1))
	{
		// similar to htmlParser, except instead of erasing we are replacing both <b> and </b> with '*'
		data.replace(i, 3, "*");
		if (data.find(b2, i) != std::string::npos)
		{
			data.replace(data.find(b2, i), 4, "*");
		}
	}
	return;
}

void iParser(std::string &data)
{
	std::string b("<i>");
	std::string b2("</i>");

	for (int i = data.find(b, 0); i != std::string::npos; i = data.find(b, i + 1))
	{
		// identical to bParser, replacing <i> and </i> with '_'
		data.replace(i, 3, "_");
		if (data.find(b2, i) != std::string::npos)
		{
			data.replace(data.find(b2, i), 4, "_");
		}
	}
	return;
}

void aParser(std::string &data)
{
	// <a href="linkurl">link text</a>   ->   link text (linkurl)
	std::string a("<a href=");
	std::string a2("</a>");
	std::string linkurl;
	std::string linktext;

	// iterate through data finding each instance of " <a href=" ", 'i' will denote the position of "<"
	for (int i = data.find(a, 0); i != std::string::npos; i = data.find(a, i + 1))
	{
		// assign linkurl
		linkurl.assign(data, i + 9, data.find('>', i) - (i + 10));
		// assign linktext: starting at pos">", with length pos"<" - pos">" - 1
		linktext.assign(data, data.find('>', i) + 1, data.find('<', i + 1) - data.find('>', i) - 1);
		// now replace the whole thing from <a href=" ... to </a> with linktext (linkurl)
		data.replace(i, data.find('>', i + a.length() + linkurl.length() + 3) - i + 1, linktext + " (" + linkurl + ")");
	}
	return;
}

void parseAll(std::string &data)
{
	// we will deal with each command one at a time, passing data by reference and editing it as we go.
	htmlParser(data);
	headParser(data);
	bParser(data);
	iParser(data);
	aParser(data);
	return;
}

void printData(std::string &data)
{
	std::cout << "\n\n" << data;
	return;
}

std::string loadData()
{
	std::string data = "";
	std::string line_input;
	std::cout << "Enter data, when finished, enter a blank line:\n";
	while (true)
	{
		std::getline(std::cin, line_input, '\n');
		if (line_input.size() == 0)
		{
			// if we enter a blank line, end data input and return
			break;
		}

		// construct one big string a line at a time
		data += line_input + "\n";
	}
	return data;
}

int main()
{
	// load data, for now this is just user input at runtime
	std::string data = loadData();
	// parse all will contain functions to parse each command in turn
	parseAll(data);
	// let's see what changes were made
	printData(data);

	int exit;
	std::cin >> exit;
	return 0;
}