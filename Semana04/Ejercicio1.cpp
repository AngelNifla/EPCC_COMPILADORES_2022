/*
Implemente el algoritmo por diagramas de transición para el reconocimiento de un identificador.
*/

#include <iostream>

int main()      //Funcion principal.
{
    int estado{1};      //Variable para el estado.
    int size{0};        //Variable para el tamaño.
    std::string cadena{};       //Variable para la cadena.
    char simbolo{};     //Variable para el simbolo.
    std::cout<<"Ingrese una cadena: ";
    std::cin>>cadena;       //Se ingresa la cadena.
    simbolo=cadena[size];       //El simbolo toma el primer caracter.

    while (size < cadena.size())        //Bucle para acceder a cada caracter de la cadena.
    {
        switch (estado) //Si el estado:
        {
            case 1:     //  es 1.
                if (simbolo>='0' && simbolo<='9')       //Si el simbolo es un digito. 
                {
                    estado=2;       //El estado va al 2.
                }else if (simbolo >= 'a' && simbolo <= 'z') //Si el simbolo es una letra
                {
                    estado=3;   //El estado va al 3.
                }else
                {
                    std::cout<<"-> Error\n";    //Si no manda error.
                }
                break;
            case 2:     //Si es 2:
                std::cout<<"-> ERROR\n";        //Manda error.
                break;
            case 3:     //Si es 3:
                if (simbolo >= '0' && simbolo<= '9')    //Si es el simbolo es un digito.
                {
                    estado = 3;     //El estado va al 3
                }else if (simbolo >= 'a' && simbolo <= 'z') //Si el simbolo es una letra.
                {
                    estado=3;       //El estadp va al 3.
                }else       //Si no, 
                {
                    std::cout<<"-> ERROR\n";   //Manda error.
                }
                break;
        }
        size=size+1;    //El tamaño aumenta en uno
        simbolo=cadena[size];       //Se accede al siguiente caracter.
    }
    
    if (estado!=3)      //Si el estado final es diferente de 3
    {
        std::cout<<"-> ERROR\n";   //Manda error.
    }else           //Si no,
    {
        std::cout<<"-> ACEPTADO\n";     //Se acepta la cadena.
    }
    return 0;
}