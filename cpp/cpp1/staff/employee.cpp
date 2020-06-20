#include<iostream>
#include"employee.hpp"

using namespace std;

void Employee::print() const {
    StaffMember::print();
    cout << "      SSN: " << ssn << endl;
    cout << " Pay Rate: " << payrate << endl;
}

