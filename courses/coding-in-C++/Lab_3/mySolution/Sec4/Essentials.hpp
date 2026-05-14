#ifndef ESSENTIALS_HPP
#define ESSENTIALS_HPP
#include <iostream>
#include <string>
#include <vector>

//------------------------------------------
//-----------------Inventory----------------
//------------------------------------------
class inventory
{
private:
	static constexpr int max_items = 10;
	static constexpr int min_items = 0;
	std::vector<std::string> stored_items;

public:
	inventory()
	{ }

	void display() const;
	bool is_empty() const;
	bool is_full() const;
	
	bool add_item(std::string new_item);
	bool remove_last_item();

	std::string get_last_item() const
	{
		if (is_empty())
		{
			return "";
		}

		return stored_items.back();
	}
};


//------------------------------------------
//-----------------Weapon-------------------
//------------------------------------------
class weapon
{
private:
	std::string name;
	int damage_value;

public:
	weapon(std::string name ,int dmg_value);

	void display() const;
	void upgrade_weapon(int points);
	int get_damage() const;
};



#endif // !ESSENTIALS_HPP
