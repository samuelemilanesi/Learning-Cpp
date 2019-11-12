///Header include
#include "social_network.hpp"
#include "user.hpp"

///STD include
#include <iostream>

namespace SocialNetworkNS
{
  size_t SocialNetwork::CUserIndex(const std::string & name, 
                                   const std::string & surname) const
  {
      size_t i;

      User u(name, surname);

      bool found = false;

      for (i = 0; i < users.size() && !found; ++i)
          if (users[i] == u)
              found = true;

      if (found)
          return --i;
      else
          return users.size();
  }

  void SocialNetwork::AddUser(const std::string & name, 
                              const std::string & surname)
  {
    friends.push_back( std::vector<size_t> {} );
    users.push_back(User(name, surname));

  }

  const std::vector<User> SocialNetwork::CGetUsers() const
  {
      return users;
  }


  const std::vector<User> SocialNetwork::CGetFriends(const User & user) const
  {
    return CGetFriends(user.CGetName(),user.CGetSurname());
  }


  const std::vector<User> SocialNetwork::CGetFriends(const std::string & name, 
                                            const std::string  & surname) const
  {
    std::vector<size_t> user_indexes;
    size_t user_index = CUserIndex(name,surname); 
    if(user_index!=users.size()){
        std::vector<User>  res;
        for(auto j: friends[user_index])
        {
            res.push_back(users[j]);
        }   
        return res;
    }else
    {
        std::cerr<<"User not found"<<std::endl;
        return std::vector<User> {}; 
    }
  }

  void SocialNetwork::AddFriendship(const std::string & first_name, 
                                    const std::string & first_surname, 
                                    const std::string & second_name, 
                                    const std::string & second_surname)
  {

    size_t first_index = CUserIndex(first_name,first_surname);
    size_t second_index = CUserIndex(second_name,second_surname);
    if (first_index != users.size() && second_index!=users.size() && first_index!=second_index)
    {   
        friends[first_index].push_back(second_index);
        friends[second_index].push_back(first_index);
    }else{
        std::cerr<<"Not suitable friendship assignment"<<std::endl;
    }

  }

}
