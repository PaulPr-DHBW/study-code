#include <iostream>
#include <iomanip>
#include <string>

class user
{
protected:
	std::string name;
	int id;

public:
	user(std::string name, int id);
	void print_info() const;
};

class student : public user
{
private:
	int matknr;
public:
	student(int manr, std::string name, int id);
	void print_info() const;
};

class instructor : public user
{
private: 
	std::string klasse;

public:
	instructor(std::string name, int id, std::string klasse);
	void print_info() const;
};




int main(void)
{
	//...


	return 0;
}

user::user(std::string name, int id)
	: name(name), id(id)
{
}
void user::print_info() const
{
	std::cout << "Name: " << name << std::endl;
}

student::student(int manr, std::string name, int id)
	: user(name, id), matknr(manr)
{
}
void student::print_info() const
{
	std::cout << "Name: " << name << std::endl;
	std::cout << "MANR: " << matknr << std::endl;
	std::cout << "Role: Student" << std::endl;
}

instructor::instructor(std::string name, int id, std::string klasse)
	: user(name, id), klasse(klasse)
{ }
void instructor::print_info() const
{
	std::cout << "Name: " << name << std::endl;
	std::cout << "Klasse " << klasse << std::endl;
	std::cout << "Role: Instructor" << std::endl;
}