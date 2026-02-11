#include <stdio.h>

int main()
{
    char s_content[] = "Curly bird catches the worm";
    char* p_content = s_content;

    printf("%s\n", s_content);
    printf("%s\n", p_content);

    return 0;
}
