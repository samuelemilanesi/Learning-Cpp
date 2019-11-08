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
    users.push_back(User(name, surname));

  }

  const std::vector<User> SocialNetwork::CGetUsers() const
  {
      return users;
  }


  const std::vector<User> SocialNetwork::CGetFriends(const User & user) const
  {
    std::vector<size_t> user_indexes;
    bool found=0;
    for(size_t k=0; k<users.size(); ++k)
    {
        if(users[k]==user)
        {
            user_indexes=friends[k];
            found=true;
        }
    }
    if(found){
        std::vector<User>  res;
        for(auto j: user_indexes)
        {
            res.push_back(users[j]);
        }   
    }else
    {
        std::cerr<<"User not found"<<std::endl;
    }
  }


  const std::vector<User> SocialNetwork::CGetFriends(const std::string & name, 
                                            const std::string  & surname) const
  {
      std::vector<User> ret{};

        /* YOUR CODE GOES HERE */

      return ret;

  }

  void SocialNetwork::AddFriendship(const std::string & first_name, 
                                    const std::string & first_surname, 
                                    const std::string & second_name, 
                                    const std::string & second_surname)
  {

       /* YOUR CODE GOES HERE */

  }

}
