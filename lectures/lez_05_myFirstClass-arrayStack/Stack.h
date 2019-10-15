/* This file defines the HEADER of the Stack class
 * every declaration goes in here
 * this make easier to include the stack class into projects
 * because I can include just the header
 */

#ifndef LEZ_05_MYFIRSTCLASS_ARRAYSTACK_STACK_H
#define LEZ_05_MYFIRSTCLASS_ARRAYSTACK_STACK_H

const int maxSize=5;
class Stack {

public: // the public part can be accessed by the program directly invoking the
        // method or accessing the variable with syntax "obj.Method(...)"
    Stack(){maxIndex=-1;} // the CONSTRUCTOR is invoked every time a stack object is created
    int top();
    int pop();
    void push(int x);

private: // the private part is cannot be accessed by the program directly but only by
         // other methods in the same class
    bool isEmpty() const; //const means that this method do not change the obj status!
    bool isFull() const;
    int arr[maxSize]; //my stack contains INTEGERS
    int maxIndex;
};


#endif //LEZ_05_MYFIRSTCLASS_ARRAYSTACK_STACK_H
