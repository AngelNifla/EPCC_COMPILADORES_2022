#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <fstream>   //Incluimos la libreria fstream para abrir un documento y leer cada linea de ella.

int contadorlineas{};
std::string linea{},aux_linea{},aux_linea2{};
std::string nombre_archivo;     //En una variable tipo string agregamos el nombre del archivo del texto plano.
std::ifstream archivo;  //Se abre el archivo.

void correcto();            //Funcion que devuelve un consaje de correcto.
void error();           //Funcion que devuelve un mesaje de error.
void ignorar_salto_espacio_linea();         //Funcion que ignora los espacios en baldo, saltos de linea y tab.
void parea();           //Funcion que colecciona el un string todas las lineas de codigo de un txt.
void inicio();          //Funcion que da inicio, comrobando el token INICIO.
bool bloque();          //Funcion que verifica el bloque.
bool expresion();           //Funcion que verifica las expresiones.
bool campo();           //Funcion que verifica los campos en las expresiones.
bool num();         //Funcion que verifica los numeros.
bool signo();           //Funcion que verifica los signos.
bool fin();         //Funcion que verifica el token FIN.
int postfija();         //Funcion que que devuelve la expresion postfija y el resultado.


void correcto()         //Funcion que devuelve un consaje de correcto.
{
    printf("\n-> Sintaxis correcta.");
}

void error()            //Funcion que devuelve un mesaje de error.
{
    printf("\n-> Error de sintaxis.");
    exit(-1);
}

void ignorar_salto_espacio_linea()          //Funcion que ignora los espacios en baldo, saltos de linea y tab.
{
    while (linea[0] == ' ' ||linea[0]== '\t' || linea[0] =='\n')
    {
        linea.erase(linea.begin()); 
    }
}

void parea()            //Funcion que colecciona el un string todas las lineas de codigo de un txt.
{

    if(getline(archivo, linea))
    {
        aux_linea = linea;
        while (getline(archivo, linea))
        {
            aux_linea.append(linea);
        }
        linea = aux_linea;
        aux_linea2 = aux_linea;
    }else
    {
        std::cout<<"\n->Archivo vacio.\n";
        error();
    }
}

void inicio()           //Funcion que da inicio, comrobando el token INICIO.
{
    parea();
    bool ok{false};
    std::string aux;
    while (linea[0]!= '\0')
    {
        if (linea[0] >= 'A' && linea[0] <= 'Z')
        {
            aux.push_back(linea[0]);
            ok=true;
        }else if (ok)
        {
            break;
        }else if (linea[0]!=' ' ||linea[0]!='\t' || linea[0]!='\n')
        {
            error();
        }
        linea.erase(linea.begin()); 
    }
    if (aux == "INICIOFIN")
    {
        correcto();
    }else if (aux == "INICIO" && bloque())
    {
        correcto();
    }else
    {
        error();
    }
}

bool bloque()           //Funcion que verifica el bloque.
{
    ignorar_salto_espacio_linea();
    if (expresion())
    {
        if (linea[0]==';')
        {
            linea.erase(linea.begin());
            contadorlineas++;
            if ((fin()||bloque()))
            {
                return true;
            }
        }
    }else
    {
        error();
    }
}

bool expresion()            //Funcion que verifica las expresiones.
{
    if (campo() && signo() && campo())
    {
        return true;
    }else
    {
        return false;
    }
    
}

bool campo()            //Funcion que verifica los campos en las expresiones.
{
    if (linea[0]=='(')
    {
        linea.erase(linea.begin());
        ignorar_salto_espacio_linea();
        if (expresion() && linea[0] == ')')
        {
            linea.erase(linea.begin());
            ignorar_salto_espacio_linea();
            return true;
        }else
        {
            return false;
        } 
    }else if (num())
    {
        return true;
    }else
    {
        return false;
    }
}

bool num()          //Funcion que verifica los numeros.
{
    if (linea[0]>='0' && linea[0]<='9')
    {
        linea.erase(linea.begin());
        if (num()){}
        ignorar_salto_espacio_linea();
        return true;
    }else
    {
        return false;
    }
}

bool signo()            //Funcion que verifica los signos.
{
    if (linea[0] == '+'||linea[0] == '-' ||linea[0] == '*' ||linea[0] == '/')
    {
        linea.erase(linea.begin());
        ignorar_salto_espacio_linea();
        return true;
    }else
    {
        return false;
    }
}

bool fin()          //Funcion que verifica el token FIN.
{
    bool ok{false};
    std::string aux;
    while (linea[0]!= '\0')
    {
        if (linea[0] >= 'A' && linea[0] <= 'Z')
        {
            aux.push_back(linea[0]);
            ok=true;
        }else if (ok)
        {
            break;
        }else if (linea[0]!=' ' ||linea[0]!='\t' || linea[0]!='\n')
        {
            return false;
        }
        linea.erase(linea.begin()); 
    }
    if (aux == "FIN")
    {
        return true;
    }else
    {
        return false;
    }
}


///////////////////////////////POSTFIJO Y REAULTADO////////////////////////////////////
std::string exp_postfija{};

int postfija()          //Funcion que que devuelve la expresion postfija y el resultado.
{
    int resultado_exp{},variable{},variable_parentesis{NULL};
    char signo{0};
    int aux_num{0};
    while (aux_linea2[0]!=';' && aux_linea2[0]!='\0')
    {
        if (aux_linea2[0]=='(')
        {
            aux_linea2.erase(aux_linea2.begin());
            if (signo!=0)
            {
                int nuevo{postfija()};
                exp_postfija.push_back(signo);
                exp_postfija.push_back(' ');
                aux_linea2.erase(aux_linea2.begin());
                if (signo == '+')
                {
                    return variable_parentesis + nuevo;
                }else if (signo == '-')
                {
                    return variable_parentesis - nuevo;
                }else if (signo == '*')
                {
                    return variable_parentesis * nuevo;
                }else
                {
                    return variable_parentesis / nuevo;
                }
            }else
            {
                variable_parentesis = postfija();
                resultado_exp = variable_parentesis;
            } 
        }
        if (aux_linea2[0]>='0' && aux_linea2[0]<='9')
        {
            exp_postfija.push_back(aux_linea2[0]);
            if (aux_num==0)
            {
                variable = aux_linea2[0] - 48;
                aux_num=1;
            }else
            {
                variable = (variable*10) + ((aux_linea2[0]) - 48);
            }
        }else if (aux_linea2[0] == '+'||aux_linea2[0] == '-' ||aux_linea2[0] == '*' ||aux_linea2[0] == '/')
        {
            signo =aux_linea2[0];
            if (variable_parentesis==NULL)
            {
                resultado_exp = variable;
            }
            variable = 0;
            aux_num = 0;
            exp_postfija.push_back(' ');
        }

        if (aux_linea2[1]==';' || aux_linea2[1] == ')')
        {
            exp_postfija.push_back(' ');
            exp_postfija.push_back(signo);
            exp_postfija.push_back(' ');
            aux_linea2.erase(aux_linea2.begin());
            if (signo == '+')
            {
                aux_linea2.erase(aux_linea2.begin());
                return resultado_exp + variable;
            }else if (signo == '-')
            {
                aux_linea2.erase(aux_linea2.begin());
                return resultado_exp - variable;
            }else if (signo == '*')
            {
                aux_linea2.erase(aux_linea2.begin());
                return resultado_exp * variable;
            }else
            {
                aux_linea2.erase(aux_linea2.begin());
                return resultado_exp / variable;
            }
        }else
        {
            aux_linea2.erase(aux_linea2.begin());
        }
    }
}