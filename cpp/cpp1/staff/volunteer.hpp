// Volunteer class
#ifndef VOLUNTEER_HPP
#define VOLUNTEER_HPP
#include"employee.hpp"

class Volunteer : public StaffMember{
  public :
    Volunteer(std::string n, std::string a, std::string p) : 
       StaffMember(n, a, p)
    {
    }
  int pay () { return 0; }
};
#endif
