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
void change_letter_sec1(char* p_input_content, int content_length)
{
    int first_pos = 0;
    int sec_pos = 1;
    int rel_pos = 2; // Step 6, second char gets changed

    //Section 1 step 4 
    //p_input_content[0] = 'E';
    //p_input_content[1] = 'a';

    //Section 1 step 6
    if(content_length >= rel_pos)
    {
        p_input_content[rel_pos-1] = 'c'; //second element ist "1" in Array
    }
}



int main()
{
    char s_content_sec1_step1[] = "Curly bird catches the worm";
    char* p_content = s_content_sec1_step1;

    //Section 1 - Steps 1 to 3, printing out the String
    
    /*printf("%s\n", s_content);
    change_letter_sec1(s_content, get_array_length(s_content));
    printf("%s\n", p_content);
    */

    //Section 1 - Steps 5 to 8

    char s_content_sec1_step7[] = "AAtions speak louder than words";
    printf("%s\n", s_content_sec1_step7);
    change_letter_sec1(s_content_sec1_step7, get_array_length(s_content_sec1_step7));
    printf("%s\n", s_content_sec1_step7);
    
    return 0;
}
