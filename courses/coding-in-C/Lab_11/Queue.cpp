#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define CONST_ENQUE 1
#define CONST_DEQUE 2
#define CONST_PRINT 3
#define CONST_SEARCH 4
#define CONST_EXIT 5

typedef struct Project
{
	int project_id;
	char* project_msg;

	struct Project* ptr_next_project;

} Project;

typedef struct Queue
{
	Project* ptr_head;

} Queue;

int menu();
int get_random_number(int min, int max);
char* get_string(const char* inptut_message);

void Enque(Queue* main_queue);
void Deque(Queue* main_queue);
void Delete(Queue* main_queue);
void Print(Queue* main_queue);
void Search(Queue* main_queue, char* search_msg);



int main()
{
	int menu_output = 0;
	Queue q_main;
	q_main.ptr_head = NULL;

	while (1)
	{
		menu_output = menu();

		switch (menu_output)
		{
		case CONST_ENQUE:
			Enque(&q_main);
			break;
		case CONST_DEQUE:
			Deque(&q_main);
			break;
		case CONST_PRINT:
			Print(&q_main);
			break;
		case CONST_SEARCH:
			Search(&q_main, get_string("Gib die zu suchende Project MSG ein: "));
			break;
		case CONST_EXIT:
			Delete(&q_main);
			return 0;
			break;

		default:
			printf("\nWrong Input please try again!");
		}

	}

	return 0;
}

int menu()
{
	char buffer[10];

	printf("\n\n\n");
	printf("\n--------------------------------------------------------");
	printf("\n--------------------------MENU--------------------------");
	printf("\n--------------------------------------------------------");
	printf("\nPlease choose an action:");
	printf("\nENQUE			(%d)", CONST_ENQUE);
	printf("\nDEQUE			(%d)", CONST_DEQUE);
	printf("\nPRINT			(%d)", CONST_PRINT);
	printf("\nSEARCH		(%d)", CONST_SEARCH);
	printf("\nEXIT			(%d)", CONST_EXIT);

	do
	{
		printf("\nPlease enter your Choice: ");

	} while (fgets(buffer, sizeof(buffer), stdin) == NULL);

	buffer[strcspn(buffer, "\n")] = '\0';

	return atoi(buffer);
}

int get_random_number(int min, int max)
{
	srand(time(NULL));

	return rand() % (max - min + 1) + min;
}

char* get_string(const char* inptut_message)
{
	char* output = NULL;
	char buffer[100];
	size_t str_length = 0;

	do
	{
		printf("\n%s ", inptut_message);

	} while (fgets(buffer, sizeof(buffer), stdin) == NULL);

	buffer[strcspn(buffer, "\n")] = '\0';

	str_length = strlen(buffer) + 1; // +1 for \0

	output = (char*)malloc(str_length*sizeof(char));
	if (output == NULL)
	{
		printf("\nError while get_String");
		//Delete queue;
		exit(0);
	}

	strcpy_s(output, str_length*sizeof(char), buffer);

	return output;
}

void Enque(Queue* main_queue)
{
	Project* new_Project = NULL;

	if (main_queue == NULL)
	{
		printf("\nNo Queue avaible");
		return;
	}

	new_Project = (Project*)malloc(sizeof(Project));
	if (new_Project == NULL)
	{
		printf("\nError while generating new Element");
		return;
	}

	new_Project->ptr_next_project = NULL;
	new_Project->project_id = get_random_number(0, 10);
	new_Project->project_msg = get_string("Please enter a Project message: ");

	//First Element
	if (main_queue->ptr_head == NULL)
	{
		main_queue->ptr_head = new_Project;
		return;
	}

	//Otherwise
	new_Project->ptr_next_project = main_queue->ptr_head;
	main_queue->ptr_head = new_Project;	

	return;
}

void Deque(Queue* main_queue)
{
	Project* iterator = NULL;

	if (main_queue == NULL || main_queue->ptr_head == NULL)
	{
		printf("\nNothing to dequeue found");
		return;
	}

	iterator = main_queue->ptr_head;

	//Elementeanzahl = 1
	if (iterator->ptr_next_project == NULL)
	{
		printf("\nDequing:");
		printf("\nProject ID:	%d", iterator->project_id);
		printf("\nProject MSG:	%s", iterator->project_msg);

		free(iterator->project_msg);
		free(iterator);

		main_queue->ptr_head = NULL;
		return;
	}


	//Fall Elementeanzahl > 2
	while (iterator->ptr_next_project->ptr_next_project != NULL)
	{
		iterator = iterator->ptr_next_project;
	}

	printf("\nDequing:");
	printf("\nProject ID:	%d", iterator->ptr_next_project->project_id);
	printf("\nProject MSG:	%s", iterator->ptr_next_project->project_msg);

	free(iterator->ptr_next_project->project_msg);
	free(iterator->ptr_next_project);
	iterator->ptr_next_project = NULL;

	return;
}

void Delete(Queue* main_queue)
{
	if (main_queue == NULL || main_queue->ptr_head == NULL)
	{
		return;
	}

	Project* iterator = main_queue->ptr_head;
	Project* help = NULL;

	while (iterator != NULL)
	{
		help = iterator->ptr_next_project;
		free(iterator->project_msg);
		free(iterator);
		iterator = help;
	}
}

void Print(Queue* main_queue)
{
	if (main_queue == NULL || main_queue->ptr_head == NULL)
	{
		printf("\nNothing to print");
		return;
	}

	Project* iterator = main_queue->ptr_head;

	while (iterator != NULL)
	{
		printf("\nProject ID:		(%d)", iterator->project_id);
		printf("\nProject MSG:		(%s)", iterator->project_msg);
		printf("\n");

		iterator = iterator->ptr_next_project;
	}
}

void Search(Queue* main_queue, char* search_msg)
{
	if (main_queue == NULL || main_queue->ptr_head == NULL)
	{
		printf("\nNothing to be searched");
		return;
	}

	Project* iterator = main_queue->ptr_head;

	while (iterator != NULL)
	{
		if (0 == strcmp(iterator->project_msg,search_msg))
		{
			printf("\nFound Element:");
			printf("\nProject ID:		(%d)", iterator->project_id);
			printf("\nproject MSG:		(%s)", iterator->project_msg);
			return;
		}

		iterator = iterator->ptr_next_project;
	}

	printf("\nNot Element found!");

}
