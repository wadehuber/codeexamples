#include<iostream>

using namespace std;

class MyClass {
  public:
    int * a;
  private:
    int b;
    string name;

  public:
    // Constructor
    MyClass(int x, string n="") {
      static int counter = 1;
      a = new int;
      *a = x;
      b = counter;
      counter ++;
      name = n;
      cout << "  Constructor " << name << " " << b << " : " 
             << a << " (" << *a << ")" << endl;
    }

    // Copy constructor
    MyClass(const MyClass& original) {
      a = new int;
      *a = *(original.a);
      b = original.b * 10;
      name = original.name + "_copy";
      cout << "  Copy ctor " << name << " " << b << " : " 
             << a << " (" << *a << ")" << endl;
    }

    // Destructor
    ~MyClass() {
      cout << "  Destructor " << name << " " << b << " : " 
             << a << " (" << *a << ")" << endl;
      delete a;
      a = nullptr;
    }

    void print();
};

void MyClass::print() {
  cout << "       object " << name << " " << b << " : "
         << a << " (" << *a << ")" << endl;
}

void func(MyClass cparam) {
  cout << " FUNC: ++++++++++++ start func ++++++++++++" << endl;

  cout << " FUNC: begin declare c3" << endl;
  MyClass c3(3, "c3");
  cout << " FUNC: end declare c3" << endl;

  cout << " FUNC: print cparam" << endl;
  cparam.print();
  cout << " FUNC: print c3" << endl;
  c3.print();

  cout << " FUNC: ++++++++++++ end func ++++++++++++" << endl;
}

int main() {
  cout << "MAIN: start" << endl;  
  cout << "MAIN: begin declare c1 (object)" << endl;
  MyClass c1(1, "c1");    // MyClass object allocated on the stack
  cout << "MAIN: end declare c1 (object)" << endl;

  cout << "MAIN: begin declare c2 (pointer)" << endl;
  MyClass * c2;            // MyClass pointer allocated on the stack
  cout << "MAIN: end declare c2 (pointer)" << endl;

  cout << "MAIN: begin instantiate MyClass object using new " << endl;
  c2 = new MyClass(2, "c2");  // MyClass object allocated on the heap
  cout << "MAIN: end instantiate MyClass object using new " << endl;

  cout << "MAIN: print c1 (&c1 = " << &c1 << ")" << endl;
  c1.print();
  cout << "MAIN: print c2 (&c2 = " << &c2 << ", c2 = " << c2 << ")" << endl;
  c2->print();

  cout << "MAIN: begin call to func(c1)" << endl;
  func(c1);
  cout << "MAIN: end call to func(c1)" << endl;

  cout << "MAIN: print c1 (&c1 = " << &c1 << ")" << endl;
  c1.print();

  cout << "MAIN: begin delete c2" << endl;
  delete c2;
  cout << "MAIN: end delete c2" << endl;


  cout << "MAIN: complete" << endl;
  return 0;
}
