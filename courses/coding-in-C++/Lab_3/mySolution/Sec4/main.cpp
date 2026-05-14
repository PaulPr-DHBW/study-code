#include "Characters.hpp"
#include "Essentials.hpp"

#include <iostream>
#include <string>

int main(void)
{
	//Anlegen von einem Magier
	mage dumbeldore("Dumbledor", 100, 9, "Elder-Wand", 999, 800);
	dumbeldore.get_inventory().add_item("Resurection Stone");
	dumbeldore.display();

	//Anlegen eines Diebes
	thief robin_hood("Robin Hood", 50, 5, "Bow", 150, 200);
	robin_hood.steal(dumbeldore);

	dumbeldore.display();
	robin_hood.display();




	return 0;
}