#pragma once

#include<queue>
#include<string>
#include<unordered_set>
#include<iostream>
#include<deque>
using std::queue; using std::string; using std::unordered_set;


class Queue {
private:
    queue<string> people_order;
    unordered_set<string> people_set;

public:
    Queue()=default;
    
    // add a client to the queue returns 0 if the client is already in the queue
    bool add_to_queue(const string& ID);

    // returns the ID of next client to serve (first person in the queue)
    string next_client();

    // returns TRUE if the queue is empty
    bool is_empty() const;


};