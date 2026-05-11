#ifndef SEARCHABLE_ITEM_HPP
#define SEARCHABLE_ITEM_HPP
#include <iostream>
#include <string>

//Konstanten für das Ranking System
const int highest_rank = 100;
const int lowest_rank = 0;
const int popular_rank = 80;


class Searchable_Item
{
private:
	std::string web_adress;
	std::string text_information;

	int ranking;
	bool is_popular;

public:
	Searchable_Item(std::string new_web_adress, std::string new_text_information, int new_rank);
	Searchable_Item();

	void display_Item() const;
	std::string get_Adress() const;
	std::string get_Information() const;
	int get_Rank() const;
	bool get_is_popular() const;

};




#endif // !SEARCHABLE_ITEM_HPP
