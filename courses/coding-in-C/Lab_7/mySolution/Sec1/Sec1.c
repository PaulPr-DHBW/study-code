#include <stdio.h>
#include <stdlib.h>

int input_variable_number();
void fill_array(int length, int* ptr_array);
void print_array(int length, int* ptr_array);


int main(void)
{
	int N = input_variable_number();
	printf("Moin");

	int* ptr_for_N = (int*)malloc(sizeof(int));
	if (ptr_for_N == NULL)
	{
		printf("\nError while malloc\n");
		return 1;
	}

	*ptr_for_N = N;

	free(ptr_for_N);

	int* ptr_array = (int*)calloc(N, sizeof(int));
	if (ptr_array == NULL)
	{
		printf("\nError while calloc\n");
		return 1;
	}

	fill_array(N, ptr_array);

	int* temp = (int*)realloc(ptr_array, 2 * N * sizeof(int));
	if (temp == NULL)
	{
		printf("\nFehler bei realloc\n");
		return 1;
	}

	ptr_array = temp;

	fill_array(2 * N, ptr_array);
	print_array(2 * N, ptr_array);

	free(ptr_array);
	return 0;
}

int input_variable_number() {
	int temp = 0;
	while (1) {
		printf("\nPlease enter an Integer N: ");
		if (scanf("%d", &temp) == 1 && temp > 0) { // gültige Zahl eingegeben
			break;
		}
		printf("Invalid input, try again.\n");
		while (getchar() != '\n'); // Eingabepuffer leeren
	}
	return temp;
}

void fill_array(int length, int* ptr_array)
{
	for (int i = 0; i < length; i++)
	{
		ptr_array[i] = i * i;
	}
}

void print_array(int length, int* ptr_array)
{
	printf("\n");
	for (int i = 0; i < length; i++)
	{
		printf(" %d ", ptr_array[i]);
	}
}
