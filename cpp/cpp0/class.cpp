// Example C++ Class 
#include<iostream>

using namespace std;

class MyClass {
  private:
    string name;
    int num;
  public:
    // Constructor with default values
    MyClass(const &string n="", int x=0) {
      name = n;
      num = x;
    }

    // Method declarations
    void print();
    void change(string, int);
};

// Display name & num
void MyClass::print() {
  cout << "Name =  " << name << endl;
  cout << "Num =  " << num << endl;
}

// Mutator
void MyClass::change(const &string n, int x) {
  name = n;
  num = x;
}

// Non class member function
int timestwo(int x) {
    return 2 * x;
}

int main() {
  MyClass c1("Bob Smith", 1);
  cout << endl;
  MyClass c2("Alice Jones", 2);
  cout << endl;

  c1.print();
  c2.print();
  cout << endl;

  cout << "timestwo(5) = " << timestwo(5) << endl << endl;

  c2.change("Alice Smith", timestwo(4));
  c2.print();

  return 0;
}
