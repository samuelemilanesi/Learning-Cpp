#include <iostream>
#include "DataFrame.hpp"
int main()
{
    cout<<"Creating the DataFrame...\n\n"<< std::endl;

    DataFrame dataf("x_coord y_coord z_coord temperature");

    cout<<"Filling the DataFrame...\n\n"<< std::endl;

    dataf.set_column(vector<double>{1,8,36,14,9,1},"x_coord");
    dataf.set_column(vector<double>{5,8,59,84,5,4},"y_coord");
    dataf.set_column(vector<double>{8,5,48,45,4,3},"z_coord");
    dataf.set_column(vector<double>{25,25.6,26.5,24.3,24.02,27.5},"temperature");

    cout<<"Printing the DataFrame...\n\n"<< std::endl;

    dataf.set_column(vector<double>{8,5,48,45,4,3},"z_coord");

    dataf.print_df();

    cout<<"Modifying a column of the DataFrame...\n\n"<< std::endl;
    dataf.set_column(vector<double>{15,15.6,16.5,14.3,14.02,17.5},"temperature");
    cout<<"Printing the modified DataFrame...\n\n"<< std::endl;
    dataf.print_df();

    cout<<"Modifying an element of the DataFrame...\n\n"<< std::endl;

    dataf.set_element_at("x_coord", 3, 22.3);

    cout<<"Printing the 2nd modified DataFrame...\n\n"<< std::endl;

    dataf.print_df();

    cout<<"Creating the cutted DataFrame...\n\n"<< std::endl;

    DataFrame cutted_df=dataf.set_equal("x_coord", 1);

    cout<<"Printing cutted DataFrame...\n\n"<< std::endl;

    cutted_df.print_df();
    
    cout<<"Trying to do somthing wrong on the DataFrame...\n\n"<< std::endl;
    dataf.set_column({1,2,2},"x_coord");
    











}