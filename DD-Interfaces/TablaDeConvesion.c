#include <stdio.h>
#include "conversiones.h"

void PrintCelsius(double t_min,double t_max, int incre)
{
    double t_actual = t_min;
    double t_convert;
    printf("Celsius     ||      Farenheit");
    for(t_actual;t_actual <= t_max; incre)
    {
        t_convert = Farenheit(t_actual);
        printf("%.1f°C      ||      %.1f°F \n",t_actual,t_convert);
    }
}

void PrintFarenheit(double t_min,double t_max, int incre)
{
    double t_actual = t_min;
    double t_convert;
    printf("Farenheit   ||      Celsius");
    for (t_actual;t_actual <= t_max; incre)
    {
        t_convert=Celsius(t_actual);
        printf("%.1f°F  ||      %.1f°F \n",t_actual,t_convert);

    }  
}

int main()
{
    PrintCelsius(0,200,20);
    printf("\n-------------------------------------\n");
    PrintFarenheit(0,200,20);
    printf("\n-------------------------------------\n");
    return 0;
}