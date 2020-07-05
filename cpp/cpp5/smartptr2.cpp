#include<iostream>
#include<memory>

using namespace std;

class MyClass {
    private:
        int x;
    public:
        explicit MyClass(int n=1) : x(n) { cout << "Constructor x=" << n << endl; }
        ~MyClass() { cout << "Destructor x=" << x << endl; }
        void print() { cout << "MyClassObject x=" << x << endl; }
};

MyClass * myClassMakerBad(int n) {
    return new MyClass(n); 
}

unique_ptr<MyClass> myClassMaker(int n) {
    return make_unique<MyClass>(n);
}

int main() {

    auto mPtr1 = myClassMakerBad(5);
    mPtr1->print();

    auto mPtr2 = myClassMaker(10);
    mPtr2->print();

    delete(mPtr1);

    return 0;
}