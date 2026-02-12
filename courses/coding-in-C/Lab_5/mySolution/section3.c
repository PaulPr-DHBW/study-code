/*
*   File:           section3.c (Main)
*   Author:         Paul Prätorius
*   Version:        1.0
*   Release Date:   12.02.2026
*/



//Lets inlcude all relevant libs
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Prints out Menu and allocates needed memory (array) to an pointer -> redirects init null pointer to allocated pointer
void init_function(int **ptr_particle, int* array_length)
{
    srand(time(NULL));
    
    do
    {
        printf("Please enter the size of your particle Array.\n");
        printf("Please make sure its greater 6!\n Input: ");
    } while (!scanf(" %d", array_length) || *array_length < 6);

    //one dereferencation -> changing adress pointer ptr_particle is pointing to (now its the start of the calloc array)
    *ptr_particle = calloc(*array_length, sizeof(int));   
}

//Initialises the array according to task. places 2,4,6 are set to 1 (all others are set to 0 by calloc)
void set_array(int *ptr_particle, int* array_length)
{
    for(int i = 0; i < *array_length; i++)
    {
        if(i == 1 || i == 3 || i == 5)
        {
            *(ptr_particle + i) = 1;
        }
    }

}

//returns a random number between max and min
int get_rand_number(int max, int min)
{
    return (min + (rand() % (max - min + 1)));
}

//here it gets real...
int main (void)
{
    //Lets init the main list
    int *ptr_particle = NULL;
    int array_length = 0;

    init_function(&ptr_particle, &array_length);
    set_array(ptr_particle, &array_length);


    //Lets init a temp array, used to store movement of particles
    int *ptr_temp_array = (int*)calloc(array_length, sizeof(int));


    //init of a number counter, used for upcoming iteration and counting which Time we are on
    int number_round = 0;

    while(number_round < 7)
    {   
        //Reset of the help array to all 0s, so we can store new future moves
        for(int i = 0; i < array_length; i++)
        {
            ptr_temp_array[i] = 0;
        }

        //Main movement logic, if random number is '0' check left movement and '1' for right
        //If there is already a '1' in help array then its a collision!
        for(int i = 0; i < array_length; i++)
        {
            if(ptr_particle[i])
            {
                int temp_random = get_rand_number(1,0);
                if(temp_random && i +1 < array_length)
                {
                    if(ptr_temp_array[i+1])
                    {
                        printf("Collision on index %d\n", i+1);
                        ptr_temp_array [i+1] = 0; 
                    }
                    else
                    {
                        ptr_temp_array[i+1] = 1;
                    }
                }
                else if(temp_random && i == array_length-1)
                {
                    ptr_temp_array[i] = 1;
                }
                else if(!temp_random && i - 1 >= 0)
                {
                    if(ptr_temp_array[i-1])
                    {
                        printf("Collision on index %d\n", i-1);
                        ptr_temp_array [i-1] = 0; 
                    }
                    else
                    {
                        ptr_temp_array[i-1] = 1;
                    }

                }
                else if(!temp_random && i == 0)
                {
                    ptr_temp_array[i] = 1;
                }
            }


        }

        //lets print the move:
        printf("Time %d: ", number_round+1);
        for(int i = 0; i < array_length; i++)
        {   
            printf("%3d", ptr_temp_array[i]);
        }
        printf("\n");

        //now lets merge help move to main pointer
        for(int i = 0; i < array_length; i++)
        {
            ptr_particle[i] = ptr_temp_array[i];
        }


        number_round++;
    }


    free(ptr_particle);
    free(ptr_temp_array);
    return 0;
}