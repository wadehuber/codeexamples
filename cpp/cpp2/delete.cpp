#include <iostream>

using namespace std;

class MyDeleteClass {
  private:
    int *a;
    int *b;

  public:
  // Constructor
  MyDeleteClass(int size=5) {
    a = new int;
    *a = size;
    b = new int[size];
    for (int ii=0;ii<*a;ii++) {
      b[ii] = ii+1;
    }
  }

  // How would you write a copy constructor for MyDeleteClass?

  // Destructor
  ~MyDeleteClass() {
    delete a;
    delete[] b;     // b points to an array, use delete[]
    a = nullptr; 
    b = nullptr; 
  }

  void print() {
    cout << "  MyDeleteClass " << *a << ": " ;
    for(int ii=0;ii<*a;ii++) {
      cout << b[ii] << " "; 
    }
    cout << endl;
  }
};


int main() {
  MyDeleteClass c1(10);      // value semantics
  MyDeleteClass * c2;
  c2 = new MyDeleteClass(5); // reference semantics

  cout << "C1: " << endl;
  c1.print();
  cout << "C2: " << endl;
  c2->print();
 
  return 0; 
}
