#pragma once
#include "content.hpp"
#include <iostream>
#include <string>

#include <vector>

class lesson
{
private:
	const std::string title;

	std::vector<content> lesson_content;

public:
	lesson(std::string title);

	std::string get_title() const;
	void print_lesson_content() const;

	void add_content(content const& new_content);
};