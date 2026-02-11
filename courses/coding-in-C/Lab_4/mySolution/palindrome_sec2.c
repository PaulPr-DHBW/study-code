#include <stdio.h>
#include <string.h>

void check_palindrome(char* input_array, int length_array)
{
    for(int i = 0; i < length_array; i++)
    {
        if(input_array[i] != input_array[length_array-i])
        {   
            printf("Your provided Word: %s \nis not a palindrome.", input_array); 
            return;
        }
        
    }

    printf("Your provided Word: %s \nis a palindrome.", input_array);

}

void get_userinput(char* input_array, int size_of_input_array)
{
    do
    {
        printf("Please enter a word, to check if its a palindrome: \n");

    } while (fgets(input_array, size_of_input_array, stdin) == NULL);

    input_array[strcspn(input_array, "\n")] = '\0';
}


int main ()
{
    char userinput_content[100];

    get_userinput(userinput_content, sizeof(userinput_content));

    check_palindrome(userinput_content, strlen(userinput_content)-1); //-1 da terminierungs symbol



    return 0;
}
