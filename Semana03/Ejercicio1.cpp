/*
Programa que lea toda una instrucción por consola (Ejemplo: “int temp;”) y mostrar en panta-lla letra por letra
*/

#include <iostream>

using namespace std;

int main()
{
    string instruccion;     //Varible cadena para almacenar la instruccion.

    cout<<"Ingrese una instruccion : ";
    getline(cin,instruccion);   //se ingresa la instruccion

    for (int i = 0; i < instruccion.size(); i++)       //Bucle para obtener cada palabra de la cadena.
    {
        cout<<instruccion[i]<<endl;     //Imprime cada letra por linea en la consola.
    }

    return 0;
}