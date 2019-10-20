#include <iostream>
#include "Book.hpp"
#include "bookLibrary.hpp"

int main() {

    
    Book convivio(1,"Dante Alighieri","Il Convivio",1307,190,true);

    Book divComm(2,"Dante Alighieri","La Divina Commedia", 1321, 540, true);

    Book pinocchio(3,"Carlo Collodi", "Le aventure di Pinocchio - Storia di un burattino",
     1883, 500, true);

    bookLibrary myLib;
    myLib.addBook(divComm);
    myLib.addBook(pinocchio);
    myLib.addBook(convivio);
  
    
    cout<<"++++++\n\n"<<endl;

    myLib.print();

    cout<<"\n\n...................................\n\n"<<endl;
    cout<<"renting Pinocchio"<<endl;
    myLib.rentBook(pinocchio);
    cout<<"renting Pinocchio again"<<endl;
    myLib.rentBook(pinocchio);
    cout<<"returning Pinocchio"<<endl;
    myLib.returnBook(3);
    cout<<"rent Pinocchio for the third time"<<endl;
    myLib.rentBook(pinocchio);

    myLib.print();

    cout<<"\n\nThe oldest book in my library is:\n"<<endl;
    myLib.printOldestBook();
    return 0;
}