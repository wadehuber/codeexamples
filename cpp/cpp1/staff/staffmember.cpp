#include<iostream>
#include"staffmember.hpp"

void StaffMember::print() const {
    std::cout << "   Name: " << name << std::endl;
    std::cout << "   Address: " << address << std::endl;
    std::cout << "   Phone: " << phone << std::endl;
}

int StaffMember::bonus(int b) const {
    return b;
}
