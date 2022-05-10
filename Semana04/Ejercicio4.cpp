/*
La solución 2, puede ser automatizada, teniendo como dato de entrada la tabla de transiciones.
Defina el formato de la tabla de transición y en un archivo de texto plano represente la
respectiva tabla (considere el diagrama del ejercicio 3). Finalmente, en base al archivo
de texto plano, determine la validez de una entrada.
*/
#include <iostream>
#include <string>
#include <fstream>   //Incluimos la libreria fstream para abrir un documento y leer cada linea de ella.


int main()
{
    int Matriz[6][5];    //Tabla de Transicion.

    std::string nombre_archivo;     //En una variable tipo string agregamos el nombre del archivo del texto plano.
    
    std::cout<<"Ingrese el nombre del archivo:  ";
    std::cin>>nombre_archivo;    //Se ingresa el nombre del archivo. Archivo de ejemplo "Ejercicio4.txt".
    std::ifstream archivo(nombre_archivo.c_str());  //Se abre el archivo.
    if (!archivo)       //Si el archivo no se abre.
    {
        std::cout<<"-> Archivo no encontrado\n";        //Se avisa de ello.
        return 0;       //Y termina el programa.
    }

    std::string linea{};   //Variable dinamica para cada linea del texto.
    int fila{0},columna{0};     //varibale para el conteo de filas y columnas,mientras se guarda valores en la matriz.
    std::string valor{};        //Variable para guardar cada caracter.

    while (getline(archivo, linea)) //bucle para obtener cada linea no vacia
    {
        if (fila<6)     //El numero de filas tiene que ser menor que 6, ya que es el maximo de la matriz.
        {
            for (int i = 0; i <= linea.size(); i++)  //Bucle para acceder a cada letra de la cadena obtenida por el bucle principal
            {
                if (linea[i]>='0' && linea[i]<='9')     //Si un caracter de la linea es un digito
                {
                    valor=valor+linea[i];       //Se guarda y/o se suma el caracter.
                }else if(linea[i]==',' || linea[i]=='\0' || columna<5)      //Si el carcater es una coma o final de linea y la columna es menor que 5
                {
                    Matriz[fila][columna]=stoi(valor);      //Se guarda esos caracteres guardados o sumados a la matriz.
                    columna++;      //Se suma el contador de columnas.
                    valor="";       //la variable que guarda los caracteres guardados o sumados se vuelve vacia.
                }else       //Si no,
                {
                    std::cout<<"-> ERROR\n";        //Se devuelve error.
                    return 0;       //Y termina el programa.
                }   
            }
            fila++;     //Si todo termina bien, el contador de filas aumenta en 1.
            columna=0;      //Y el contador de columans vuelve a cero.
        }else   ///Si no,
        {
            std::cout<<"-> ERROR\n";    //Se devuelve Error;
            return 0;       //Y  termina el programa.
        }   
    }
    
    for (int i = 0; i < 6; i++)     //Bucle para acceder las filas del array
    {
        for (int j = 0; j < 5; j++) //Bucle para acceder al los elementos de las filas.
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
        if (simbolo =='+' || simbolo == '-')        //Si el caracter es un signo + o -.
        {
            entrad = 0;     //La entrada sera 0;
        }else if (simbolo >= '0' && simbolo <= '9')       //Si el caracter es un numero.
        {
            entrad = 1;         //La entrada sera 1;
        }else if (simbolo >= 'a' && simbolo <= 'z')     //Si el caracter es una letra.
        {
            entrad = 2;     //La entrada sera 2;
        }else if(simbolo == '.')            //Si el caracter es un punto.
        {
            entrad = 3;     //La entrada sera 3;
        }else if (simbolo == '\0')      //Si el caracter es un FDC.
        {
            entrad = 4;     //La entrada sera 4.
        }else           //Si no,
        {
            std::cout<<"-> ERROR\n";        //Se considera error.
            break;                      //Y se cierra el bucle
        }
        estado=Matriz[estado][entrad];      //Obtenemos el nuevo estado de la matriz con el estado y la entrada actual.
        if (estado==1)      //Si ese estado es 0
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