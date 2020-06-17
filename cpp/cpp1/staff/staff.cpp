// Adapted from an example from Java Foundations 
//  by John Lewis, Peter DePasquale, & Joe Chase
//
#include<iostream>
#include"staffmember.hpp"
#include"salaried.hpp"
#include"volunteer.hpp"
#include"hourly.hpp"

using namespace std;

#define STAFF_SIZE  4

void print_paystub(StaffMember * s) {
  s->print();
  cout << "Current pay : " << s->pay() << endl;
}

int main() {
  int ii;
  int totalpay = 0;
  StaffMember * staff[STAFF_SIZE];
  staff[0] = new Salaried("Bob Smith", "123 Main", "480-555-8765", 
                           "111-22-3333", 50000);
  staff[1] = new Volunteer("Alice Jenkins", "456 4th", "480-555-2341");
  staff[2] = new Hourly("Mitch Jenkins", "456 4th", "480-555-2341", 
                          "222-33-2222", 10, 40);
  staff[3] = new Salaried("John Franklin", "222 Bank", "480-555-2343", 
                           "111-22-4444", 78000);

  for(ii=0;ii<STAFF_SIZE;ii++)  {
    cout <<"\nEmployee " << ii << ": " << endl;
    print_paystub(staff[ii]);
    totalpay=totalpay + staff[ii]->pay();
  }

  cout << "\nTotal payroll: " << totalpay << endl; 
  cout << "Done!" << endl;  

  return 0;
}
