#include <iostream>
#include "Stock_quote.hpp"
#include "Stock_quote_archive.hpp"

int main() {

    Stock_quote apple("AAPL", 245.96);
    

    Stock_quote google("GOOGL", 1264.30);
    Stock_quote amazon("AMZN",1761.33);
    
    Stock_quote_archive my_stocks;

    apple.add_price(12.0);
    
    my_stocks.add_stock_quote(apple);
    my_stocks.add_stock_quote(google);
    my_stocks.add_stock_quote(amazon);
    my_stocks.add_last_sale_price("AAPL",246.58);


    my_stocks.print();

   

return 0;
}