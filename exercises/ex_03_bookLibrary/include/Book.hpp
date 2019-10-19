#pragma once
#include <iostream>
#include <string>
using std::string; using std::cout; using std::cin; using std::endl;


class Book {


private:
    unsigned code; // unique code of the book
    const string author; // author of the book
    const string title; // book title
    unsigned year; // year of publication
    unsigned pages; // number of pages
    bool available; // is it available in the library or not

public:
    Book(unsigned int code, const string& author, const string& title, 
    unsigned year, unsigned pages, bool av);

    unsigned get_code() const;
    const string get_author() const;
    const string get_title() const;
    bool isAvailable() const;
    void setAvailable(bool); // sets the availability
    void print() const; // prints infos of the book;
};