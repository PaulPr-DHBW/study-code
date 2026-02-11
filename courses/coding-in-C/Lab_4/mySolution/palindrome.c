#include <stdio.h>

int get_array_length(char* array)
{
    int count = 0;

    while(array[count] != '\0')
    {
        count++;
    }

    return count;
}

void change_letter(char* p_input_content, int content_length)
{

}



int main()
{
    char s_content[] = "Curly bird catches the worm";
    char* p_content = s_content;

    //Section 1 - Steps 1 to 3, printing out the String
    /*printf("%s\n", s_content);
    printf("%s\n", p_content);
    */

    
    return 0;
}
