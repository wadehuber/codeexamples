// Example C++ Class
#include<iostream>
#include<string>

using namespace std;

class MyClass {
    private:
        string name;
        int num;
    public:
        // Constructor with default values
        MyClass(const string& n="", int x=10) {
            name = n;
            num = x;
        }

        // Method declarations
        void print();
        void change(const string& n, int x);
};

// Display the name & num
void MyClass::print() {
    cout << "Name = " << name << "  ";
    cout << "Num = " << num << endl;
}

// Mutator
void MyClass::change(const string& n, int x) {
    name = n;
    num = x;
}

// Non class member function
int timesTwo(int x) {
    return 2 * x;
}

int main() {
    MyClass c1("Bob Smith", 1);
    MyClass c2("Alice Jones", 2);

    c1.print();
    c2.print();
    cout << endl;

    cout << "timeTwo(5)=" << timesTwo(5) << endl << endl;

    c2.change("Alice Smith", timesTwo(4));
    c2.print();

    return 0;
}
