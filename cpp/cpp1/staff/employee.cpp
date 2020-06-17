#include<iostream>
#include"employee.hpp"

using namespace std;

void Employee::print() {
  StaffMember::print();
  cout << "      SSN: " << ssn << endl;
  cout << " Pay rate: " << payrate << endl;
}
