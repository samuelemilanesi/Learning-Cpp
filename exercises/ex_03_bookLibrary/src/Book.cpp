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
    return code;
}

unsigned Book::get_year() const{
    return year;
}


const string Book::get_author() const{
    return author;
}


const string Book::get_title() const{
    return title;
}

bool Book::isAvailable() const{
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
    cout<< "Author: "<< author << endl;
    cout<< "Book code: "<< code << endl;
    cout<< "Year of publication: "<< year<<endl;
    cout<< "Number of pages: "<< pages <<endl;
    cout<< "is Avaiable: "<< available <<endl;
}

bool operator==(const Book& a, const Book& b){

    return (a.code==b.code && a.author==b.author && a.title==b.title) ; 
}