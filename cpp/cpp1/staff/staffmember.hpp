// Staff member - base class
#ifndef STAFFMEMBER_HPP
#define STAFFMEMBER_HPP

class StaffMember {
  private:
    std::string name;
    std::string address;
    std::string phone;
  
  public: 
    // Constructor
    StaffMember(std::string n, std::string a, std::string p) {
      name = n;
      address = a;
      phone = p;
    }
    void print();
    virtual int pay() = 0;  // Abstract method
};
#endif
