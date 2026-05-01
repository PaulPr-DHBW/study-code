#include "Section2.hpp"
#include <string>
#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>

void print_vector(std::vector<int> const& data)
{
	for (int x : data)
	{
		std::cout << x << " ";
	}
	std::cout << std::endl;
}

void sort_inspect_data(std::vector<int>& data, int searched_value)
{
	std::vector<int>::iterator it_data;

	print_vector(data);
	std::sort(data.begin(), data.end());
	print_vector(data);


	it_data = std::find(data.begin(), data.end(), searched_value);
	if (it_data != data.end())
	{
		std::cout << "The searched Value: " << searched_value << " exists!" << std::endl;
		return;
	}
	std::cout << "The searched Value: " << searched_value << " does not exist!" << std::endl;
}

void noise_cleanup(std::vector<int>& data)
{
	std::vector<int>::iterator it_data;
	it_data = std::find(data.begin(), data.end(), -1); //-1 is the searched number here

	while (it_data != data.end())
	{
		*it_data = 0;
		it_data = std::find(data.begin(), data.end(), -1);
	}
	print_vector(data);

	std::reverse(data.begin(), data.end());
	print_vector(data);
}

void iterator_walk(std::vector<int>& data)
{
	std::vector<int>::iterator it_data;

	for (it_data = data.begin(); it_data < data.end(); it_data++)
	{
		std::cout << *it_data << " ";
	}
	std::cout << std::endl;
}