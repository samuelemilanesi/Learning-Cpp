#include "FileManager.h"
#include <iostream>
using std::cerr;
using std::endl;
using std::string;
using std::ifstream;
using std::istringstream;
const table_type &FileManager::parse_file(const std::string &filename, char d)
{
    std::ifstream i_csv{filename}; // stream to read the file
    table_type *dataptr = new table_type;
    if (i_csv)
    {
        std::string line; // stores the line we're reading
       
        while (getline(i_csv, line)) // iterate the file line-by-line
        {
            dataptr->push_back({});          // insert new row in the table
            std::string field;               // temporarly store here every data in the row
            std::istringstream i_line{line}; // stream to read the row

            while (getline(i_line, field, d)) // iterate the file field-by-field
            {
                dataptr->rbegin()->push_back(field); //push the field in the last row
            }
        }
    }
    else
        cerr << "ERROR in FileManager::parse_csv - file "
             << filename << " cannot be opened" << endl;

    return *dataptr;
}
