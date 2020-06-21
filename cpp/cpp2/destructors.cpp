#include<iostream>

using namespace std;

class MyClass {
    public:
        int * a;
    private:
        int * b;
        int c;
        string name;

    public:
        // Constructor
        MyClass(int x=0, const string n="") : name(n) {
            static int counter = 1;     // Allocated in static memory
            a = new int;                // Allocated on the heap
            *a = x;
            b = new int[*a];             // Allocated on the heap
            for (int ii=0;ii<*a;ii++) {
                b[ii] = ii * *a;
            }
            c = counter;
            cout << "  Constructor " << name << " " << *a << " {" << a << "} : "
                 << "b=" << b << " c=" << c << endl;
            counter++;
        }

        // Copy Constructor
        MyClass(const MyClass & original) {
            a = new int;                // Allocated on the heap
            *a = *(original.a);
            b = new int[*a];             // Allocated on the heap
            for (int ii=0;ii<*a;ii++) {
                b[ii] = original.b[ii];
            }
            c = original.c + 6000;
            cout << "  Copy ctor " << name << " " << *a << " {" << a << "} : "
                 << "b=" << b << " c=" << c << endl;
        }

        // Destructor
        ~MyClass() {
            cout << "  Destructor " << name << " " << *a << " {" << a << "} : "
                 << "b=" << b << " c=" << c << endl;
            delete a;
            a = nullptr;
            delete[] b;     // b points to an array, so use delete[]
            b = nullptr;
        }

        void print() const;
};

void MyClass::print() const {
    cout << "  Print: " << name << " " << *a << " {" << a << "} : "
         << "b=" << b << " c=" << c << endl;

}

void func(MyClass funParam) {
    cout << " FUNC: ++++++++++++ start func ++++++++++++" << endl;

    cout << " FUNC: begin declare func1" << endl;
    MyClass func1(3, "func1");
    cout << " FUNC: end declare func1" << endl;

    cout << " FUNC: begin print func1" << endl;
    func1.print();
    cout << " FUNC: end print func1" << endl;

    cout << " FUNC: begin print funParam" << endl;
    funParam.print();
    cout << " FUNC: end print funParam" << endl;

    cout << " FUNC: ++++++++++++ end func ++++++++++++" << endl;
}

int main() {
    cout << "MAIN: begin" << endl;
    cout << "MAIN: begin declare main1 (object)" << endl;
    MyClass main1(1, "main1");
    cout << "MAIN: end declare main1 (object)" << endl;

    cout << "MAIN: begin declare main2ptr (pointer)" << endl;
    MyClass * main2ptr;
    cout << "MAIN: end declare main2ptr (pointer)" << endl;

    cout << "MAIN: begin declare main2ptr (pointer)" << endl;
    main2ptr = new MyClass(2, "main2ptr");
    cout << "MAIN: end declare main2ptr (pointer)" << endl;

    cout << "MAIN: print main1 (&main1 = " << &main1 << ")" << endl;
    main1.print();
    cout << "MAIN: print main2ptr (&main2ptr = " << &main2ptr << ", main2ptr = " << main2ptr << ")" << endl;
    main2ptr->print();

    cout << "MAIN: begin call to func(main1)" << endl;
    func(main1);
    cout << "MAIN: end call to func(main1)" << endl;

    cout << "MAIN: print main1 (&main1 = " << &main1 << ")" << endl;
    main1.print();

    cout << "MAIN: begin delete main2ptr" << endl;
    delete main2ptr;
    cout << "MAIN: end delete main2ptr" << endl;

    cout << "MAIN: complete" << endl;

    return 0;
}
