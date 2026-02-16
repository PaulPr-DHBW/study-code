#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void reading_by_fgetc(FILE* ptr_data)
{
    int temp;

    while ((temp = fgetc(ptr_data)) != EOF)
    {
        printf("%c", temp);
    }

    printf("\n");
}

void reading_by_fgets(FILE* ptr_data)
{
    char buffer[100]; //Liest ganze Zeilen ein, unvorteilhaft

    while(fgets(buffer, sizeof(buffer), ptr_data) != NULL)
    {
        printf("\nData read in by fgets:\t%s", buffer);
    }
    

}

void reading_by_fscanf(FILE* ptr_data)
{
    char *buffer = NULL;
    int anzahl = 0;
    char temp;

    while (fscanf(ptr_data, "%c", &temp) == 1)
    {
        char *help = realloc(buffer, (anzahl + 1));

        if (help == NULL)
        {
            free(buffer);
            return;
        }

        buffer = help;
        buffer[anzahl] = temp;
        anzahl++;
    }

    char *help = realloc(buffer, anzahl + 1);

    if (help == NULL)
    {
        free(buffer);
        return;
    }

    buffer = help;
    buffer[anzahl] = '\0';

    printf("\nData read in by fscanf:\t%s\n", buffer);

    free(buffer);
}

void writing_by_fputc(FILE* ptr_data)
{
    fputc('P', ptr_data);
    fputc('A', ptr_data);
    fputc('U', ptr_data);
    fputc('L', ptr_data);

}

void writing_by_fputs(FILE* ptr_data)
{
    char* ptr_write_fputs = "Hier hat Paul geschrieben";

    if(fputs(ptr_write_fputs, ptr_data) == EOF)
        printf("\nERROR fputs\n");


}

void writing_by_fprintf(FILE* ptr_data)
{
    int example = 1;

    fprintf(ptr_data, "Hallo %d", example);

}

int main()
{
    FILE *ptr_read_file = fopen("example.txt", "r");
    //FILE *ptr_write_file = fopen("example.txt", "w");

    //Lets read in the example File
    //reading_by_fgetc(ptr_read_file);
    //rewind(ptr_read_file);

    //reading_by_fgets(ptr_read_file);
    //rewind(ptr_read_file);

    //reading_by_fscanf(ptr_read_file);
    //rewind(ptr_read_file);


    fclose(ptr_read_file);
    //fclose(ptr_write_file);

    FILE *ptr_write_file = fopen("examplewrite.txt", "w");

    writing_by_fputc(ptr_write_file);
    writing_by_fputs(ptr_write_file);
    writing_by_fprintf(ptr_write_file);

    //writing_by_fputs(ptr_write_file);


    fclose(ptr_write_file);
    return 0;
}