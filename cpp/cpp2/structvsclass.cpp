#include<iostream>
#include<string>
#include<string.h>
#include<stdio.h>

using namespace std;

// C-style structure
struct myStruct {
  int a;
  char c[8];

  void tryThis() { cout << "Hi" << endl;}
};

// C++ class
class myClass {
  public:
    int a;
    string c;

    myClass(int x, string y) {
       a = x;
       c = y;
    }
};

int main() {
  struct myStruct str = {7, "Hello"};
  myClass cls(15, "World");
  char * c = (char *) &str;
  char * k = (char *) &cls;

  cout << "myStruct size=" << sizeof(myStruct) << "  a=" << str.a <<
              "  c=" << str.c << endl;
  cout << " myClass size=" << sizeof(myClass) << "  a=" << cls.a <<
              "  c=" << cls.c << endl;

  unsigned int ii;
  cout <<"myStruct: " << endl;
  for(ii=0;ii<sizeof(myStruct);ii++) {
     printf("%3d: %5c %5x %5d\n", ii, *(c+ii), *(c+ii), *(c+ii));
  }
  cout << endl << "myClass: " << endl;
  for(ii=0;ii<sizeof(myClass);ii++) {
     printf("%3d: %5c %5x %5d\n", ii, *(k+ii), *(k+ii), *(k+ii));
  }

  return 0;
}
