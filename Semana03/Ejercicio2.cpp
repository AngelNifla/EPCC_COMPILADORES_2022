/*
Programa que lea un archivo de texto plano (archivo con un pseudocódigo) y
muestre en pantalla letra por letra.
*/

#include <iostream>
#include <fstream>   //Incluimos la libreria fstream para abrir un documento y leer cada linea de ella.

using namespace std;

int main()
{
    string nombre_archivo;     //En una variable tipo string agregamos el nombre del archivo del texto plano.
    
    cout<<"Ingrese el nombre del archivo:  ";
    cin>>nombre_archivo;    //Se ingresa el nombre del archivo. Archivo de ejemplo "Ejercicio2.txt"
    if(nombre_archivo=="")  //Si no se ingresa el nombre del archivo
    {
        cout<<"Archivo no encontrado";  //  impreme,avisa y 
        return 0;   //termina el programa.
    }
    
    ifstream archivo(nombre_archivo.c_str());
    string linea;   //Variable dinamica para cada linea del texto.
    int cont=1;     //varibale para contar el numero de lineas(guia).

    while (getline(archivo, linea)) //bucle para obtener cada linea no vacia
    {/*
        cout<<"linea "<<cont<<":   ";   //se imprime la linea.
        cout<<linea<<endl;
        cont++;
        */
        for (int i = 0; i < linea.size(); i++)  //Bucle para imprimir cada letra de la cadena obtenida por el bucle principal
        {
            cout<<linea[i]<<endl;       //y se imprime cada letra la linea.
        }
    }
    return 0;
}