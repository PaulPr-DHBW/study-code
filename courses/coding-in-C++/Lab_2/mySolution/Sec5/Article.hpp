#ifndef ARTICLE_HPP
#define ARTICLE_HPP

#include <iostream>
#include <string>

class Article {

private:
    std::string name;
    double price;
    int stock;
    std::string* category;
    int id;

public:

    Article(std::string name, double price, int stock, std::string category, int id)
        : name(name), price(price), stock(stock), id(id)
    {
        this->category = new std::string;
        *this->category = category;
    }

    void setPrice(double const price) {
        this->price = price;
    }

    void sell(int const amount) {
        if (amount >= stock)
        {
            stock = 0;
            return;
        }
        
        stock -= amount;
    }

    void restock(int const amount) {
        if (amount <= 0)
        {
            return;
        }
        
        this->stock += amount;
    }

    double applyDiscount(double const percent) {
       
        if (percent > 100)
        {
            return price;
        }
        
        price = price - price * percent / 100;
        return price;
    }

    double getPrice()const {
        return price;
    }

    bool isAvailable()const {
        if (stock > 0)
            return true;
        else
            return false;
    }

    void printInfo()const {
        std::cout << "Article: " << name << std::endl;
        std::cout << "Category: " << *category << std::endl;
        std::cout << "Price: " << price << std::endl;
        std::cout << "Stock: " << stock << std::endl;
        std::cout << "ID: " << id << std::endl;
    }
};

#endif // !ARTICLE_HPP
