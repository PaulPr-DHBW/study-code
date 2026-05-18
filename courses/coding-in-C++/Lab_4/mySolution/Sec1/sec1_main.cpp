#include <iostream>
#include <iomanip>
#include <string>

#include <cmath>

class vector_2D
{
private:
	int x;
	int y;

public:
	vector_2D(int x, int y)
		: x(x), y(y)
	{ }

	int get_x() const
	{
		return x;
	}

	int get_y() const
	{
		return y;
	}

	void display() const
	{
		std::cout << "(" << x << ", " << y << ")" << std::endl;
	}

	double get_length() const
	{ 
		return sqrt((pow(x, 2)) + pow(y, 2));
	}

	double get_length(int precision) const
	{
		double factor = pow(10.0, precision);
		double value = sqrt((pow(x, 2)) + pow(y, 2));
		return std::round(value * factor) / factor;
	}


	vector_2D operator + (vector_2D& adding_vector_2D)
	{ 
		return vector_2D(
			get_x() + adding_vector_2D.get_x(),
			get_y() + adding_vector_2D.get_y()
		);
	}

	vector_2D operator * (int scalar)
	{
		return vector_2D(
			get_x() * scalar,
			get_y() * scalar
		);
	}


	vector_2D& operator += (vector_2D const& adding_vector_2D)
	{
		this->x += adding_vector_2D.get_x();
		this->y += adding_vector_2D.get_y();
	}

};

vector_2D operator * (int scaler, vector_2D& right)
{
	return vector_2D(
		scaler * right.get_x(),
		scaler * right.get_y()
	);
}

std::ostream& operator << (std::ostream& stream, vector_2D& right)
{
	stream << "(" << right.get_x() << ", " << right.get_y() << ")" << std::endl;

	return stream;
}

bool operator == (vector_2D& left, vector_2D& right)
{ 
	return left.get_x() == right.get_x() && left.get_y() == right.get_y();
}

bool operator != (vector_2D& left, vector_2D& right)
{
	return left.get_x() != right.get_x() && left.get_y() != right.get_y();
}

int main(void)
{
	vector_2D AB(1, 2);
	vector_2D CD(2, 4);

	std::cout << AB;

	vector_2D AD = AB + CD;
	std::cout << AD;

	std::cout << "AB == CD" << std::boolalpha << (AB == CD) << std::endl;
	std::cout << "AB != CD" << std::boolalpha << (AB != CD) << std::endl;
}