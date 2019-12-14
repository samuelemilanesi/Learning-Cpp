#pragma once
#include <map>
#include <iostream>
#include <sstream>
#include <string>
#include <list>

using std::cout; using std::cin; using std::map; using std::string; using std::list;


class Messenger {
private: 
    map<int, string> messages;

    bool word_in_text(const string& ,const string& ) const;

public:
    Messenger()=default;
    
    // adds the message < timestamp, text > to messages
    void send(int timestamp, const string& text);

    // returns all the messages after timestamp
    map<int,string> last_messages(int timestamp) const;

    // returns al the messages containing 'word' in their text
    list<std::pair<int,string>> find_message(const string&) const;
    
};