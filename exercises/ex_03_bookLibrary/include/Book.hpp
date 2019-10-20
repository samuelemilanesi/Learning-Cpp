#pragma once
#include <iostream>
#include <string>
using std::string; using std::cout; using std::cin; using std::endl;
using std::cerr;

class Book {

friend bool operator==(const Book&, const Book&);

private:
    unsigned code; // unique code of the book
    string author; // author of the book
    string title; // book title
    unsigned year; // year of publication
    unsigned pages; // number of pages
    bool available; // is it available in the library or not

public:

    Book(unsigned int code, const string& author, const string& title, 
    unsigned year, unsigned pages, bool av); //constructor

    unsigned get_code() const;
    const string get_author() const;
    const string get_title() const;
    unsigned get_year() const;

    bool isAvailable() const;
    void setAvailable(bool); // sets the availability
    void print() const; // prints infos of the book;
};