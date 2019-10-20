# ex_01: Sudoku check
Create a function that given a 3^N x 3^N solved sudoku returns TRUE if the solution is correct, FALSE otherwise

# ex_02: Array Stack
Implement a class Stack for integers with methods:
    - top(): returns the head of the stack
    - pop(): returns the last element in the stack and then pops it out
    - push(int x): append the integer x to the stack

# ex_03: Book library
    1. Implement a Book class with the following members:
        - unsigned code; // unique code of the book
        - string author; // author of the book
        - string title; // book title
        - unsigned year; // year of publication
        - unsigned pages; // number of pages
        - bool available; // is it available in the library or not
        - setAvailable(bool av) // sets the availability to av
        - print() // prints infos of the book;
        
        - an operator == for the class to compare if two books are the same (i.e. same author and title)
    
    2. Implement a Library class with the following members:
        - a vector of books
        - addBook(const Book & b); //add a book to the library
        - rentBook; //function to rent a book passing as input a Book object
        - rentBook; // function to rent a book passing as input only author and title
         title
        - returnBook // fun to return a rented book passing its code
        - print() // Prints the whole library
        - printOldestBook() // prints infos of the oldest book in the library
        - find; (private) // function to find if a book exists in the library a book
        - findAvailableBook // (private) fun to find if a book exist and is avialable passing a book

# ex_04: Complex numbers
Implement two classes:

    1. Class Complex: class to deal with complex numbers in algebraic form implementing the operators + - * /

    2. Class Complex_polar: class to deal with complex numbers in polar form implementing the operators + - * /

# ex_05: Pointers code analysis 
Analyze the code contained in the file pointers.cpp

# ex_06: Binary search
Implement a function that given an ORDERD vector of strings finds a given string performing binary search. Evaluate computational complexity.


