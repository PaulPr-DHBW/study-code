#ifndef SEARCH_ENGINE_HPP
#define SEARCH_ENGINE_HPP

#include <iostream>
#include <string>
#include <vector>

#include "Query.hpp"
#include "Searchable_Item.hpp"

class Search_Engine
{
private:
	std::string engine_name;
	int element_count;
	std::vector<Searchable_Item> Item_List;

public:
	static int usages;
	

	Search_Engine(std::string name);

	void add_Entry(Searchable_Item new_Item);
	std::vector<Searchable_Item> get_items_in_query(Query_new request) const;

	void display();


};





#endif // !SEARCH_ENGINE_HPP
