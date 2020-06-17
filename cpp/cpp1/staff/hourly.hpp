// Staff member - base class
#ifndef HOURLY_HPP
#define HOURLY_HPP
#include"employee.hpp"

class Hourly : public Employee {
  private:
    int hours;
  public:
    Hourly(std::string n, std::string a, std::string p, 
              std::string s, int r, int h) :
       Employee(n, a, p, s, r)
    {
       hours = h;
    }

  int pay();
};
#endif
