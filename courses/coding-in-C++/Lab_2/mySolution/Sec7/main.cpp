#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

#include "Query.hpp"
#include "Seach_Engine.hpp"
#include "Searchable_Item.hpp"

int main(void)
{
	Search_Engine Paul_Google("Paul_Google");
	Searchable_Item DHBW("https://dhbw.com", "Alles rund ums Bachelor Studium", 80);
	Searchable_Item ChatGPT("https://openai.com", "Dein taeglicher Freund und helfer", highest_rank);
	Searchable_Item Wikipedia("https://wiki.de", "Alles rund um Studium und Schule", 10);

	Paul_Google.add_Entry(DHBW);
	Paul_Google.add_Entry(ChatGPT);
	Paul_Google.add_Entry(Wikipedia);

	Paul_Google.display();
	DHBW.display_Item();
	ChatGPT.display_Item();
	Wikipedia.display_Item();


	//Lets make a query
	Query_new search("Stud", 2);

	std::vector<Searchable_Item> Ergebnis = Paul_Google.get_items_in_query(search);
	

	std::cout << "Ergebis der Suche: " << search.get_query_text() << std::endl;
	for (auto x : Ergebnis)
	{
		x.display_Item();
	}





	return 0;
}