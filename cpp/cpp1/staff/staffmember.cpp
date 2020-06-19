#include<iostream>
#include"staffmember.hpp"

using namespace std;

void StaffMember::print() const {
  cout << "    Name: " << name << endl;
  cout << " Address: " << address << endl;
  cout << "   Phone: " << phone << endl;
}

