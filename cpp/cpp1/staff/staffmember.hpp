// Staff member - base class
#ifndef STAFFMEMBER_HPP
#define STAFFMEMBER_HPP
#include<string>
class StaffMember {
    private:
        std::string name;
        std::string address;
        std::string phone;

    public:
        // Constructor
        StaffMember(const std::string n, const std::string a, const std::string p) 
                    : name(n), address(a), phone(p)
                    { }
        void print() const;
        virtual int pay() const = 0;  // Abstract method
        int bonus(int b) const;       // Non-virtual method
};
#endif
