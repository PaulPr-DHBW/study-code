#include "Searchable_Item.hpp"

#include <iostream>
#include <iomanip>
#include <string>



Searchable_Item::Searchable_Item(std::string new_web_adress, std::string new_text_information, int new_rank)
	: web_adress(new_web_adress), text_information(new_text_information), ranking(new_rank)
{
	is_popular = (ranking >= popular_rank);
}
Searchable_Item::Searchable_Item()
	: web_adress(""), text_information(""), ranking(0), is_popular(false)
{
}


void Searchable_Item::display_Item() const
{
	std::cout << "\n\n";
	std::cout << std::setw(25) << std::setfill('*') << std::right << "" << std::endl;
	std::cout << std::setw(25) << std::left << "Web Adress: " << web_adress << std::endl;
	std::cout << std::setw(25) << std::left << "Information: " << text_information << std::endl;
	std::cout << std::setw(25) << std::left << "Rank: " << ranking << std::endl;
	std::cout << std::setw(25) << std::setfill('*') << std::right << "" << std::endl;

}

std::string Searchable_Item::get_Adress() const
{
	return web_adress;
}

std::string Searchable_Item::get_Information() const
{
	return text_information;
}

int Searchable_Item::get_Rank() const
{
	return ranking;
}

bool Searchable_Item::get_is_popular() const
{
	return is_popular;
}