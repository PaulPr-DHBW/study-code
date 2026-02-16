#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct car
{
    const float f_max_fuel_level;
    float f_fuel_level;
    char model[20];

} car;


void refuel(car *ptr_car_data, float fuel_amount)
{
    if(ptr_car_data->f_fuel_level + fuel_amount < ptr_car_data->f_max_fuel_level && fuel_amount > 0)
    {
        ptr_car_data->f_fuel_level += fuel_amount;
    }
    else if (fuel_amount > 0)
    {
        ptr_car_data->f_fuel_level = ptr_car_data->f_max_fuel_level;
    }
    else
    {
        printf("\nFuel cant be negativ!\n");
    }
}

int main (void)
{
    car Mercedes = {50.0, 10.0, "AMG ONE"};
    printf("Aktueller Tankinhalt: %.2f\n", Mercedes.f_fuel_level);
    refuel(&Mercedes, 10);
    printf("Aktueller Tankinhalt: %.2f\n", Mercedes.f_fuel_level);


    return 0;
}