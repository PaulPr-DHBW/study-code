#include "content.hpp"

#include <iostream>
#include <iomanip>
#include <string>

content::content(std::string title, std::string content_type)
	: title(title), content_type(content_type)
{ }

void content::display() const
{
	std::cout << std::setw(20) << std::setfill("*") << "" << std::endl;
	std::cout << std::left << std::setfill(" ") << "Content Title: " << title << std::endl;
	std::cout << std::left << std::setfill(" ") << "Content Type: " << content_type << std::endl;
	std::cout << std::setw(20) << std::setfill("*") << "" << std::endl;
}

void content::do_content() const
{
	//Doing something in here woooo
}