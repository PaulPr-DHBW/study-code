#ifndef QUERY_HPP
#define QUERY_HPP
#include <iostream>
#include <string>


class Query_new
{
private:
	std::string query_text;
	int max_results;
	bool is_valid;

public:
	Query_new(std::string input_text, int new_max_results);

	void display() const;
	std::string get_query_text() const;
	int get_max_results() const;
	bool get_is_valid() const;


};



#endif // !QUERY_HPP
