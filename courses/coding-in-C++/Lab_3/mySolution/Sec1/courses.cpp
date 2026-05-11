#include "course.hpp"
#include "lesson.hpp"
#include "user.hpp"

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>

course::course(std::string title)
	: title(title)
{ }

std::string course::get_title() const
{
	return title;
}

void course::add_participant(user &new_user)
{
	course_participants.push_back(new_user);
}

void course::remove_participant(user &old_user)
{
	for (std::vector<user>::iterator x = course_participants.begin(); x < course_participants.end(); ++x)
	{
		if ((*x).get_username() == old_user.get_username())
		{
			course_participants.erase(x);
			return;
		}
	}

}

void course::add_lesson(lesson& new_lesson)
{ 
	course_lesson.push_back(new_lesson);
}

void course::remove_lesson(lesson& old_lesson)
{ 
	for (auto x = course_lesson.begin(); x < course_lesson.end(); ++x)
	{
		if ((*x).get_title() == old_lesson.get_title())
		{
			course_lesson.erase(x);
			return;
		}
	}
}

void course::sort_lesson()
{
	std::sort(course_lesson.begin(), course_lesson.end(),
		[](const lesson& a, const lesson& b)
		{
			return (a.get_title() < b.get_title());
		}

	
	);
}