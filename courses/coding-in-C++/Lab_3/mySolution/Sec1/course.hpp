#pragma once
#include "lesson.hpp"
#include "user.hpp"

#include <iostream>
#include <string>
#include <vector>



class course
{
private:
	const std::string title;
	std::vector<lesson> course_lesson;
	std::vector<user> course_participants;

public:
	course(std::string title);

	std::string get_title() const;

	void add_participant(user &new_user);
	void remove_participant(user &old_user);
		
	void add_lesson(lesson &new_lesson);
	void remove_lesson(lesson &old_lesson);

	void sort_lesson();
};