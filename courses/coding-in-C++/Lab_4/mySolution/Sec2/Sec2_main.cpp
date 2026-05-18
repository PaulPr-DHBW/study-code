#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>

// Class Shape
class shape
{
public:

	virtual double calculate_area() const = 0;

	virtual void display() const = 0;

	virtual ~shape() = default; // Da später mit Basisklassenpointern gearbeiter wird, ist an dieser Stelle ein Default-Konstruktor notwendig, welcher somit ebenfall in den Kindklassen auftritt

};


// Lets make a Circle
class circle : public shape
{
private:
	static constexpr float PI = 3.14f;
	float radius;

public:
	circle(float radius)
		: radius(radius)
	{ 
	}
	

	double calculate_area() const override // override zwingt den compiler, die virtuelle FUnktion zu überschreiben
	{
		return static_cast<double>(PI * pow(radius, 2));
	}
	void display() const override
	{
		std::cout << "Shape - Circle: " << calculate_area() << std::endl;
	}
};

//Lets make a Rectangle
class rectangle : public shape
{
private:
	double width;
	double height;

public:
	rectangle(double width, double height)
		: width(width), height(height)
	{ }

	double calculate_area() const override
	{
		return width*height;
	}

	void display() const override
	{
		std::cout << "Shape - Rectangle: " << calculate_area() << std::endl;
	}

};



//Testing in the main
int main(void)
{
	// Tests of Part 2
	/*
	shape some_shape;
	some_shape.display();

	circle wheel(17.7);
	wheel.display();

	rectangle square(4, 4);
	square.display();
	*/

	// Tests of Part 3
	circle c1(3);
	rectangle r1(4, 5);
	circle c2(10);
	rectangle r2(2, 8);

	shape* arr[4];

	arr[0] = &c1;
	arr[1] = &c2;
	arr[2] = &r1;
	arr[3] = &r2;

	for (auto it : arr)
	{
		(*it).display();
	}


	/*
	Reflection:
	a) Das "virtual" dient dazu dem Compiler mitzuteilen, dass diese Funktion bei der Vererbung überschrieben wird. Es ist somit das anlegen eines Bauplans für Funktionen
	b) "overriding" überschreibt Funktionen beim Vererben. "Overloading" beschreibt Funktionen/Operatoren gleichen Namens aber unterschiedlicher Funktion in unterschiedlichen Kontexten
	c) Reine Virtuelle Funktion ist eine Funktion dessen Implementation nicht feststeht und wird mit = 0 definiert
	c) Bauplanklasse, welche nicht instanziert werden können. Geben ein Grundgerüst mit FUnktionen und Attributen
	
	
	*/

}