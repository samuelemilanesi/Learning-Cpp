#include "Book.hpp"

Book::Book(unsigned int code, const string& author, const string& title, 
unsigned year, unsigned pages, bool av):
        code(code), 
        author(author),
        title(title),
        year(year),
        pages(pages), 
        available(av){};

unsigned Book::get_code() const{
    cout<< "Book code: " << code << endl ;
    return code;
}

const string Book::get_author() const{
    cout<< "Book author: " << author << endl ;
    return author;
}


const string Book::get_title() const{
    cout<< "Book title: " << title << endl ;
    return title;
}

bool Book::isAvailable() const{
    if(available){ 
        cout<< "The book is available" << endl;
    }else{cout <<"The book is NOT available"<<endl;}
    return available;
}

void Book::setAvailable(bool av){
    if(av){
        cout<< "The book is now available" << endl;
    }else{cout <<"The book is now NOT available"<<endl;}
    available=av;
}

void Book::print() const{
    
    cout<< "Title: "<< title << endl;
    cout<< "Author: "<< code << endl;
    cout<< "Book code: "<< code << endl;
    cout<< "Year of publication: "<< year<<endl;
    cout<< "Number of pages: "<< pages <<endl;
    cout<< "is Avaiable: "<< available <<endl;
}