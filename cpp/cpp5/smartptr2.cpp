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

MyClass * myClassMakerPtr(int n) {
    return new MyClass(n);
}

unique_ptr<MyClass> myClassMakerSmart(int n) {
    return make_unique<MyClass>(n);
}

int main() {
    auto mPtrRaw = myClassMakerPtr(5);
    auto mPtrSmart = myClassMakerSmart(10);

    mPtrRaw->print();
    mPtrSmart->print();

    delete(mPtrRaw);

    return 0;
}
