#pragma once
#include <iostream>
#include <string>

class content
{
private:
	const std::string title;
	const std::string content_type;

public:
	content(std::string title, std::string content_type);
	
	void display() const;
	void do_content() const;
};