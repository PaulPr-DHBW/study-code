#include <stdio.h>

const char colums[8] = {'A', 'B', 'C', 'D', 'F', 'G', 'H'};
const char top[] = "+---+---+---+---+---+---+---+";
const char filler[] = "###";
const int rows = 8;
const int cols = 7;

void printline()
{
    printf(" %s\t\n", top);
}
void printLetters()
{
    printf("  ");
    for(int i = 0; i < rows; i++)
    {
        printf(" %c  ", colums[i]);
    }
    printf("\n");
}
void fillblanks(int currentrow, int currentcol)
{
    if((currentcol%2 == 0 && currentrow%2 == 0) || (currentcol%2 != 0 && currentrow%2 != 0))
    {
        printf("###");
    }
    else
        printf("   ");
}


int main()
{
    printLetters();
    
    for (int i = 0; i < rows; i++)
    {
        printline();
        printf("%d", i);
        printf("|");

        for(int j = 0; j < cols; j++)
        {
            fillblanks(i, j);
            printf("|");
        }
        printf("%d", i);
        printf("\n");
    }
    printLetters();

}
