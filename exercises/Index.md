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
Implementa class:

    Class Complex: class to deal with complex numbers in algebraic form implementing the operators + - * /; get phase, modulus, conjugate;

 
# ex_05: Pointers code analysis 
Analyze the code contained in the file pointers.cpp

# ex_06: Binary search
Implement a function that given an ORDERD vector of strings finds a given string performing binary search. Evaluate computational complexity.

# ex_07: Stock Prices 
The aim of this exercise is to implement a program for the U.S. stock quotes market.
A stock quote is characterized by its unique symbol (NASDAQ symbols are four or five
characters in length) and the last sale price values (the price at which a stock last traded
during regular market hours), quoted in U.S. dollars and cents.
We need to define two classes, namely `Stock_quote` and `Stock_quote_archive`.
In particular, the `Stock_quote`objects keep track of the price history in a `std::vector`, whilst
the `Stock_quote_archive` class stores stock quotes data in another `std::vector`.
Moreover, we want to provide the implementation of the following methods of the
`Stock_quote_archive` class:
• `add_stock_quote`, which adds a stock quote to the archive.
• `add_last_sale_price`, that, given a stock quote symbol and a price, appends the price
to the vector in the archived stock quote represented by the symbol.

# ex_08: Polynomial Root Finder
Implement a library in order to find a root of a given real  polynomialfunction $f:[a,b] \to \mathbb{R}$ using three numerical methods:
    - Bisection method
    - Newton method 
    - Bisection-Newton-pooled method (which uses bisection at first, and the result of bisection as input starting point for Newton's method)
There must be 3 possible stopping condition: 
    - INCREMENTS: absolute value of difference of the function evaluated at two consecutive iterations.
    - RESIDUAL: absolute value of the function evaluated in the point returned by the algorithm (i.e. distance from the zero value we want to find) 
    - BOTH: well... both

# ex_09: Gradient Descent in R
Implement a program that given a smooth function and its derivative (e.g. the class Polynomial defined in ex_8), finds the minimum of the function using a gradient descent algorithm with constant learning rate (i.e. descent step)

#ex_10: Gradient Descent in Rn 
*Uncompleted*

#ex_11: Social Network
Implement a simple social network according to the rules attached in the pdf file 
 
#ex_12: Employees
A company with three categories of employees (manager, developer and secretary) needs a program to manage the procedure of salary payment.
Each employee has the following information: name, surname, employee_ID and pay_rate (which is the amount of salary any kind of employee receives per hour). 
Managers and developers, in addition, have a workshop attendance rate (wsh_rate). Managers have also a mission rate (m_rate). Total work hours (work_hours), mission hours (m_hours) and workshop hours (wsh_hours) are set from employees’ worksheets through a suitable method.
Every employee is either manager, developer or secretary. Each of these positions provides its specific function to calculate monthly salary: 
- Managers:
    ((work_hours - m_hours - wsh_hours) * pay_rate) + (m_hours * m_rate) + (wsh_hours * wsh_rate)
- Developers:
    ((work_hours - wsh_hours) * pay_rate) + (wsh_hours * wsh_rate)
- Secretaries:
    (work_hours* pay_rate)

#ex_13: Interpolation
Develop a library that, given a vector of points, calculates their interpolation in a two dimensional Euclidean space with three different implementation methods:

- Linear interpolation, which connects the points with a straight line.
- Stepwise interpolation, which provides, within an interval bounded by subsequent points,
the y value of the left extreme.
- Nearest-neighbor interpolation, which locates in the vector the nearest point and assigns
the same value.

#ex_14: Block Matrix

