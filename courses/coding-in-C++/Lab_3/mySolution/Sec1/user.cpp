#include "user.hpp"
#include "course.hpp"
#include "lesson.hpp"

#include <string>
#include <iostream>

std::string user::get_username() const
{
	return username;
}

void user::enroll_course(course& new_course)
{
	new_course.add_participant(*this);
}

void user::leave_course(course& old_course)
{
	old_course.remove_participant(*this);
}