/*
Desarrollar un analizador sintáctico predictivo para la siguiente gramática:
                        S --> x S
                        S --> A B c
                        A --> a
                        B --> b
*/

#include <stdio.h>
#include <conio.h>
int preanalisis;
parea(int);
A();
B();
error();

S()
{
    if (preanalisis == 'x')
    { parea('x'); S(); }
    else if (preanalisis == 'a')
    { A(); B(); parea('c'); }
    else
    error();
}

A()
{
    if (preanalisis == 'a')
    parea('a');
    else
    error();
}

B()
{
    if (preanalisis == 'b')
    parea('b');
    else
    error();
}

error()
{
    printf("Error de sintaxis");
}

parea(int t)
{
    if (preanalisis==t)
    preanalisis=getchar();
    else
    error();
}

main()
{
    preanalisis=getchar(); //lee un carácter
    //de la entrada
    S();
}