#include "Messenger.hpp"


bool Messenger::word_in_text(const string& word , const string& text ) const
{
    std::istringstream itext{text};
    string cword;
    while(getline(itext, cword,' '))
    {
        if(word==cword)
            return true;
    }    
    return false;
}


void Messenger::send(int timestamp, const string& text)
{
    messages.emplace(timestamp,text);
}

map<int,string> Messenger::last_messages(int timestamp) const
{
    map<int,string>result;
    result.insert(messages.lower_bound(timestamp),messages.cend());
    return result;

}

list<std::pair<int,string>> Messenger::find_message(const string& word) const
{
    list<std::pair<int,string>> result;
    for(auto it=messages.cbegin(); it!=messages.cend(); ++it)
    {
        if(word_in_text(word, it->second))
            result.push_back(*it);
    }
    return  result;
}
