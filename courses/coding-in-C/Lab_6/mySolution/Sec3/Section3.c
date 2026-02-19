#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct SensorData
{
    float time;
    double probability;

} SensorData;

typedef struct Sensor
{
    int id;
    double threshold;
    SensorData *data;
    int *object_detection;
    int data_count;

} Sensor;

void read_in_sensordata(Sensor *ptr_sensor, FILE *ptr_data_file)
{
    int anzahl = 0;
    float temp = 0;
    int is_data = 0;
    Sensor temp_data;
    temp_data.data = NULL;
    

    while(fscanf(ptr_data_file, "%f", &temp) == 1)
    {
        if(!is_data)
        {
            anzahl++;
            temp_data.data = realloc(ptr_sensor->data, anzahl*sizeof(SensorData));
        }

        if(temp_data.data == NULL)
        {
            printf("Error while reading in the File an allocating memory");
            free(ptr_sensor->data);
            return;
        }

        ptr_sensor->data = temp_data.data;

        if(!is_data)
        {
            ptr_sensor->data[anzahl-1].time = temp;
        }
        else if(is_data)
        {
            ptr_sensor->data[anzahl-1].probability = temp;
        }

        is_data = !is_data;       
    }

    ptr_sensor->data_count = anzahl;
}

void check_object_detection(Sensor *ptr_sensor)
{
    int i = 0;
    int *temp = NULL;

    temp = (int*)calloc(ptr_sensor->data_count, sizeof(int));
    
    if(temp == NULL)
    {
        printf("\nFehler bei der Speicherallokierung bei object_detection\n");
        free(ptr_sensor->object_detection);
        return;
    }

    ptr_sensor->object_detection = temp;
    

    while(i < ptr_sensor->data_count)
    {
        if(ptr_sensor->data[i].probability >= ptr_sensor->threshold)
        {
            ptr_sensor->object_detection[i] = 1;
        }
        //else nicht unbedingt notwendig, da mit calloc alle anderen Stellen bereits 0 sind

        i++;
    }
}

void print_detection_result(Sensor *ptr_sensor)
{
    if(ptr_sensor->object_detection == NULL)
    {
        printf("Der Sensor %d hat kein Binäres Signal", ptr_sensor->id);
        return;
    }
    //Variable die den Status speicher (High oder Low) um Flanken zu erkennen
    int status = 0;

    printf("\nSensor %d detection: ", ptr_sensor->id);

    for(int i = 0; i < ptr_sensor->data_count; i++)
    {
        if(status == 0 && ptr_sensor->object_detection[i] == 1)
        {
            status = 1; //Status auf High setzen
            printf("Start: %.2f ", ptr_sensor->data[i].time);
        }
        else if(status == 1 && ptr_sensor->object_detection[i] == 0)
        {
            status = 0; //Fallende Flanke Status wird auf LOW gesstzt
            printf("End: %.2f ", ptr_sensor->data[i-1].time); //Muss das Vorherige Elemt ausgeben, da es ja auf 0 geswitcht ist
        }
    }

    if(status == 1) //Falls es vor Detectionsende nicht mehr aufhört
    {
        printf("End: %.2f ", ptr_sensor->data[ptr_sensor->data_count -1].time);
    }
    printf("\n\n"); //Formatierung

}

void print_overlapping_result(Sensor *ptr_sensor1, Sensor *ptr_sensor2)
{
    if(ptr_sensor1->object_detection == NULL || ptr_sensor2->object_detection == NULL)
    {
        printf("Kein Binäres Signal vorhanden");
        return;
    }

    if(ptr_sensor1->data_count != ptr_sensor2->data_count)
    {
        printf("Die Binären Signale sind nicht gleich Lang, überlagerung nicht möglich");
        return;
    }

    //Variable die den Status speicher (High oder Low) um Flanken zu erkennen
    int status = 0;

    printf("\nFused signal:");

    for(int i = 0; i < ptr_sensor1->data_count; i++)
    {
        if(status == 0 && ptr_sensor1->object_detection[i] == 1 && ptr_sensor2->object_detection[i] == 1)
        {
            status = 1; //Status auf High setzen
            printf("Start: %.2f ", ptr_sensor1->data[i].time);
        }
        else if(status == 1 && ptr_sensor1->object_detection[i] == 0 && ptr_sensor2->object_detection[i] == 0)
        {
            status = 0; //Fallende Flanke Status wird auf LOW gesstzt
            printf("End: %.2f ", ptr_sensor1->data[i-1].time); //Muss das Vorherige Elemt ausgeben, da es ja auf 0 geswitcht ist
        }
    }

    if(status == 1) //Falls es vor Detectionsende nicht mehr aufhört
    {
        printf("End: %.2f ", ptr_sensor1->data[ptr_sensor1->data_count -1].time);
    }
    printf("\n\n"); //Formatierung


}

int main(void)
{
    //All about Sensor 1:
    Sensor Sensor1;
    Sensor1.id = 1;
    Sensor1.threshold = 0.8;
    Sensor1.data = NULL;
    Sensor1.data_count = 0;
    Sensor1.object_detection = NULL;
    FILE *ptr_file_Sensor1 = fopen("../../sensor1.txt", "r");

    if(ptr_file_Sensor1 == NULL)
    {
        printf("File 1 nicht vorhanden");
        return 1;
    }

    //Lets read in Sensor 1:
    read_in_sensordata(&Sensor1, ptr_file_Sensor1);

    fclose(ptr_file_Sensor1);

    //All about Sensor 2:
    Sensor Sensor2;
    Sensor2.id = 2;
    Sensor2.threshold = 0.7;
    Sensor2.data = NULL;
    Sensor2.data_count = 0;
    Sensor2.object_detection = NULL;
    FILE *ptr_file_Sensor2 = fopen("../../sensor2.txt", "r");

    if(ptr_file_Sensor2 == NULL)
    {
        printf("File 2 nicht vorhanden");
        return 1;
    }

    //Lets read in Sensor 2:
    read_in_sensordata(&Sensor2, ptr_file_Sensor2);

    fclose(ptr_file_Sensor2);

    //Now we set up the object_detection for both sensors
    check_object_detection(&Sensor1);
    check_object_detection(&Sensor2);

    //Print the Detection times without overlapping
    print_detection_result(&Sensor1);
    print_detection_result(&Sensor2);

    //Print overlapping detections
    print_overlapping_result(&Sensor1, &Sensor2);

    free(Sensor1.object_detection);
    free(Sensor1.data);

    free(Sensor2.object_detection);
    free(Sensor2.data);

    return 0;
}