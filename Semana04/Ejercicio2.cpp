/*
Implemente, el algoritmo por tablas de transición para el reconocimiento de un identificador.
*/

#include <iostream>

int main()
{
    int Matriz[3][3]={{1,2,0},{0,0,0},{2,2,10}};    //Tabla de Transicion.
    //la columna digito es la posicion 0 del array.
    //la columna letra es la posicion 1 del array.
    //la columna FDC es la posicion 2 del array.
    for (int i = 0; i < 3; i++)     //Bucle para acceder las filas del array
    {
        for (int j = 0; j < 3; j++) //Bucle para acceder al los elementos de las filas.
        {
            std::cout<<Matriz[i][j]<<" ";   //Imprime los valores.
        }
        std::cout<<std::endl;
    }

    std::string entrada{};      //Variable para la cadena entrada.
    int size{entrada.size()};       //Variable para el tamaño de la entrada.
    char simbolo;       //Variable para los entraderes de la entrada.
    int entrad;     //Variable para la entrada en numero.
    int sum{-1};        //Variable para sumarorio para acceder a la cadena entrada.
    int estado{0};      //Variable para los esatdos.

    std::cout<<"Ingrese una ID: ";
    std::cin>>entrada;      //Se pide ingresar la cadena. 

    do  //Ejecutar
    {
        sum++;      //Aumento de el sumatorio.
        simbolo=entrada[sum];       //Extraemos el caracter de la cadena.
        if (simbolo >= '0' && simbolo <= '9')       //Si el caracter es un numero.
        {
            entrad = 0;         //La entrada sera 0;
        }else if (simbolo >= 'a' && simbolo <= 'z')     //Si el caracter es una letra.
        {
            entrad = 1;     //La entrada sera 1;
        }else if (simbolo == '\0')      //Si el caracter es un FDC.
        {
            entrad = 2;     //La entrada sera 2.
        }else           //Si no,
        {
            std::cout<<"-> ERROR\n";        //Se considera error.
            break;                      //Y se cierra el bucle
        }
        estado=Matriz[estado][entrad];      //Obtenemos el nuevo estado de la matriz con el estado y la entrada actual.
        if (estado==0)      //Si ese estado es 0
        {
            std::cout<<"-> ERROR\n";        //Se le concidera error.
            break;                      //Y se cierra el bucle
        } 
    } while (estado !=10);  //Mientras el estado sea diferente de 10, el bucle continua.

    if (estado==10)     //Si el bucle concluye y el estado es igual a 10, 
    {
        std::cout<<"-> ACEPTADO";        //La cadena es aceptada.
    }

    return 0;

}