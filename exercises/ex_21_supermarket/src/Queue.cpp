#include "Queue.hpp"

bool Queue::add_to_queue(const string &ID)
{
    std::pair<unordered_set<string>::const_iterator, bool> insert_result = people_set.insert(ID);
    if (insert_result.second)
    {
        people_order.push(ID);
    }
    return insert_result.second;
}

string Queue::next_client()
{
    string result = people_order.front();
    people_order.pop();
    people_set.erase(result);
    return result;
}

bool Queue::is_empty() const
{
    return people_set.empty();
}
