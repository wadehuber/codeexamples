#include<iostream>

using namespace std;

// ---------------- Start of MyClass ---------------- 
class MyClass {
  private:
    int a;
  public:
    MyClass(int x=0) {
      a = x;
    }
    void print() {
      cout << "  Printing: " << a << endl;
    }

   MyClass operator+(const MyClass& that);
   MyClass operator+(int x);

   // Friends can see private members
   friend ostream& operator<<(ostream& strm, const MyClass& m);
   friend MyClass operator+(int x, MyClass that);
};

MyClass MyClass::operator+(const MyClass& that) {
  MyClass ret(this->a + that.a);
  return ret;
}

MyClass MyClass::operator+(int x) {
  MyClass ret(this->a + x);
  return ret;
}

// ----------------- End of MyClass ----------------- 
ostream& operator<<(ostream& strm, const MyClass& m) {
  strm << "{" << m.a << "}";
  return strm;
}

MyClass operator+(int x, MyClass that) {
  MyClass ret(x + that.a);
  return ret;
}

int main() {
  MyClass c1(1);
  MyClass c2(2);
  MyClass result;

  cout << "Initial" << endl;
  c1.print();
  c2.print();
  result.print();


  cout << endl << "result = c1 + c2" << endl;
  result = c1 + c2;   // result = c1.operator+(c2);
  result.print();

  //cout << "c1 + c2 = " << c1.a << " + " << c2.a << " = " << c1.a+c2.a << endl;
  cout << "c1 + c2 = " << c1 << " + " << c2 << " = " << c1+c2 << endl;
  cout << "c1 + 10 = " << c1 << " + " << 10 << " = " << c1+10 << endl;
  cout << "20 + c2 = " << 20 << " + " << c2 << " = " << 20+c2 << endl;

  return 0;
}

