#pragma once
#include "course.hpp"

#include <iostream>
#include <string>

class user
{
private:
	std::string username;

public:
	std::string get_username() const;
	void enroll_course(course& new_course);
	void leave_course(course& old_course);

};