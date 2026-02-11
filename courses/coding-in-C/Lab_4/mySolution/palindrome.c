#include <stdio.h>

//function counts up the number of symbols until '\0'
int get_array_length(char* array)
{
    int count = 0;

    while(array[count] != '\0')
    {
        count++;
    }

    return count;
}

//function is meant to change the letter at certain places regarding the task
void change_letter(char* p_input_content, int content_length)
{
    int first_pos = 0;
    int sec_pos = 1;

    p_input_content[0] = 'E';
    p_input_content[1] = 'a';

}



int main()
{
    char s_content[] = "Curly bird catches the worm";
    char* p_content = s_content;

    //Section 1 - Steps 1 to 3, printing out the String
    
    printf("%s\n", s_content);
    change_letter(s_content, get_array_length(s_content));
    printf("%s\n", p_content);

    
    return 0;
}
