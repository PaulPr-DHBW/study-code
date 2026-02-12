#include <stdio.h>
#include <string.h>

int main(int argc, char** argv)
{
    //First try on how main signature funcitons, char** argv is a pointer on a pointer which then points to a string / char array
    printf("Menge an eingelesenen Daten: %d\n", argc);
    printf("0tes Element: %s\n", argv[0]);
    printf("1tes Element: %s\n", argv[1]);

    //Iterating over all Arguments with []
    for(int i = 0; i < argc; i++)
    {
        printf("Argument %d at adress \"%p\" has content: %s (length: %d)\n ", i, argv[i], argv[i], strlen(argv[i])-1);
    }

    //iterating over all Arguments with dereferencing
    for(int i = 0; i < argc; i++)
    {
        printf("Argument %d at adress \"%p\" has content: %s (length: %d)\n ", i, *(argv+i), *(argv+i), strlen(*(argv+i))-1);
    }

    return 0;
}