// Adapted from an example from Java Foundations 
//  by John Lewis, Peter DePasquale, & Joe Chase

#include<iostream>
#include<vector>
#include"staffmember.hpp"
#include"salaried.hpp"
#include"hourly.hpp"
#include"volunteer.hpp"

using namespace std;

void print_paystub(const StaffMember * s) {
    s->print();
    cout << "Current pay : " << s->pay() << endl;
}

int main() {
    int counter = 0;
    int totalPay = 0;

    vector<StaffMember *> staff;

    Salaried * bob = new Salaried("Bob Smith", "123 Main", "480-555-8756", 
                                 "111-22-3333", 50000);
    Volunteer * alice = new Volunteer("Alice Jenkins", "456 4th", "480-555-2351"); 
    Hourly * mitch = new Hourly("Mitch Jenkins", "456 4th", "480-555-2351",
                                 "222-33-2222", 15, 30);
    Salaried * john = new Salaried("John Franklin", "222 Bank", "480-555-2343", 
                                 "111-22-4444", 75000);

    staff.push_back(bob);
    staff.push_back(alice);
    staff.push_back(mitch);
    staff.push_back(john);

    for (const StaffMember *s : staff) {
        cout << endl << "Employee " << counter << ": " << endl;
        print_paystub(s);
        totalPay = totalPay + s->pay();
        cout << "Bonus: " << s->bonus(500) << endl;
        counter ++;
    }

    cout << endl << "Total payroll: " << totalPay << endl;

    cout << endl << "Special bonus for John = " << john->bonus(500);
    cout << endl << "Special bonus for Mitch = " << mitch->bonus(500);
    cout << endl << "Special bonus for Alice = " << alice->bonus(500) << endl;



    return 0;
}
