#include "lesson.hpp"
#include "content.hpp"

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

lesson::lesson(std::string title)
	: title(title)
{ }

std::string lesson::get_title() const
{
	return title;
}

void lesson::print_lesson_content() const
{
	std::cout << std::setw(20) << std::setfill("*") << "" << std::endl;

	for (auto x : lesson_content)
	{
		x.display();
		std::cout << std::endl;
	}
	std::cout << std::setw(20) << std::setfill("*") << "" << std::endl;
}

void lesson::add_content(content const& new_content)
{
	lesson_content.push_back(new_content);
}