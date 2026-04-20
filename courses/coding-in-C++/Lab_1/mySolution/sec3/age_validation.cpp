#include <iostream>
#include <string>
#include <cstdint>
#include <limits>

namespace validation
{
    bool check_adult(u_int8_t age)
    {
        if (age >= 18)
        {
            return true;
        }
        
        return false;
    }

    bool check_senior(u_int8_t age)
    {
        if (age >= 65)
        {
            return true;
        }
        
        return false;
    }

}

void print_validation(u_int8_t& age)
{
    std::cout << "You are " << static_cast<int>(age) << " Years old." << std::endl;

    if (validation::check_adult(age))
    {
        std::cout << "That means you are an adult." << std::endl; 
    }
    else if (validation::check_senior(age))
    {
        std::cout << "That means you are a senior." << std::endl; 
    }
    else 
    {
         std::cout << "That means you are still a minor." << std::endl;
    }


}

u_int8_t read_in()
{
    int input;
    while (true)
    {
        std::cout << "Please enter your age: ";
        if (!(std::cin >> input))
        {
            std::cout << "Your input was not a number!" << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

        if (input < 0 || input > 150)
        {
            std::cout << "Please enter a valid age between 0 and 150." << std::endl;
            continue;
        }

        return static_cast<uint8_t>(input);
    }
}

int main(void)
{
    u_int8_t age = read_in();

    print_validation(age);

    return 0;
}