#include<iostream>
#include"staffmember.hpp"

using namespace std;

void StaffMember::print() {
  cout << "    Name: " << name << endl;
  cout << " Address: " << address << endl;
  cout << "   Phone: " << phone << endl;
}

