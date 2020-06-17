#include<iostream>

using namespace std;


template<class T>
class TwoThings {
  private:
    T thing1;
    T thing2;
  
  public:
    TwoThings(const T &t1, const T &t2) : thing1{t1}, thing2{t2} {}
    T getOne() const { return thing1; };
    T getTwo() const { return thing2; };

    void setOne(const T &t1) { thing1 = t1; };
    void setTwo(const T &t2) { thing2 = t2; };
};

int main() {
  TwoThings<int> nums(1,5);
  TwoThings<string> strings("CSC", "240");

  nums.setOne(20);
  strings.setTwo("220");

  cout << "nums:" << endl;
  cout << "  " << nums.getOne() << endl;
  cout << "  " << nums.getTwo() << endl;

  cout << "strings:" << endl;
  cout << "  " << strings.getOne() << endl;
  cout << "  " << strings.getTwo() << endl;

  return 0;
}
