#include<iostream>
#include<string>

using namespace std;

class Super {
  public:
    Super() { cout << "SUPER: constructor" << endl; }

    // Non-virtual methods can be overridden by the child class
    // The type of the pointer determines the method that gets called
    void nonVirtual1() { cout << "SUPER: nonVirtual1" << endl; }
    void nonVirtual2() { cout << "SUPER: nonVirtual2" << endl; }

    // Virtual methods can be overridden by the child class
    // The type of the object determines the method that gets called 
    virtual void Virtual1() { cout << "SUPER: Virtual1" << endl; }
    virtual void Virtual2() { cout << "SUPER: Virtual2" << endl; }

    // Pure virtual methods must be overridden by any non-abstract
    //   derrived class
    virtual void pureVirtual() = 0;
};

class Sub : public Super {
  public:
    Sub() { cout << "SUB: constructor" << endl; }
    // void nonVirtual2() override { cout << "SUPER: nonVirtual2" << endl; }
    void nonVirtual2() { cout << "SUB: nonVirtual2" << endl; }
    virtual void Virtual2() override { cout << "SUB: Virtual2" << endl; }
    void pureVirtual() override { cout << "SUB: pureVirtual" << endl; }

};

int main() {
  /*
  Super superObject;
  */
  Sub subObject;

  Super * superPtr = &subObject;
  Sub * subPtr = &subObject;

  /*
  cout << endl << "Calling Super Object methods" << endl;
  superObject.nonVirtual1();
  superObject.nonVirtual2();
  superObject.Virtual1();
  superObject.Virtual2();
  */

  cout << endl << "Calling Sub Object methods with Sub variable" << endl;
  subObject.nonVirtual1();
  subObject.nonVirtual2();
  subObject.Virtual1();
  subObject.Virtual2();
  subObject.pureVirtual();

  cout << endl << "Calling Sub Object methods with Super pointer" << endl;
  superPtr->nonVirtual1();
  superPtr->nonVirtual2();
  superPtr->Virtual1();
  superPtr->Virtual2();
  superPtr->pureVirtual();

  cout << endl << "Calling Sub Object methods with Sub pointer" << endl;
  subPtr->nonVirtual1();
  subPtr->nonVirtual2();
  subPtr->Virtual1();
  subPtr->Virtual2();
  subPtr->pureVirtual();

  return 0;
}

