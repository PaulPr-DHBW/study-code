#ifndef SECTION_1_HPP
#define SECTION_1_HPP

#include <iostream>
#include <string>

class BankAccount
{
private:
	std::string owner;
	double balance; //{}, initialises the Balance with 0

public:
	BankAccount(double new_Balance = 0, std::string new_owner = "Max Mustermann");

	void set_Owner(std::string new_Owner);
	std::string get_Owner() const;

	void deposit(double amount);
	void withdraw(double amount);
	
	double get_Balance() const;
	void get_Account_Info() const;
};




#endif // !SECTION_!_HPP
