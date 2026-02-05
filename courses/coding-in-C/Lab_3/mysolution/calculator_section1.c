#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

const char operations[5] = {'+','-','*','/','E'};


void clearBuffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}


char menu()
{
    while(1)
    {
        printf("Welcome to today calculating session.\n");
        printf("Please choose an operation:\nOptions:");

        for(int i = 0; i < 4; i++)
        {
            printf("\t%c\n", operations[i]);
        }

        printf("\nOr Exit with (E)\nInput: ");

        char temp;
        if (scanf(" %c", &temp) != 1)
            //delay Error
            continue;

        for(int i = 0; i < 5; i++)
        {
            if(temp == operations[i])
                return operations[i];
        }
    }
}

void output(float sol)
{
    printf("\nSolution: %.2f\n\n", sol);
}

int main()
{
    float f1, f2;

    while(1)
    {
        char op = menu();
        system("clear");
        if(op == 'E' || op == 'e')
        {
            //delay
            break;
        }

        printf("Input first number: ");
        if(scanf("%f", &f1) != 1)
        {
            clearBuffer();
            continue;
            
        }

        printf("Input second number: ");
        if(scanf("%f", &f2) != 1)
        {
            clearBuffer();
            continue;
            
        }

        if(op == '+')
        {
            output(f1 + f2);
        }
        else if(op == '-')
        {
            output(f1 - f2);
        }
        else if(op == '*')
        {
            output(f1 * f2);
        }
        else if(op == '/')
        {
            if(f2 == 0)
                printf("\n\n\nError: /DIV#0\n");
            else
                output(f1 / f2);
        }

    }

    return 0;
}
