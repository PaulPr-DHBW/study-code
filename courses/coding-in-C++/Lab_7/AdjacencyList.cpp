#include "AdjacencyList.hpp"

#include <iostream>
#include <iomanip>
#include <string>

#include <vector>
#include <list>
#include <numeric>
#include <algorithm>


void AdjacencyList::add_Vertex(int Start, int Destionation, int value)
{
	//Pr+fen ob Start und Destination Valid sind
	if (!is_valid_index(Start) || !is_valid_index(Destionation))
	{
		return;
	}



	//Schauen ob ungerichteter Graph?
	if (is_bidirectional)
	{
		//Neue Kante anlegen
		Edge new_edge1(Destionation, value);
		Edge new_edge2(Start, value);

		vertex_List[Start].push_back(new_edge1);
		vertex_List[Destionation].push_back(new_edge2);

		return;
	}

	//Ansonsten:
	Edge new_edge1(Destionation, value);
	vertex_List[Start].push_back(new_edge1);
}

bool AdjacencyList:: is_valid_index(int index)
{
	return index >= 0 && index < vertex_List.size();
}


Pathresult AdjacencyList::find_shortest_path(int Start, int Destination)
{
	Pathresult result;

	//Anlegen von Konstanten
	const int node_amount = vertex_List.size();
	const int infinite_distance = std::numeric_limits<int>::max();

	result.path_length = infinite_distance;


	//Pr+fen ob Start und Destination Valid sind
	if (!is_valid_index(Start) || !is_valid_index(Destination))
	{
		return result;
	}



	//Anlegen von Hilfstabellen
	std::vector<int> distances(node_amount, infinite_distance);
	std::vector<int> previous_index(node_amount, -1);
	std::vector<bool> visited(node_amount, false);

	//Vorbereitung
	distances[Start] = 0;

	//Hauptschleife
	for (int step = 0; step < node_amount; ++step)
	{
		//Finden des unbesuchten objektes des kleinsten Abstands:
		int current_index = -1;
		int smallest_distance = infinite_distance;

		for (int i = 0; i < node_amount; i++)
		{
			if (!visited[i] && distances[i] < smallest_distance)
			{
				current_index = i;
				smallest_distance = distances[i];
			}
		}

		//Schauen ob wir ein Objekt gefunden haben
		if (current_index == -1)
		{
			break;
		}

		//Obejkt als besucht markieren
		visited[current_index] = true;

		//Sind wir am Ende?
		if (current_index == Destination)
		{
			break;
		}

		//Alle Nachbarn untersuchen
		for (const Edge& edge : vertex_List[current_index])
		{
			//Ist der Nachbar bereits besucht? -> besucht bedeutet geringster Abstand für diesen Knoten bereits gefunden
			if (visited[edge.index_to])
			{
				continue;
			}

			//Neue Distance aus dem current Index und dem Kantengwicht berechnen
			int new_distance = distances[current_index] + edge.value;

			//Ist diese Distance geringer > Update/Relaxation
			if (new_distance < distances[edge.index_to])
			{
				distances[edge.index_to] = new_distance;
				previous_index[edge.index_to] = current_index;
			}

		}


	}

	//Wurde das Ende überhaupt erreicht?
	if (distances[Destination] == infinite_distance)
	{
		return result;
	}

	//Über Previous Nodes Rückwärts gehen und in einen Vector pushen
	int current_index = Destination;

	while (current_index != -1) //Nur Knoten Start hat noch Vorgänger -1
	{
		result.index_order.push_back(current_index);
		current_index = previous_index[current_index];
	}

	//Invertieren
	std::reverse(result.index_order.begin(), result.index_order.end());

	result.path_length = distances[Destination];
	result.path_found = true;

	return result;

}


void AdjacencyList::print_shortest_path(int start_index, int destination_index)
{
	Pathresult result = find_shortest_path(start_index, destination_index);

	if (!result.path_found)
	{
		std::cout << "No shortest path found!" << std::endl;
		return;
	}

	std::cout << "Shortest path from " << start_index
		<< " to " << destination_index << ": ";

	for (int i = 0; i < static_cast<int>(result.index_order.size()); ++i)
	{
		std::cout << result.index_order[i];

		if (i < static_cast<int>(result.index_order.size()) - 1)
		{
			std::cout << " -> ";
		}
	}

	std::cout << std::endl;
	std::cout << "Total distance: " << result.path_length << std::endl;
	std::cout << std::endl;
}

void AdjacencyList :: print() const
{
	for (int i = 0; i < vertex_List.size(); ++i)
	{
		std::cout << i << ": ";

		for (const Edge& edge : vertex_List[i])
		{
			std::cout << edge.index_to << "(" << edge.value << ")" << "-->";
		}

		std::cout << "NULL" << std::endl;
		std::cout << std::endl;
	}
}