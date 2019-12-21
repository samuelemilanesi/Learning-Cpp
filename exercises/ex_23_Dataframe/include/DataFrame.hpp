#pragma once
#include<iostream>
#include<string>
#include<unordered_map>
#include<vector>
#include<sstream>

using std::cout; using std::cin; using std::string; using std::unordered_map; using std::vector;

class DataFrame {

typedef unordered_map< string, vector<double>>::const_iterator df_const_iter; 
typedef unordered_map< string, vector<double>>::iterator df_iter; 
typedef unordered_map< string, vector<double>> df;

private:
    df columns;
    string header;
    vector<string> split(const string& s, char d);
    bool exists_nonempty_col=false;
    df_iter nonempty_col_it;

    
public:
    DataFrame(const string& h);

    void set_column(const vector<double>& new_data, const string& col_name);

    void set_element_at(const string& col_name, std::size_t i, double val);

    double get_mean(const string& col_name) const;

    DataFrame set_equal(const string& col_name, double val) const;

    void print_header() const;

    void print_df() const;

};