#include<iostream>

using namespace std;

class MyClass {
    private:
        string str;
    public:
        MyClass() : str("Hello, world!") {}

        void print() {
            cout << " --- " << str << " --- " << endl;
        }
};

int main() {
    MyClass greeting();
    greeting.print();
}
