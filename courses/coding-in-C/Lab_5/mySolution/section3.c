#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void init_function(int **ptr_particle, int* array_length)
{
    srand(time(NULL));
    
    do
    {
        printf("Please enter the size of your particle Array.\n");
        printf("Please make sure its greater 6!\n Input: ");
    } while (!scanf(" %d", array_length) || *array_length < 6);

    *ptr_particle = calloc(*array_length, sizeof(int));   
}

void set_array(int *ptr_particle, int* array_length)
{
    for(int i = 0; i < *array_length; i++)
    {
        if(i == 1 || i == 3 || i == 5)
        {
            *(ptr_particle + i) = 1;
            continue;
        }
        *(ptr_particle + i) = 0;
    }

}

int get_rand_number(int max, int min)
{
    return (min + (rand() % (max - min + 1)));
}


int main (void)
{
    int *ptr_particle = NULL;
    int array_length = 0;

    init_function(&ptr_particle, &array_length);
    set_array(ptr_particle, &array_length);

    int *ptr_temp_array = (int*)calloc(array_length, sizeof(int));

    //Now it comes to Moving the dots, starting from the left an copying all movements into temp array, if there als is a dot its supposed to be used to,
    //this index has the opportunity to move away or it will be a collision

    int number_round = 0;

    while(number_round < 7)
    {   
        //lets reset help
        for(int i = 0; i < array_length; i++)
        {
            ptr_temp_array[i] = 0;
        }

        //now lets check the main one for 1s and copy their movement into help
        //random 0 -> left, random 1 -> right
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