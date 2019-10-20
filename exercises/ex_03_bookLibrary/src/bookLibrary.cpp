#include "bookLibrary.hpp"

int bookLibrary::find(const string& tit, const string& auth) const{

    for(unsigned i=0; i<books.size(); ++i ){
        if(books[i].get_title()==tit && books[i].get_author()==auth){
            return i;
        }
    }
    cerr<< "Book not present in stock"<<endl;
    return -1;
 }

int bookLibrary::findAvailableBook(const string& tit, const string& auth) const{
    int k=find(tit,auth);
    
    if (k!=0){
        if(!books[k].isAvailable()){
            cerr<<"Book not available" << endl;
        }else{
            return k;
        }
    }
    return -1;
}


void bookLibrary::addBook(const Book& b){
    books.push_back(b);
};


void bookLibrary::rentBook(const Book& b) {

    int k=findAvailableBook(b.get_title(),b.get_author());

    if(k!=-1){
        cout<< "Book rented!"<<endl;
        books[k].setAvailable(false);
    }else{
        cerr<<"Not possible to rent the book"<<endl;
    }
}
void bookLibrary::rentBook(const string& tit, const string& auth) {

    int k=findAvailableBook(tit,auth);

    if(k!=-1){
        cout<< "Book rented!"<<endl;
        books[k].setAvailable(false);
    }else{
        cerr<<"Not possible to rent the book"<<endl;
    }
}

void bookLibrary::returnBook(const unsigned code){
bool inStock=false;
    for(unsigned i=0; i<books.size(); ++i){

        if(books[i].get_code()==code){
            inStock=true;
            if(!books[i].isAvailable()){
                books[i].setAvailable(true);
                cout<<"Book returned"<<endl;
            }else{
                cerr<<"Stolen book returned"<<endl;
            }
        }
    }
    if(!inStock) 
        cerr<<"Book not in stock: cannot be returned!"<<endl;
} 

void bookLibrary::print() const{

    if(books.size()>0){
        for(unsigned i=0; i<books.size();++i){

            books[i].print();
            cout<<"--------"<<endl;
        }
    }else{
            cout<<"No book in the library"<<endl;
        }
}


void bookLibrary::printOldestBook() const{
int oldestBookIndex=0;


    if(books.size()>0){
        for(unsigned i=0; i<books.size();++i){
            if(books[oldestBookIndex].get_year()>books[i].get_year())
                 oldestBookIndex=i;
        }

        books[oldestBookIndex].print();
    }else{
            cout<<"No book in the library"<<endl;
        }
}

