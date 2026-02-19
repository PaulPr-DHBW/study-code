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
}


int main(void)
{
    //All about Sensor 1:
    Sensor Sensor1;
    Sensor1.id = 1;
    Sensor1.threshold = 0.8;
    Sensor1.data = NULL;
    FILE *ptr_file_Sensor1 = fopen("../sensor1.txt", "r");

    //Lets read in Sensor 1:
    read_in_sensordata(&Sensor1, ptr_file_Sensor1);

    return 0;
}