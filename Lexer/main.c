#include <stdio.h>
#include <ctype.h>
#include "reconocedor.h"
struct E_Token
{
    char lexema [100];
    int tipo;
    int linea;
    int columna;
};

enum ESTADOS
{
    OPERADOR=1,CONSTANTE_NUMERICO=2, NUEVA_LINEA, ERROR, ExtraFIN
};

struct E_Token Automata();
int ColumnaTabla(int c);

int main(){

struct E_Token token;
printf("iNGRESE EXPRESION ARITMETICA:" );

while (((token = Automata()).tipo ) != ExtraFIN)
{ 
     if(token.tipo == ERROR)
    {
        fprintf(stderr, "Caracter invalido... linea:%d columna:%d \n", token.linea, token.columna);
    }else if( token.tipo != NUEVA_LINEA)
    {
        switch (token.tipo)
        {
        case 1:
        fprintf(stdout, "%s,Operador\n",token.lexema);
        break;
        case 2: 
        fprintf(stdout, "%s,Constante numerico\n",token.lexema);
        break;
        }  
    }
};

return 0;
}
