#pragma once
#include "Book.hpp"
#include <vector>
using std::vector;
class bookLibrary {

private:
    vector<Book> books;

    // Returns the position of a book in the library (if it exists)
    int find(const string& tit, const string& auth) const; 

    // Returns the position of a book in the library (if it exists) passing auth and title
    int findAvailableBook(const string& tit, const string& auth) const; 


public:

    void addBook(const Book& b); //add a book to the library
   
    //function to rent a book passing as input a Book object
    void rentBook(const Book& b) ; 

    // function to rent a book passing as input only author and title
    void rentBook(const string& tit, const string& auth) ; 

    // fun to return a rented book passing its code
    void returnBook(const unsigned) ; 

    void print() const; // Prints the whole library
    void printOldestBook() const; // prints infos of the oldest book in the library


};