/*////////////////////////////ENUNCIADO////////////////////////////
EJEMPLO DE FUNCIONAMIENTO DE UNA PILA
*/


/*////////////////////////////CODIGO////////////////////////////*/

#include <iostream> 
#include <stack> 
using namespace std;
int main() {
    stack<int> stack;
    stack.push(21);
    stack.push(22);
    stack.push(24);
    stack.push(25);
      
    stack.pop();
    stack.pop();
  
    while (!stack.empty()) {
        cout << ' ' << stack.top();
        stack.pop();
    }
}

/*////////////////////////////EJECUCION////////////////////////////

PS E:\C++\2022\EPCC_COMPILADORES_2022\Semana09> g++ Pila.cpp      
PS E:\C++\2022\EPCC_COMPILADORES_2022\Semana09> .\\a        
 22 21

*/