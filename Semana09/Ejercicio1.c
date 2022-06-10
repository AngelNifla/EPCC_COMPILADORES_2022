/*////////////////////////////ENUNCIADO////////////////////////////
A) Escribir un analizador sintáctico de infija a postfija incluyendo el analizador léxico.

Analizador sintáctico de infija a postfija
Exp --> Term Resto
Resto --> mas Term {printf("+")} Resto
Resto --> menos Term {printf("-")} Resto
Resto -->
Term --> {printf(num.valor)} num
*/

/*////////////////////////////CODIGO////////////////////////////*/

#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#define MAS '+'
#define MENOS '-'
#define NUM 256
#define FIN -1
char lexema[80];
int tok;
parea(int);
error();
Resto();
Term();
int scanner();

Exp()
{
    if (tok==NUM)
    {
        Term();
        Resto();
    }else
        error();
}

Resto()
{
    if (tok == MAS)
    {
        parea(MAS);
        Term();
        printf("+");
        Resto();
    }
    else if (tok == MENOS)
    {
        parea(MENOS);
        Term();
        printf("-");
        Resto();
    }
    else //cadena vacia
    ;
}

Term()
{
    if (tok==NUM)
    {
        printf("%s",lexema);
        parea(NUM);
    }
    else
        error();
}

error()
{
    printf("Error de sintaxis");
}

parea(int t)
{
    if (tok==t)
        tok=scanner();
    else
        error();
}

int scanner()
{
    int c,i;
    do c=getchar(); while(c==' ');
    if (c=='\n')
        return FIN;
    if (c==MAS || c==MENOS)
        return c;
    if(isdigit(c))
    {
        i=0;
        do { lexema[i++]=c; c=getchar(); }while(isdigit(c));
        lexema[i]=0;
        ungetc(c,stdin);
        return NUM;
    }
}

main()
{
    tok=scanner();
    Exp();
}


/*////////////////////////////EJECUCION////////////////////////////

PS E:\C++\2022\EPCC_COMPILADORES_2022\Semana09> .\\a 
15+15
1515+
PS E:\C++\2022\EPCC_COMPILADORES_2022\Semana09> .\\a  
15+3-4
153+4-
PS E:\C++\2022\EPCC_COMPILADORES_2022\Semana09> .\\a
15
15
PS E:\C++\2022\EPCC_COMPILADORES_2022\Semana09> .\\a
15-
15Error de sintaxis-
PS E:\C++\2022\EPCC_COMPILADORES_2022\Semana09>

*/