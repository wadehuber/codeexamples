#ifndef VOLUNTEER_HPP
#define VOLUNTEER_HPP
#include"staffmember.hpp"
#include<string>

class Volunteer : public StaffMember {
    public:
        Volunteer(std::string n, std::string a, std::string p) :
             StaffMember(n, a, p) {}
        int pay() const { return 0; }
        int bonus(int b) const { return b / 10; };
};

#endif
