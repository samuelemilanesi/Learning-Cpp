/* Let's create a basic Class: we define a Stack class
 * which has the following methods:
 *      - push: appends a new element into the stack
 *      - pop: removes and returns the tail element from the stack
 *      - top: returns the head element of the stack
 */

#include <iostream>
#include "Stack.h"
using namespace std;


int main() {
    Stack pila;
    pila.push(5); //0
    pila.push(80); //1
    pila.push(-3);//2
    pila.pop(); //1
    pila.top();
    pila.push(4); //2
    pila.push(29); //3
    pila.push(33); //4 -> STACK FULL
    pila.push(-2912); //5 can't be pushed
    pila.pop();
    pila.push(-2912); // 4 (now can be pushed!)
    pila.top();
    return 0;
}