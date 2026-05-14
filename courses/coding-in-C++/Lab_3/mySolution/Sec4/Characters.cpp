#include "Characters.hpp"
#include "Essentials.hpp"

#include <iostream>
#include <iomanip>
#include <string>

#include <vector>
#include <algorithm>

int character::number_of_characters = 0;


//------------------------------------------
//-----------------character----------------
//------------------------------------------
character::character(std::string name, int health_points, int level, std::string weapon_name, int weapon_damage)
	: name(name), health_points(health_points), character_weapon(weapon(weapon_name, weapon_damage))
{ 
	//level muss größer 0 <= 10 sein
	if (level <= max_level && level >= min_level)
	{
		this->level = level;
		return;
	}
	this->level = min_level;

	number_of_characters++;
}

inventory& character::get_inventory()
{ 
	return character_inventory;
}

void character::level_up()
{ 
	if (level + 1 > max_level)
	{
		return;
	}
	++level;
}



//------------------------------------------
//-----------------Warrior------------------
//------------------------------------------
warrior::warrior(std::string name, int health_points, int level, std::string weapon_name, int weapon_damage, int weapon_skill_points)
	: character(name, health_points, level, weapon_name, weapon_damage), weapon_skill_points(weapon_skill_points)
{ }

void warrior::display() const
{ 
	std::cout << std::setw(43) << std::setfill('-') << std::left << "" << std::endl;
	std::cout << std::setfill(' ') << "Displaying Warrior" << std::endl;
	std::cout << std::setfill(' ') << "Name: " << name << std::endl;
	std::cout << std::setfill(' ') << "Level: " << level << std::endl;
	std::cout << std::setfill(' ') << "HP: " << health_points<< std::endl;
	std::cout << std::setfill(' ') << "Weapon Skill: " << weapon_skill_points << std::endl;
	
	character_inventory.display();
	character_weapon.display();
	std::cout << std::setw(343) << std::setfill('-') << std::left << "" << std::endl;

}



//------------------------------------------
//-----------------Mage---------------------
//------------------------------------------
mage::mage(std::string name, int health_points, int level, std::string weapon_name, int weapon_damage, int mana_skill_points)
	: character(name, health_points, level, weapon_name, weapon_damage), mana_skill_points(mana_skill_points)
{ }

void mage::display() const
{ 
	std::cout << std::setw(43) << std::setfill('-') << std::left << "" << std::endl;
	std::cout << std::setfill(' ') << "Displaying Mage" << std::endl;
	std::cout << std::setfill(' ') << "Name: " << name << std::endl;
	std::cout << std::setfill(' ') << "Level: " << level << std::endl;
	std::cout << std::setfill(' ') << "HP: " << health_points << std::endl;
	std::cout << std::setfill(' ') << "Mana Skill: " << mana_skill_points << std::endl;

	character_inventory.display();
	character_weapon.display();
	std::cout << std::setw(343) << std::setfill('-') << std::left << "" << std::endl;

}



//------------------------------------------
//-----------------Thief--------------------
//------------------------------------------
thief::thief(std::string name, int health_points, int level, std::string weapon_name, int weapon_damage, int weapon_skill_points)
	: warrior(name, health_points, level, weapon_name, weapon_damage, weapon_skill_points)
{ }

thief& thief::steal(character& target)
{
	auto& target_inventory = target.get_inventory();

	std::string last_item = target_inventory.get_last_item();

	if (last_item == "")
	{
		return *this;
	}

	if (this->character_inventory.add_item(last_item))
	{
		target_inventory.remove_last_item();
	}

	return *this;
}

//------------------------------------------
//----------------Healer--------------------
//------------------------------------------
healer::healer(std::string name, int health_points, int level, std::string weapon_name, int weapon_damage, int mana_skill_points)
	: mage(name, health_points, level, weapon_name, weapon_damage, mana_skill_points)
{ 
	heal_power = calculate_heal_power();
}

healer& healer::heal(character& target)
{

	target.health_points += heal_power;
	return *this;
}

int healer::calculate_heal_power()
{
	return this->mana_skill_points * this->level * this->character_weapon.get_damage() / 10;
}