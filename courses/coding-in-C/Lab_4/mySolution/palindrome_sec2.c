#include <stdio.h>
#include <string.h>

void check_palindrome(char* input_array, int length_array)
{
    

}

void get_userinput(char* input_array, int size_of_input_array)
{
    do
    {
        printf("Please enter a word, to check if its a palindrome: \n");

    } while (fgets(input_array, size_of_input_array, stdin) != NULL);

    input_array[strcspn(input_array, "\n")] = '\0';
}


int main ()
{
    char userinput_content[100];

    get_userinput(userinput_content, sizeof(userinput_content));

    check_palindrome(userinput_content, strlen(userinput_content));



    return 0;
}
