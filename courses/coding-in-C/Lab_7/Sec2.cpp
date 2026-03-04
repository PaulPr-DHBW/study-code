#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Node
{
	double node_value;
	struct Node* next_node_ptr;
} Node;


Node* add_new_element(double new_value, Node* head)
{
	Node* new_node = (Node*)malloc(sizeof(Node));
	if (new_node == NULL)
	{
		printf("Fehler beim anlegen eines neuen Elements!\n");
		return head;
	}

	new_node->next_node_ptr = NULL;
	new_node->node_value = new_value;

	//going to the last element in the list
	if (head == NULL)
	{
		head = new_node;
		return head;

	}
	
	//iterator pointer
	Node* iterator = head;

	while (iterator->next_node_ptr != NULL)
	{
		iterator = iterator->next_node_ptr;
	}

	iterator->next_node_ptr = new_node;

	return head;
	
}


int main(void)
{
	Node* head = NULL;

	head = add_new_element(2, head);

	
	
	return 0;
}
