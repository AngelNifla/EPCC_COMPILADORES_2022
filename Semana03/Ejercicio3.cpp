/*
Crear un programa que cifre un pseudocódigo y otro que lo descifre, según la técnica del cifrado de César.
El seudocódigo se encuentra en un archivo de texto plano. El cifrado de César consiste en mover cada letra
un determinado número de espacios en el alfabeto (puede ser 3 espacios)
*/

#include <iostream>
#include <fstream>

using namespace std;

void descifrado_cesar() //  funcion para decifrar el textop que se leera
{
    //array con las letras del abecedario
    char alf[]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
    char alf_m[]={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};

    string name_archivo;    //variable para el nombre del archivo

    cout<<"Ingrese nombre del archivo de texto plano: ";
    cin>>name_archivo;
    cout<<endl;
    if(name_archivo=="")    //  Si el nombre es vacio
    {
        cout<<"-> Archivo no encontrado.";
        exit(1);            //se termina el programa.
    }
    
    fstream archivo(name_archivo.c_str());
    string linea;   //Variable dinamica para cada linea del texto.

    cout<<"El archivo decifrado es: \n";

    while (getline(archivo, linea)) //bucle para obtener cada linea no vacia
    {
        for (int i = 0; i < linea.size(); i++)  //Bucle para obtener cada letra de cadena.
        {
            for (int j = 0; j < 26; j++)    //Bucle para obtener cada letra del alfabeto.
            {
                if (linea[i]==alf[j])   //Si una letra de la cadena es igual a una del alfabeto
                {
                    linea[i]=alf[j-3];  //Se reemplaza por la 3 letra siguiente.
                }
            }
            for (int k = 0; k < 26; k++)    //Bucle para obtener cada letra del alfabeto de mayusculas.
            {
                if (linea[i]==alf_m[k]) //Si una letra de la cadena es igual a una del alfabeto de mayusculas
                {
                    linea[i]=alf_m[k-3];    //Se reemplaza por la 3 letra siguiente.
                }
            }
        }
        cout<<"-> \t"<<linea<<endl;     //Al final de estudiar y modificar toda la cadena se imprime
    }
}

void cifrado_cesar()
{
    //Array con letras del alfabeto invertido
    char alf[]={'z','y','x','w','v','u','t','s','r','q','p','o','n','m','l','k','j','i','h','g','f','e','d','c','b','a'};
    char alf_m[]={'Z','Y','X','W','V','U','T','S','R','Q','P','O','N','M','L','K','J','I','H','G','F','E','D','C','B','A'};

    string name_archivo;    //variable para el nombre del archivo

    cout<<"Ingrese nombre del archivo de texto plano: ";
    cin>>name_archivo;
    cout<<endl;
    if(name_archivo=="")    //  Si el nombre es vacio
    {
        cout<<"-> Archivo no encontrado.";
        exit(1);            //se termina el programa.
    }
    
    fstream archivo(name_archivo.c_str());
    string linea;   //Variable dinamica para cada linea del texto.

    cout<<"El archivo cifrado es: \n";

    while (getline(archivo, linea)) //bucle para obtener cada linea no vacia
    {
        for (int i = 0; i < linea.size(); i++)  //Bucle para obtener cada letra de cadena.
        {
            for (int j = 0; j < 26; j++)    //Bucle para obtener cada letra del alfabeto.
            {
                if (linea[i]==alf[j])   //Si una letra de la cadena es igual a una del alfabeto
                {
                    linea[i]=alf[j-3];  //Se reemplaza por la 3 letra siguiente.
                }
            }
            for (int k = 0; k < 26; k++)    //Bucle para obtener cada letra del alfabeto de mayusculas.
            {
                if (linea[i]==alf_m[k]) //Si una letra de la cadena es igual a una del alfabeto de mayusculas
                {
                    linea[i]=alf_m[k-3];    //Se reemplaza por la 3 letra siguiente.
                }
            }
        }
        cout<<"-> \t"<<linea<<endl;     //Al final de estudiar y modificar toda la cadena se imprime
    }
}

int main()      //Funcion principal.
{
    int opcion=NULL;
    while (opcion==NULL)    //  Bucle para ingresar una opcion.
    {
        cout<<"--------------------------------------------------\n"<<endl;
        cout<<"Eliga una opcion:\n"<<endl;
        cout<<"(1) Cifrar el texto de un archivo.\n";
        cout<<"(2) Descifrar el texto de un archivo.\n";
        cout<<endl<<"Ingrese el numero de la opcion que desea: ";
        cin>>opcion;
        cout<<" \n--------------------------------------------------\n"<<endl;
        if (opcion==1)  //Si la opcion es 1
        {
            cifrado_cesar();    //llamamos a la funcion para cifrar.
            cout<<" \n--------------------------------------------------\n"<<endl;
        }else if(opcion==2) //Si la opcion es 2
        {
            descifrado_cesar(); //llamamos a la funcion para desifrar.
            cout<<" \n--------------------------------------------------\n"<<endl;
        }else if(opcion==NULL)  //Si no se ingresa nada, se seguira con el bucle while.
        {
            cout<<"-> No ingreso ninguna opcion.";
            cout<<" \n--------------------------------------------------\n"<<endl;
        }else   //Si se ingresa otro numero, termina el programa.
        {
            cout<<"-> La opcion no existe.";
            cout<<" \n--------------------------------------------------\n"<<endl;
        }
    }
    return 0;
}