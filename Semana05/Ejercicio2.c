#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <string.h>


/*Definimos expresiones*/
#define SUMA '+'
#define RESTA '-'
#define PRODUCTO '*'
#define DIVISION '/'
#define MAYOR '>'
#define MENOR '<'
#define ASIGNACION '='
#define NEGACION '!'
#define COMA ','
#define PUNTOYCOMA ';'
#define PARI_E '('
#define PARI_S ')'
#define CORCH_E '['
#define CORCH_S ']'
#define LLAVE_E '{'
#define LLAVE_S '}'
#define ID 256
#define NUM 257
#define MAYORIGUAL 258
#define MENORIGUAL 259
#define IGUALDAD 260
#define DIFERENTE 261
#define COMENTARIO 262
#define WHILE 263
#define IF 264
#define MAIN 265
#define RETURN 266
#define VOID 267
#define INT 268
#define FLOAT 269
#define DOUBLE 270
#define STRING 271
#define CHAR 272
#define BOOL 273

int scaner();           //Funcion para escanear una entrada.
void mostrar(int);          //Funcion para mostrar los tokens.
int espalres();             //Funcion para saber si un ID es una Palabra Reservada.

FILE *f;            //Puntero a una cedena en un archivo.
char lexema[80];        //Array de caracteres para los lexemas.

void main(int n, char *pal[])       //Funcion principal.
{
    int token;  //variable para el codigo entero de un token.
    f=stdin;    //entrada estandar del teclado
    if(n==2)    //si se especifico un archivo de lectura
    {
        f=fopen(pal[1],"rt"); //lectura modo texto
        if(f==NULL)
            f=stdin;
    }
    if(f==stdin) //la lectura sera desde la entrada estandar
        printf("Ingrese texto ........ termine con Ctrl z \n");
    while(1)    //Bucle para escanear y estudiar la entrada.
    {
        token=scaner(); //Se sigue escaneando la entra.
        if(token==EOF)  //Si el token es -1.
            break;              //Se corta el bucle.
        mostrar(token); //Si no, se muestra los lexemas encontrados.
    }
    if(f !=stdin) // si la entrada fue de un archivo
        fclose(f); // entonces cerrar el archivo.
}

int scaner()            //Funcion para escanear una entrada.
{
    int c;  //Variable para almacenar el codigo de un caracter definido.
    int i;  //
    do      //Se 
        c=fgetc(f);     //obtiene el siguiente caracter de la entrada
    while(isspace(c)); //Hasta que se obtenga un caracter diferente de  espacio
    if(c==EOF)  //Si hay un error
        return EOF;     //Se devueleve -1
    if(isalpha(c)) //regla del ID, Si el caracter es un caracter del alfabeto
    {
        i=0;    //Se inicializa la variable.
        do{     //Se
            lexema[i++]=c;      //Abrega el caracter al lexema
            c=fgetc(f);     //y se obtine el siguiemnte caracter de la entrada.
        } while(isalnum(c)||c=='_');        //Hasta que se obtenga un carcater diferente de un numero o subgion.

        lexema[i]=0;    //Se le agrega fin de cadena al lexema.
        ungetc(c,f); //se devuelve la entrada desde el carcater al flujo de entrada
        i=espalres(); // verifica si el lexema es palabra reservada por la funcion.
        // WHILE , IF
        if(i>=0)    //Si es una Palabra reservada dara un numero >=0
            return i;   // y se retorna el codigo del token.
        return ID; // se trata de un ID
    }
    if(isdigit(c)) //regla del NUM
    {
        i=0;        //Se inicializa la variable.
        do{         //Se
            lexema[i++]=c;      //Abrega el caracter al lexema
            c=fgetc(f);     //y se obtine el siguiemnte caracter de la entrada.
        }while(isdigit(c));     //Hasta que se obtenga un carcater diferente de un numero.
        lexema[i]=0;        //Se le agrega fin de cadena al lexema.
        ungetc(c,f);        //se devuelve la entrada desde el carcater al flujo de entrada
        return NUM;         // se trata de un NUM.
    }
    
    if((c==',')||(c==';')||(c=='(')||(c==')')       //Si es un caracter de signos
        ||(c=='[')||(c==']')||(c=='{')||(c=='}')
        ||(c=='+')||(c=='-')||(c=='*'))
        return c; //regla del ";" y "("     //Se retorna el mismo en forma de codigo ascci
    if(c=='>')              //Si el caarcter es ">" o ">=".
    {
        c=fgetc(f);         //se obtine el siguiente caracter de la entrada.
        if(c=='=')          //Si ese caracter es al signo =
        { 
            lexema[0]='>';          //Se agrega al lexema el primer carcacter
            lexema[1]='=';          //Se agrega al lexema el segundo carcacter
            lexema[2]=0;            //Se agrega al lexema un final de cadena
            return MAYORIGUAL;  //return MAYORIGUAL
        }
        ungetc(c,f);    //se devuelve la entrada desde el carcater al flujo de entrada.
        return MAYOR; //return MAYOR
    }
    if(c=='<')//regla de "<" o "<="
    {
        c=fgetc(f);
        if(c=='=') //return MENORIGUAL
        { 
            lexema[0]='<';
            lexema[1]='=';
            lexema[2]=0;
            return MENORIGUAL;
        }
        ungetc(c,f);
        return MENOR; //return MENOR
    }
    if(c=='=')//regla de "=" o "=="
    {
        c=fgetc(f);
        if(c=='=') //return IGUALDAD
        { 
            lexema[0]='=';
            lexema[1]='=';
            lexema[2]=0;
            return IGUALDAD;
        }
        ungetc(c,f);
        return ASIGNACION; //return ASIGNACION
    }
    if(c=='!')//regla de "!" o "!="
    {
        c=fgetc(f);
        if(c=='=') //return DIFERENTE
        { 
            lexema[0]='!';
            lexema[1]='=';
            lexema[2]=0;
            return DIFERENTE;
        }
        ungetc(c,f);
        return NEGACION; //return NEGACION
    }
    if(c=='/')//regla de "/" o "//" o "/*" o "*/"
    {
        c=fgetc(f);     //se obtine el siguiente caracter de la entrada.
        if(c=='/')          //Si ese caracter es al signo /
        {
            while (c!='\n')     //Mediante un bucle hasta encontrar un carcater de salto de linea
            {
                c=fgetc(f);     //se siguira obteniendo el siguiemnte caracter de la entrada.
            }
            return COMENTARIO;      //Al final se envia un token de comentario
        }
        if (c=='*')         //Si ese caracter es al signo *
        {
            c=fgetc(f);         //se obtine el siguiemnte caracter de la entrada.
            while (c!=EOF)      //Mediante un bucle
            {
                c=fgetc(f);     //se obtine el siguiemnte caracter de la entrada.
                if (c=='*')     //Si ese carcater es *
                {
                    c=fgetc(f);     //se obtine el siguiemnte caracter de la entrada.
                    if (c=='/')        //Si ese caracter es al signo /
                    {
                        return COMENTARIO;     //Se envia un token de comentario .
                    }
                }
            }
        }
        ungetc(c,f);        //Si no,se devuelve la entrada desde el carcater al flujo de entrada 
        return DIVISION;        //Se retorna el token de Division.
    }
}//fin de scaner

