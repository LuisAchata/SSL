#include "conversiones.h"

double Farenheit(double t_celsius)
{
    return (t_celsius * 9.0 / 5.0) + 32;
}
double Celsius(double t_farenheit)
{
    return (5.0/9.0) * (t_farenheit-32);
}