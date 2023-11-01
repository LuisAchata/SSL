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
struct E_Token Automata()
{
    static int tt[5][4] = 
    {//0,1,2,3
     {1,2,3,4},//0
     {4,4,4,4},//1
     {4,2,4,4},//2
     {4,4,4,4},//3
     {4,4,4,4}//4
    };
    int estado=0,i=0,c;
    struct E_Token token;
    int estado_error;

    while ( (c= getc(stdin)) != EOF)
    {
        if( c != '\t' && c != ' ' )
        {
            token.lexema[i]=c;
            i++;
            estado_error=estado;
            estado= tt[estado][ColumnaTabla(c)];
            switch (estado)
            {
            case OPERADOR:
            token.tipo = OPERADOR;
            token.lexema[i]='\0';
            return token;
            
            case CONSTANTE_NUMERICO:
                while( (isdigit(c=getc(stdin))))
                {
                    token.lexema[i]=c;
                    i++;
                };
            token.tipo=CONSTANTE_NUMERICO;
            token.lexema[i]='\0';
            ungetc(c,stdin);
            return token;

           case ERROR:  
           
            token.tipo = ERROR;
            token.lexema[i]='\0';
            token.linea=estado_error;
            token.columna=ColumnaTabla(c);
            return token;

            case NUEVA_LINEA:
            token.tipo= NUEVA_LINEA;
            token.lexema[i]='\0';
            return token;  
            default: break;
            }
            
        }
  
    }
    printf("salida del posible archivo\n");
    token.tipo = ExtraFIN;
    token.lexema[0]='\0';
    return token;
    
};

int ColumnaTabla(int x)
{

    if(x >= 40 && x <= 47) // operadores
    { 
        
        return 0;
    }else if (x >= 48 && x <= 57) // digitos
    {
        
        return 1;
    } 
    else if( x !='\n' ) //ERROR
    {   
        return 3;
    }else

    return 2;
};