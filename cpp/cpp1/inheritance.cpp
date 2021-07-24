#include<iostream>
#include<string>

using namespace std;

class Parent {
  protected:
    string name;
  public:
    Parent(const string& n="Person X") : name(n) 
          { cout << "    PARENT: constructor for " << name << endl; }

    void method1() { cout << "    PARENT: method1" << endl; }
    void method2() { cout << "    PARENT: method2" << endl; }
};

class Child : public Parent {
  private:
    int age;
  public:
    Child(const string& n="Baby", const int& a=0) 
          : Parent(n), age(a)
          { cout << "    CHILD: constructor for " << name 
                 << " age " << age << endl; }
    void method1() { cout << "    CHILD: method1" << endl; }
    void method3() { cout << "    CHILD: method3" << endl; }
};

int main() {
  cout << "Instantiating Parent object:" << endl;
  Parent parentObject("Ward Cleaver");
  cout << endl << "Instantiating Child object:" << endl;
  Child childObject("Beaver Cleaver");

  cout << endl << "Calling Parent Object methods" << endl;
  parentObject.method1();
  parentObject.method2();

  cout << endl << "Calling Child Object methods" << endl;
  childObject.method1();
  childObject.method2();
  childObject.method3();

  return 0;
}

