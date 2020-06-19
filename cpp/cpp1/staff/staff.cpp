// Adapted from an example from Java Foundations 
//  by John Lewis, Peter DePasquale, & Joe Chase
//
#include<iostream>
#include<vector>
#include"staffmember.hpp"
#include"salaried.hpp"
#include"volunteer.hpp"
#include"hourly.hpp"

using namespace std;


void print_paystub(const StaffMember * s) {
  s->print();
  cout << "Current pay : " << s->pay() << endl;
}

int main() {
  int counter = 0;
  int totalpay = 0;
  vector<StaffMember*> staff;
  staff.push_back(new Salaried("Bob Smith", "123 Main", "480-555-8765", 
                           "111-22-3333", 50000));
  staff.push_back(new Volunteer("Alice Jenkins", "456 4th", "480-555-2341"));
  staff.push_back(new Hourly("Mitch Jenkins", "456 4th", "480-555-2341", 
                          "222-33-2222", 10, 40));
  staff.push_back(new Salaried("John Franklin", "222 Bank", "480-555-2343", 
                           "111-22-4444", 78000));

  
  for(StaffMember const *s : staff) {
    cout <<"\nEmployee " << counter << ": " << endl;
    print_paystub(s);
    totalpay=totalpay + s->pay();
    counter ++;
  }

  cout << "\nTotal payroll: " << totalpay << endl; 
  cout << "Done!" << endl;  

  return 0;
}
