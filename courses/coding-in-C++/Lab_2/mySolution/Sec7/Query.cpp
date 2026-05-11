#include "Query.hpp"

#include <iostream>
#include <iomanip>
#include <string>

Query_new::Query_new(std::string input_text, int new_max_results)
	: query_text(input_text), max_results(new_max_results)
{
	is_valid = !query_text.empty() && max_results > 0;
}

void Query_new::display() const
{
	std::cout << "\n\n";
	std::cout << std::setw(25) << std::setfill('*') << std::right << "" << std::endl;
	std::cout << std::setw(25) << std::left << std::setfill(' ') << "Query: " << query_text << std::endl;
	std::cout << std::setw(25) << std::left << "Max Results: " << max_results << std::endl;
	std::cout << std::setw(25) << std::setfill('*') << std::right << "" << std::endl;

}

std::string Query_new::get_query_text() const
{
	return query_text;
}
int Query_new::get_max_results() const
{
	return max_results;
}
bool Query_new::get_is_valid() const
{
	return is_valid;
}