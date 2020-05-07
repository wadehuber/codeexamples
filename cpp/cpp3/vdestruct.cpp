#include<iostream>

using namespace std;

class MyBase {
  public:
    MyBase() { cout << "MYBASE Constructor" << endl; }
    virtual ~MyBase() { cout << "MYBASE Destructor" << endl; }
};

class MyDerrived : public MyBase {
  private:
    int * a;
  public:
    MyDerrived(int x=0) {
      a = new int;
      *a = x;
      cout << "MYDERRIVED Constructor: " << *a << endl;
    }

    ~MyDerrived() {
      cout << "MYDERRIVED Destructor: " << *a << endl;
      delete a;
      a=nullptr;
    }
};

int main () {
  MyDerrived c1(1);

  MyBase * c2 = new MyDerrived(2);

  delete(c2);
  
  return 0;
}
