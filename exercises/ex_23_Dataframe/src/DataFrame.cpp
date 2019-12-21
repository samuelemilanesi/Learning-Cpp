#include "DataFrame.hpp"

DataFrame::DataFrame(const string &h)
    : header(h)
{
    vector<string> col_names(split(header, ' '));

    for (auto it = col_names.cbegin(); it != col_names.cend(); ++it)
    {

        columns.insert(std::pair(*it, vector<double>{}));
    }
}

void DataFrame::set_column(const vector<double> &new_data, const string &col_name)
{
    df_iter col_it(columns.find(col_name));
    if (col_it != columns.end())
    {
        if (!exists_nonempty_col)
        {
            (*col_it).second = new_data;
            exists_nonempty_col = true;
            nonempty_col_it = col_it;
        }
        else
        {
            if ((*nonempty_col_it).second.size() != new_data.size())
            {
                std::cerr << "New column must have " << (*nonempty_col_it).second.size() << " rows" << std::endl;
            }
            else
            {
                (*col_it).second = new_data;
            }
        }
    }
    else
    {
        std::cerr << "Column not found" << std::endl;
    }
}

void DataFrame::set_element_at(const string &col_name, std::size_t i, double val)
{
    df_iter col_it(columns.find(col_name));
    if (col_it != columns.end() && i < (*col_it).second.size())
    {
        (*col_it).second[i] = val;
    }
    else
    {
        if (col_it == columns.end())
        {
            std::cerr << "Column not found" << std::endl;
        }
        else
        {
            std::cerr << "Error: index greater than " << ((*col_it).second.size() - 1) << std::endl;
        }
    }
}

double DataFrame::get_mean(const string &col_name) const
{
    double mean(0);
    df_const_iter col_it(columns.find(col_name));
    if (col_it != columns.end())
    {
        for (auto k = (*col_it).second.begin(); k != (*col_it).second.end(); ++k)
        {
            mean += *k;
        }
        mean = mean / ((double)((*col_it).second.size()));
    }
    else
    {
        std::cerr << "Column not found" << std::endl;
    }
    return mean;
}

DataFrame DataFrame::set_equal(const string &col_name, double val) const
{
    DataFrame res(header);
    df_const_iter col_it(columns.find(col_name));
    if (col_it != columns.end())
    {
        vector<std::size_t> saved_indexes;

        for (std::size_t k = 0; k < (*col_it).second.size(); ++k)
        {
            if (val == (*col_it).second[k])
                saved_indexes.push_back(k);
        }
        for (auto res_col = res.columns.begin(); res_col != res.columns.end(); ++res_col)
        {
            vector<double> v;
            for (auto x : saved_indexes)
            {
                v.push_back(columns.at(res_col->first)[x]);
            }
            res.set_column(v, res_col->first);
        }
    }
    else
    {
        std::cerr << "Column not found" << std::endl;
    }

    return res;
}

vector<string> DataFrame::split(const string &s, char d)
{
    std::istringstream istr{s};
    string caption;
    vector<string> res;
    while (getline(istr, caption, d))
    {
        res.push_back(caption);
    }
    return res;
}

// Printers

void DataFrame::print_header() const
{
    cout << "DataFrame columns: \n"
         << std::endl;

    for (auto it = columns.cbegin(); it != columns.cend(); ++it)
    {
        cout << (*it).first << "\t\t";
    }
    cout << "\n----------------------------------------------------------------------\n"
         << std::endl;
}

void DataFrame::print_df() const
{
    print_header();

    if (exists_nonempty_col)
    {
        for (std::size_t k = 0; k < (*nonempty_col_it).second.size(); ++k)
        {
            for (auto it = columns.cbegin(); it != columns.cend(); ++it)
            {
                cout << (it->second)[k] << "\t\t";
            }

            cout << std::endl;
        }
    }
    else
    {
        cout << "No data inserted" << std::endl;
    }
}
