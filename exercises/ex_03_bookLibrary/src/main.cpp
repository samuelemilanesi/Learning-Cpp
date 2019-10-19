#include <iostream>
#include "Book.hpp"

int main() {

    cout << "Creating a book"<< endl;
    
    Book myBook(1,"Dante Alighieri","Il Convivio",1307,190,true);
    myBook.print();


    return 0;
}