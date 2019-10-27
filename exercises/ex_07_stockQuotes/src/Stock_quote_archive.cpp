#include "Stock_quote_archive.hpp"

Stock_quote_archive::Stock_quote_archive() {}

Stock_quote_archive::Stock_quote_archive(vector<Stock_quote>& archive):
    archive(archive) {}

void Stock_quote_archive::add_stock_quote(Stock_quote& new_stock){
    archive.push_back(new_stock);
}

void Stock_quote_archive::add_last_sale_price(const string& xID, const float xPrice){

    bool stock_found=false;
    for(int i=0; i<archive.size();++i){
        if(archive[i].get_id()==xID){
            archive[i].add_price(xPrice);
            stock_found=true;
            break;
        }
    }
    if(!stock_found){
        std::cerr<<"\n\nStock not present in the archive, please add it before updating its price\n"<< endl;
    }
}


// printer

void Stock_quote_archive::print() const{
    
    for(auto i=archive.cbegin(); i!=archive.cend();++i){
        (*i).print();
    }

}