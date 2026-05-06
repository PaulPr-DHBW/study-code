#include "Query.hpp"
#include "Seach_Engine.hpp"
#include "Searchable_Item.hpp"

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>

int Search_Engine::usages = 0;

Search_Engine::Search_Engine(std::string name)
	: engine_name(name)
{
	element_count = 0;
	usages = 0;
}

void Search_Engine::add_Entry(Searchable_Item new_Item)
{
	Item_List.push_back(new_Item);
	element_count++;
}

std::vector<Searchable_Item> Search_Engine::get_items_in_query(Query_new request) const
{
    //Valid CHECK!
    if (!request.get_is_valid())
    {
        std::vector<Searchable_Item> empty;
        return empty;
        //return {};
    }

    std::vector<Searchable_Item> return_vector;

    //Check all Items if the have request
    for (auto it = Item_List.begin(); it != Item_List.end(); ++it)
    {
        std::string temp_text = (*it).get_Information();
        std::string temp_adress = (*it).get_Adress();

        //Check if request is in it
        if (temp_text.find(request.get_query_text()) != std::string::npos || temp_adress.find(request.get_query_text()) != std::string::npos)
        {
            return_vector.push_back(*it);
        }
    }

    // Treffer nach Ranking sortieren: höchster Rank zuerst
    std::sort(return_vector.begin(), return_vector.end(),
        [](Searchable_Item const& a, Searchable_Item const& b) //Lamba regel, also einstellen der Sortierregel -> Vergleich nebenstehender Items,
        {
            return a.get_Rank() > b.get_Rank(); //Soll a vor b stehen? (Bool) -> Ja wenn ihr Rang höher ist
        });

    //Resizing the Vector
    if (return_vector.size() > request.get_max_results())
    {
        return_vector.resize(request.get_max_results());
    }

    usages++;
    return return_vector;
}

void Search_Engine::display()
{
	std::cout << "\n\n";
	std::cout << std::setw(25) << std::setfill('*') << std::right << "" << std::endl;
	std::cout << std::setw(25) << std::left << "Eninge Name " << engine_name << std::endl;
	std::cout << std::setw(25) << std::left << "Element Count " << element_count << std::endl;
	std::cout << std::setw(25) << std::left << "Usages " << usages << std::endl;
	std::cout << std::setw(25) << std::setfill('*') << std::right << "" << std::endl;

}