#include <iostream>
#include <string>
#include <iomanip>
using namespace std; // We dont use the using key Word! Safety Reasons

class Article {
public:
    string name;
    double price;
    int stock;
    string* category;
    int id;

    //The initalising list is missing
    Article(string name, double price, int stock, string category, int id) {
        name = name; //No effect, we need the this póinter
        price = price; //No effect, we need the this póinter
        stock = stock; //No effect, we need the this póinter
        this->id = id;
        this->category = new string; //Destrucotr is missing, memory leak
        *this->category = category;
    }

    void setPrice(double price) {
        price = price; //This pointer is missing
    }

    void sell(int amount) {
        stock = stock - amount; //This pointer is missing
    }

    void restock(int amount) { 
        this->stock += amount; //Amount is allowed to be negative
    }

    double applyDiscount(double percent) {
        price = price - price * percent / 100;
        return price;
    }

    double getPrice() {
        return price;
    }

    bool isAvailable() {
        if (stock > 0)
            return true;
        else
            return false;
    }

    void printInfo() {
        cout << "Article: " << name << endl;
        cout << "Category: " << *category << endl;
        cout << "Price: " << price << endl;
        cout << "Stock: " << stock << endl;
        cout << "ID: " << id << endl;
    }
};

int main() {
    Article a("Laptop", 999.99, 10, "Electronics", 101);

    a.sell(15);
    a.restock(-5); //Restock being negativ doenst make sense
    a.price = -100; //Same for the price
    a.applyDiscount(150); //Discount shouldnt be able to be above 100

    if (a.isAvailable()) cout << "Article available" << endl; //{} should be used

    a.printInfo();
}