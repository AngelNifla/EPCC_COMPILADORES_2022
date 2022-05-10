/*
Leer un archivo de texto plano, letra por letra hasta encontrar un separador (espacio,
tabulador o salto de línea) y mostrar en pantalla si el vocablo se trata de un número
entero, una palabra o un caracter especial (“+”,”-“,”*”,”/”,"=")
*/

#include <iostream>
#include <fstream>

using namespace std;

int main() //  funcion principal
{
    //array con las letras del abecedario en minusculas y mayusculas
    char alf[]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z',
                'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
    char carac_especial[]={'+','-','/','*','='};    //array con carcateres especiales

    string name_archivo;    //variable para el nombre del archivo

    cout<<"Ingrese nombre del archivo de texto plano: ";
    cin>>name_archivo;
    cout<<endl;
    if(name_archivo=="")    //Si el nombre es vacio
    {
        cout<<"-> Archivo no encontrado.";
        exit(1);            //se termina el programa.
    }
    
    fstream archivo(name_archivo.c_str());  //Se abre el archuvi
    string linea;   //Variable dinamica para cada linea del texto.
    string aux;         //Variable de cadena auxiliar, para almacenar cada vocablo.
    int cont;           //Variable contador.

    while (getline(archivo, linea)) //Bucle para obtener cada linea no vacia.
    {
        aux="";     //La cadena auxiliar estara vacia cuando el bucle pase a otra linea.
        linea=linea+" ";    //Agregamos un separador a la linea para obtener el ultimo vocablo.

        for (int i = 0; i < linea.size(); i++)  //Bucle para obtener cada letra y/o caracter de cadena linea.
        {
            if (linea[i]=='\n' || linea[i]=='\t' || linea[i]==' ')      //Si la letra del ciclo es un separador
            {
                if(aux!="")     //y la cadena auxiliar hasta ese momento es diferente del vacio y
                {
                    cont=0;     //Inicializamos en contador.
                    for (int j = 0; j < aux.size(); j++)    //Bucle para obtener cada letra de la cadena auxiliar.
                    {
                        for (int k = 0; k < 32; k++)    //Bucle para obtener cada letra del alfabeto.
                        {
                            if (aux[j]==alf[k]) //si una letra de la cadena aux es igual a una del alfabeto
                            {
                                cont++;    //la variable cont aumenta en 1 y
                            }
                        }
                    }
                    if(cont>0) //si el cont es mayor que 0
                    {
                        cout<<aux<<" -> palabra\n";    //aux es una palabra.
                        aux="";
                        cont=0;     //Ponemos el cont a 0.
                    }else if(aux.size()==1)     //Si no es una letra, pero aux es de una letra
                    {
                        for (int m = 0; m < 5; m++)    //Bucle para obtener cada caracter especial.
                        {
                            if(aux[0]==carac_especial[m])   //y aux tambien es igual a uno de caracteres especiales
                            {
                                    cont++;     //aumentamos en 1 al contador.
                            }
                        }
                        if(cont>0)      //Si el contador es >0  entonces
                        {
                            cout<<aux<<" -> caracter especial\n";    //aux es un carcater especial.
                            aux="";
                            cont=0;
                        }else           //Si contador = 0 entonces
                        {
                            cout<<aux<<" -> un numero\n";    //aux es un numero.
                            aux="";
                        }
                    }else   //Si aux no es una palabra ni un caracter especial entonces
                    {
                        cout<<aux<<" -> un numero\n";    //aux es un numero.
                        aux="";
                    }
                }else       //Si la cadena auxiliar esta vacia 
                {
                    aux="";     //la cadena auxiliar seguira esatando vacia.
                }
            }else           //Si la letra del ciclo no es un separador entonces
            {
                aux=aux+linea[i];       //esa letra se agrega a la cadena auxiliar.
            }
        }
    }
    return 0;
}