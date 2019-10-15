/* This is the definition file
 * here we define every method we have declared in the HEADER
 */

#include "Stack.h"
#include <iostream>

void Stack::push(int x){
    if(isFull()){
        std::cout<<"Stack Overflow"<< std::endl;
    }else {
        arr[++maxIndex] = x;
        std::cout<< "Element "<<x<<" appended into the stack"<<std::endl;
    }
}

int Stack::pop(){
    if(isEmpty()){
        std::cout<<"Stack Underflow"<<std::endl;
        return 0;
    } else{

        std::cout<< "Element "<<arr[maxIndex]<<" popped out from the stack"<<std::endl;
        return arr[maxIndex--];
    }
}

int Stack::top(){
    if(isEmpty()){
        std::cout<<"The stack is empty"<<std::endl;
        return 0;
    } else{
        std::cout<< "The top value is: "<< arr[maxIndex]<<std::endl;
        return arr[maxIndex];
    }
}

bool Stack::isEmpty() const {
    return maxIndex<0;
}

bool Stack::isFull() const {

    return maxIndex>=(maxSize-1);
}