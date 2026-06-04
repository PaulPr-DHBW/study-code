#include "AdjacencyList.hpp"

#include <iostream>


int main(void)
{
	AdjacencyList List(true, 4);



	List.add_Vertex(0, 1, 4);
	List.add_Vertex(0, 2, 2);
	List.add_Vertex(0, 3, 5);

	List.add_Vertex(1, 2, 3);
	List.add_Vertex(1, 3, 1);

	List.add_Vertex(2, 3, 7);

	List.print();

	List.print_shortest_path(0, 3);
	List.print_shortest_path(1, 0);



	return 0;


}