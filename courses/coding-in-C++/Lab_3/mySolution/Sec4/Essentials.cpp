#include "Essentials.hpp"

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>




void inventory::display() const
{ 
	std::cout << std::setw(33) << std::setfill('*') << std::left << "" << std::endl;

	for (auto it = stored_items.begin(); it < stored_items.end(); ++it)
	{
		std::cout << std::setfill(' ') << std::left << *it << std::endl;
	}
	std::cout << std::setw(33) << std::setfill('*') << std::left << "" << std::endl;
}

bool inventory::is_empty() const
{ 
	return stored_items.empty();
}

bool inventory::is_full() const
{ 
	return max_items == stored_items.size();
}

bool inventory::add_item(std::string new_item)
{ 
	if (!is_full())
	{
		stored_items.push_back(new_item);
		return true;
	}

	std::cout << "Inventory is full" << std::endl;
	return false;
}

bool inventory::remove_last_item()
{ 
	if (!is_empty())
	{
		stored_items.pop_back();
		return true;
	}

	std::cout << "Inventory is empty" << std::endl;
	return false;
}



weapon::weapon(std::string name, int dmg_value)
	: name(name), damage_value(dmg_value)
{ }

void weapon::display() const
{ 
	std::cout << std::setw(33) << std::setfill('*') << std::left << "" << std::endl;
	std::cout << std::setfill(' ') << "Waffenname: " << name << std::endl;
	std::cout << std::setfill(' ') << "Damage: " << damage_value << std::endl;
	std::cout << std::setw(33) << std::setfill('*') << std::left << "" << std::endl;
}

void weapon::upgrade_weapon(int points)
{ 
	damage_value += points;
}

int weapon::get_damage() const
{ 
	return damage_value;
}
