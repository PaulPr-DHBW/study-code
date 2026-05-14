#ifndef CHARACTERS_HPP
#define CHARACTERS_HPP

#include "Essentials.hpp"

#include <iostream>
#include <iomanip>
#include <vector>
#include <string>


//------------------------------------------
//-----------------character----------------
//------------------------------------------
class character
{
private:
	static int number_of_characters;
	static const int max_level = 10;
	static const int min_level = 1;

protected:
	std::string name;
	int health_points;
	int level;
	inventory character_inventory;
	weapon character_weapon;

public:
	character(std::string name, int health_points, int level, std::string weapon_name, int weapon_damage);

	virtual void display() const = 0;
	inventory& get_inventory();
	void level_up();



	friend class healer;
};



//------------------------------------------
//-----------------Warrior------------------
//------------------------------------------
class warrior : public character
{
protected:
	int weapon_skill_points;

public:
	warrior(std::string name, int health_points, int level, std::string weapon_name, int weapon_damage, int weapon_skill_points);

	void display() const override;
};


//------------------------------------------
//-----------------Mage---------------------
//------------------------------------------
class mage : public character
{
protected:
	int mana_skill_points;

public:
	mage(std::string name, int health_points, int level, std::string weapon_name, int weapon_damage, int mana_skill_points);

	void display() const override;
};

//------------------------------------------
//-----------------Thief--------------------
//------------------------------------------
class thief : public warrior
{
public:
	thief(std::string name, int health_points, int level, std::string weapon_name, int weapon_damage, int weapon_skill_points);

	thief& steal(character& target);
};

//------------------------------------------
//-----------------healer-------------------
//------------------------------------------
class healer : public mage
{
private:
	int heal_power;

	int calculate_heal_power();

public:
	healer(std::string name, int health_points, int level, std::string weapon_name, int weapon_damage, int mana_skill_points);

	healer& heal(character& target);

};

#endif // !CHARACTERS_HPP
