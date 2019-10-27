#pragma once
#include "Stock_quote.hpp"

class Stock_quote_archive {
private:
    vector<Stock_quote> archive;


public:
    Stock_quote_archive(vector<Stock_quote>& );
    Stock_quote_archive();

    void add_stock_quote(Stock_quote&);
    void add_last_sale_price(const string&, const float); 

// printer 
    void print() const;

};