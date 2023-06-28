#include <assert.h>
#include "conversiones.h"
#include <stdio.h>
#include <math.h>

int comparar_double(double n, double m)
{
    double rango_error = 1.0f;
    if(fabs(n-m) < rango_error)
    { 
        printf("margen de error %1f\n",fabs(n-m));
      return 0; 
    }else {
        return 1;
    }
}      
int main(){
double Farenheit(double t_celsius);
double Celsius(double t_farenheit);
printf("\n --- Inició de pruebas --- \n");

assert(comparar_double(Celsius(200),93) == 0);//200°F es igual a 93°C
assert(comparar_double(Celsius(43),6.11) == 0); //43°F es igual a 6.11°C

  
assert(comparar_double(Farenheit(93.33),200)==0); //93°C es igual a 200°F
assert(comparar_double(Farenheit(6),42.8)==0); //6°C es igual a 42.8°F
printf("--- Paso las pruebas ---");
return 0;
}