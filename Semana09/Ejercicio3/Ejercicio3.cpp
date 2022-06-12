/*////////////////////////////ENUNCIADO////////////////////////////
Proponga una gramática para la evaluación de expresiones aritméticas. El programa debe leer
un archivo de texto plano (programa1.txt), generar la forma postfija y mostrar el resultado.

Programa1.txt:
        INICIO
            14 + 5;
            (12 - 6 ) + 8;
            ((8+12)-(5-2))*2;
        FIN

////////////////////////////GRAMATICA////////////////////////////

<Programa>*::= INICIO <Bloque> FIN
<Bloque>    ::= <Expresion> ; <Bloque> | vacio
<Expresion> ::= <Campo> <Signo> <Campo>
<Campo> ::= ( <Expresion> ) | <Num>
<Num>   ::= numeros...
<Signo> ::= + | - | * | /
*/

/*////////////////////////////CODIGO////////////////////////////*/

#include "Evaluacion_Gramatica.h"       //Se incluye codigo del archivo especificado.

void resultado()            //Funcion que devolvera el resultado de la excpresion y su expresion postfija.
{
    for (int i = 0; i < contadorlineas; i++)
    {
        if (fin())
        {
            std::cout<<"->Terminado\n";
        }else
        {
            std::cout<<"\nExpresion "<<i+1<<":\n";
            std::cout<<"\tRespuesta: "<<postfija()<<"\n";
            std::cout<<"\tPostfijo: "<<exp_postfija;
            exp_postfija = "";
        }
    }
}

int main()          //Funcion princnipal.
{
    std::cout<<"Ingrese el nombre del archivo:  ";
    std::cin>>nombre_archivo;    //Se ingresa el nombre del archivo. Archivo de ejemplo "Ejercicio4.txt".
    archivo =std::ifstream(nombre_archivo.c_str());
    if (!archivo)       //Si el archivo no se abre.
    {
        std::cout<<"-> Archivo no encontrado\n";        //Se avisa de ello.
        return 0;       //Y termina el programa.
    }
    inicio();       //Se verifica la sintaxis con la gramatica.
    resultado();        //Se muestra los resultados.
}
/*////////////////////////////EJECUCION////////////////////////////

PS E:\C++\2022\EPCC_COMPILADORES_2022\Semana09\Ejercicio3> .\\a
Ingrese el nombre del archivo:  programa1.txt 

-> Sintaxis correcta.
Expresion 1:
        Respuesta: 19
        Postfijo: 14 5 +
Expresion 2:
        Respuesta: 14
        Postfijo: 12 6 -  8 +
Expresion 3:
        Respuesta: 34
        Postfijo: 8 12 +  5 2 - -  2 *
PS E:\C++\2022\EPCC_COMPILADORES_2022\Semana09\Ejercicio3> 

*/
