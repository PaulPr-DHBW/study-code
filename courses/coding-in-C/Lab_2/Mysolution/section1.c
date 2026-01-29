#include <stdio.h>

const char colums[8] = {'A', 'B', 'C', 'D', 'F', 'G', 'H'};
const int ci_rowSize = 8;
const int ci_colSize = 7;

int main()
{
    for(int i = ci_rowSize; i >= 1; i--)
    {
        for(int j = 0; j < ci_colSize; j--)
        {
            printf("%c%d\t", colums[j], i);
        }
        printf("\n");
    }
    
    return 0;
}