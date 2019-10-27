#pragma once
#include <iostream>
#include <string>
#include <vector>
using std::cout; using std::cin; using std::endl;
using std::string; using std::vector;

class Stock_quote {

private:
    const string id; // stock's ID
    vector<float> price_history; //Vector containing the history of prices

public:
    Stock_quote(const string&, float); // constructor: takes ID and price
    
// getters
    float get_last_price() const; //returns a ref to the last-updated price of the stock
    string get_id() const;
// modifiers  
    void add_price(float); //add a new price to the stock history

// printers
    void print() const; // prints ID and last price of the stock
};