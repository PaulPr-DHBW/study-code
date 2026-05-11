#include "Section1.hpp"

#include <iostream>
#include <iomanip>
#include <string>

BankAccount::BankAccount(double new_Balance ,std::string new_owner)
	: balance(new_Balance), owner(new_owner)
{
}

void BankAccount::set_Owner(std::string new_Owner)
{
	this->owner = new_Owner;
}
std::string BankAccount::get_Owner() const 
{
	return this->owner;
}
void BankAccount::deposit(double amount)
{
	if (amount > 0)
	{
		this->balance += amount;
	}
}
void BankAccount::withdraw(double amount)
{
	if (amount > 0)
	{
		this->balance -= amount;
	}
}
double BankAccount::get_Balance() const 
{
	return this->balance;
}
void BankAccount::get_Account_Info() const
{
	std::cout << std::setfill('*') << std::setw(30) << "" << std::endl;

	std::cout << std::setfill(' ');
	std::cout	<< std::left << std::setw(10) << "Owner:"
				<< this->owner << std::endl;

	std::cout	<< std::left << std::setw(10) << "Balance:"
				<< std::fixed << std::setprecision(2)
				<< this->balance << " EUR" << std::endl;

	std::cout << std::setfill('*') << std::setw(30) << "" << std::endl;

	std::cout << std::setfill(' ');
}