int espalres()              //Funcion para saber si un ID es una Palabra Reservada.
{
    if(strcmp(lexema,"while")==0)       //Si el lexema es igual a la palabra reservada
        return WHILE;                       //Se envia el token de la palabra.
    if(strcmp(lexema,"if")==0)
        return IF;
    if(strcmp(lexema,"main")==0)
        return MAIN;
    if(strcmp(lexema,"return")==0)
        return RETURN;
    if(strcmp(lexema,"int")==0)
        return INT;
    if(strcmp(lexema,"float")==0)
        return FLOAT;
    if(strcmp(lexema,"double")==0)
        return DOUBLE;
    if(strcmp(lexema,"char")==0)
        return CHAR;
    if(strcmp(lexema,"string")==0)
        return STRING;
    if(strcmp(lexema,"bool")==0)
        return BOOL;
    return -1;
}

void mostrar(int token)         //Funcion para mostrar los tokens.
{
    switch(token)       //Mientras el token sea
    {
    case ID:                    //El token de ID
        printf("token = ID [%s] \n",lexema);        //Se imprime el caracter del token y su lexema.
        break;              //Al final se corta el bucle.
    case NUM:   
        printf("token = NUM [%s] \n",lexema);
        break;
    case SUMA:
        printf("token = SUMA [%c]\n",token);
        break;
    case RESTA:
        printf("token = RESTA [%c]\n",token);
        break;
    case PRODUCTO:
        printf("token = PRODUCTO [%c]\n",token);
        break;
    case DIVISION:
        printf("token = DIVISION [%c]\n",token);
        break;
    case MAYORIGUAL:
        printf("token = MAYORIGUAL [%s]\n",lexema);
        break;
    case MENORIGUAL:
        printf("token = MENORIGUAL [%s]\n",lexema);
        break;
    case PARI_E:
        printf("token = PARI_E [%c] \n",token);
        break;
    case PARI_S:
        printf("token = PARI_S [%c] \n",token);
        break;
    case CORCH_E:
        printf("token = CORCH_E [%c] \n",token);
        break;
    case CORCH_S:
        printf("token = CORCH_S [%c] \n",token);
        break;
    case LLAVE_E:
        printf("token = LLAVE_E [%c] \n",token);
        break;
    case LLAVE_S:
        printf("token = LLAVE_S [%c] \n",token);
        break;
    case MAYOR:
        printf("token = MAYOR [%c] \n",token);
        break;
    case MENOR:
        printf("token = MENOR [%c] \n",token);
        break;
    case ASIGNACION:
        printf("token = ASIGNACION [%c] \n",token);
        break;
    case IGUALDAD:
        printf("token = IGUALDAD [%s] \n",lexema);
        break;
    case NEGACION:
        printf("token = NEGACION [%c] \n",token);
        break;
    case DIFERENTE:
        printf("token = DIFERENTE [%s] \n",lexema);
        break;
    case COMA:
        printf("token = COMA [%c]\n",token);
        break;
    case PUNTOYCOMA:
        printf("token = PUNTOYCOMA [%c]\n",token);
        break;
    case COMENTARIO:
        printf("...COMENTARIO...\n");
        break;
    case WHILE:
        printf("token = WHILE [%s] \n",lexema);
        break;
    case IF:
        printf("token = IF [%s] \n",lexema);
        break;
    case MAIN:
        printf("token = MAIN [%s] \n",lexema);
        break;
    case RETURN:
        printf("token = RETURN [%s] \n",lexema);
        break;
    case INT:
        printf("token = INT [%s] \n",lexema);
        break;
    case FLOAT:
        printf("token = FLOAT [%s] \n",lexema);
        break;
    case DOUBLE:
        printf("token = DOUBLE [%s] \n",lexema);
        break;
    case CHAR:
        printf("token = CHAR [%s] \n",lexema);
        break;
    case STRING:
        printf("token = STRING [%s] \n",lexema);
        break;
    case BOOL:
        printf("token = BOOL [%s] \n",lexema);
    }
}