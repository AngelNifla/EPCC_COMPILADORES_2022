/*
Desarrollar un analizador sintáctico predictivo para la siguiente gramática:
Analizador Sintáctico de Infija a Postfija 
            Exp --> Term Resto
            Resto --> + Term {printf("+")} Resto
            Resto --> - Term {printf("-")} Resto
            Resto -->
            Term --> {printf("0")} 0
            Term --> {printf("1")} 1
            ...
            Term --> {printf("9")} 9
*/

#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <ctype.h>



/*Definicion de funciones*/
int preanalisis;
parea(int);
error();
Exp();
Resto();
Term();

Exp()       //Funcion para incializar el reconocimiento de la cadena.
{
    if (isdigit(preanalisis))
    {
        Term();
        Resto();
    }else
    {
        error();
    }
}

Resto()     //Funcion para reconocer los signos y elemntos recursivos.
{
    if (preanalisis == '+')
    {
        parea('+');
        Term();
        printf("+");
        Resto();
        
    }else if (preanalisis == '-')
    {
        parea('-');
        Term();
        printf("-");
        Resto();
    } 
}

Term()      //Funcion para determinar si es un digito.
{
    if (isdigit(preanalisis))
    {
        printf("%c",preanalisis);
        parea(preanalisis);
    }else
    {
        error();
    }  
}

parea(int p)        //Funcion para cambiar de caracter.
{
    if (preanalisis == p)
    {
        preanalisis = getchar();
    }else
    {
        error();
    }
}

error()     //Funcion para detectar error.
{
    printf("[error]\n-> Error de Sintaxis");
    exit (-1);
}

main()      //Funcion principal.
{
    printf("Ingrese la cadena: ");
    preanalisis = getchar();
    printf("-> Postfijo: ");
    Exp();
    printf("\n-> Sintaxis Correcta");
}