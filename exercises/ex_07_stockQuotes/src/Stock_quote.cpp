#include "Stock_quote.hpp"

Stock_quote::Stock_quote(const string& id, float price):
    id(id){
        price_history.push_back(price);
    }

//getters

float Stock_quote::get_last_price() const{ //returns the last-updated price of the stock
    return price_history.back();
}
string Stock_quote::get_id() const{ //returns the last-updated price of the stock
    return id;
}
    
// modifiers
void Stock_quote::add_price(float new_price){//add a new price to the stock history
 
    price_history.push_back(new_price);
}


// printer
void Stock_quote::print() const{// prints ID and last price of the stock

    cout<< "\n\n----------------------------------------"<<endl;
    cout<< "\nStock ID: " << id <<endl;
    cout<< "\nCurrent price: "<< price_history.back() << endl;
    cout<< "\n----------------------------------------"<<endl;
} 