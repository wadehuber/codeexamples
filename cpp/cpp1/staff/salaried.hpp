#ifndef SALARIED_HPP
#define SALARIED_HPP
#include<string>
#include"employee.hpp"

class Salaried : public Employee {
    public:
        Salaried(std::string n, std::string a, std::string p, 
              std::string s, int r) :
           Employee(n, a, p, s, r) {}

        int pay() const;
};
#endif
