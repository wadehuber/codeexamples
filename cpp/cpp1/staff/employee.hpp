// Employee class
#ifndef EMPLOYEE_HPP
#define EMPLOYEE_HPP
#include"staffmember.hpp"

class Employee : public StaffMember{
  private:
    std::string ssn;
  protected:
    int payrate;
  public :
    Employee(std::string n, std::string a, std::string p, 
              std::string s, int r) :
       StaffMember(n, a, p)
    {
       ssn = s;
       payrate = r;
    }
  void print();
};
#endif
