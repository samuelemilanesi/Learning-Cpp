#ifndef DRIVER_HH
#define DRIVER_HH

#include <string>

class Driver {

  std::string name;
  std::string surname;
  std::size_t id;

public:
  Driver (const std::string & n, const std::string & s, std::size_t i):
    name (n), surname (s), id (i) {}
  Driver (const Driver & d):
    name (d.name), surname (d.surname), id (d.id) {}

};

#endif /* DRIVER_HH */
