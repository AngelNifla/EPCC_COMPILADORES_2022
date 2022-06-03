/*
Proponer una gramática y desarrollar un analizador sintáctico predictivo.
Especifique cual es el objetivo de la gramática (¿Qué cadenas o programas
reconoce?), muestre la gramática y realice capturas (videos) de pantalla
del funcionamiento del analizador.
*/

#include <stdio.h>
#include <conio.h>


/*Definiciones de los tokens*/
#define INICIO 'm'
#define FIN ';'
#define LS 's'
#define LU 'u'
#define LM 'm'
#define LA 'a'
#define PI '('
#define PD ')'

/*Definicion de funciones*/
int preanalisis;
parea(int);
AA();
B();
U();
M();
A();
PARENTECIS();
error();

AA()    //Funcion que averigua la prima parte de la gramtica.
{
    if (preanalisis == INICIO)
    { parea(INICIO); B();
    }
    if (preanalisis == FIN)
    {
    }
    else
    error();
}

B()     //Funcion para corroborar la estructura de la gramtica.
{
    if (preanalisis == LS){
    parea(LS);
    U();
    }
    else
    error();
}

U()     //Funcion para corroborar la estructura de la gramtica.
{
    if (preanalisis == LU){
    parea(LU);
    M();
    }
    else
    error();
}

M()     //Funcion para corroborar la estructura de la gramtica.
{
    if (preanalisis == LM){
    parea(LM);
    A();
    }
    else
    error();
}

A()     //Funcion para corroborar la estructura de la gramtica.
{
    if (preanalisis == LA){
    parea(LA);
    PARENTECIS();
    }
    else
    error();
}

PARENTECIS()        //Funcion para corroborar la estructura de la gramtica.
{
    if (preanalisis == PI){
    parea(PI);
    }
    if(preanalisis == PD){ 
    parea(PD); 
    }
    else
    error();
}

error()     //Funcion que retorna el error.
{
    printf("Error de sintaxis");
}

parea(int t)        //Funcion que cambia de al siguiente caracter de loa cadena.
{
    if (preanalisis==t)
    preanalisis=getchar();
    else
    error();
}

main()      //Funcion principal.
{
    preanalisis=getchar(); //lee un carácter de la entrada
    AA();
}