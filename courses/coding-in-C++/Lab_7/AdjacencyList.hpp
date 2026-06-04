#ifndef ADJACENCYLIST_HPP
#define ADJACENCYLIST_HPP

#include <iostream>

#include <vector>
#include <list>

struct Edge
{
	int index_to;
	int value;

	Edge(int index_to, int value)
		: index_to(index_to), value(value)
	{ }

};

//Struct mit welchem der Djikstra das Resultat zurückgeben kann
struct Pathresult
{
	std::vector<int> index_order;
	bool path_found;
	int path_length;

	Pathresult()
	{
		path_found = false;
		path_length = 0;
	}

};



//Klasse der Liste
class AdjacencyList
{
private:
	std::vector<std::list<Edge>> vertex_List;
	bool is_bidirectional;

	bool is_valid_index(int index);


public:
	AdjacencyList(bool is_bidrectional, int node_amount)
		: is_bidirectional(is_bidrectional), vertex_List(node_amount)
	{ }

	void add_Vertex(int Start, int Destionation, int value);

	Pathresult find_shortest_path(int Start, int Destination);

	void print_shortest_path(int Start, int Destination);

	void print() const;
};



#endif // !ADJACENCYLIST_HPP



