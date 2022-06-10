/*////////////////////////////ENUNCIADO////////////////////////////

Desarrollar un programa para evaluar expresiones aritméticas por medio de una pila. La
entrada se encuentra en su forma postfija. Ejemplo: 52 13 +
*/

/*////////////////////////////CODIGO////////////////////////////*/

#include <iostream> 
#include <stack> 
#include <math.h>
#include <string>
using namespace std;

int cambiando_caracter(char c)      //Convierte codigo ascii de los numeros a sus respectivos valores,
{
    if (c == '1')
    {return 1;}
    else if (c == '2')
    {return 2;}
    else if (c == '3')
    {return 3;}
    else if (c == '4')
    {return 4;}
    else if (c == '5')
    {return 5;}
    else if (c == '6')
    {return 6;}
    else if (c == '7')
    {return 7;}
    else if (c == '8')
    {return 8;}
    else if (c == '9')
    {return 9;}
    else {return 0;}
    
}


int evaluando(stack<char> stack)        //Evalua los valores en la pila, las reconoce , las borra hasta vaciarce.
{
    char aux{NULL};
    int num{0},num_aux{0},cont{0};
    if(!stack.empty())
    {
        if (stack.top()<'0' || stack.top()>'9')
        {
            aux = stack.top();
            stack.pop();
            stack.pop();
        }
        if (aux != NULL)
        {
            while (stack.top() != ' ')
            {
                num_aux = cambiando_caracter(stack.top());
                num = num + num_aux*(pow(10,cont));
                cont++;
                stack.pop();
            }
            stack.pop();
            cont = 0;
               
            if(aux == '+')
            {
                num = evaluando(stack) + num;
            }else if (aux == '-')
            {
                num = evaluando(stack) - num;
            }else if (aux == '*')
            {
                num = evaluando(stack) * num;
            }else if (aux == '/')
            {
                num = evaluando(stack) / num;
            }
            return num;
        }else
        {
            while (!stack.empty())
            {
                num_aux = cambiando_caracter(stack.top());
                num = num + (num_aux*(pow(10,cont)));
                cont++;
                stack.pop();
            }
            cont=0;
            return num;
        }
    }else
    {
        cout<<"-> Pila vacia.\n";
        exit(-1);
    }
    
}


int main()          //Funcion principal.
{            
    string expresion{};
    stack<char> stack;
    int resultado;

    cout<<"Ingrese expresion en postfija: ";
    getline(cin,expresion);
    
    for (int i = 0; i < expresion.size(); i++)
    {
        stack.push(expresion[i]);
    }
    resultado = evaluando(stack);
    cout<<"-> El resultado de la expresion es: "<<resultado;
}

/*////////////////////////////EJECUCION////////////////////////////

PS E:\C++\2022\EPCC_COMPILADORES_2022\Semana09> .\\a
Ingrese expresion en postfija: 15 15 +
-> El resultado de la expresion es: 30
PS E:\C++\2022\EPCC_COMPILADORES_2022\Semana09> .\\a
Ingrese expresion en postfija: 15 5 - 3 +
-> El resultado de la expresion es: 13
PS E:\C++\2022\EPCC_COMPILADORES_2022\Semana09>

*/
