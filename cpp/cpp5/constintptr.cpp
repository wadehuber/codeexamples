#include<iostream>

using namespace std;

int main() {
    int num = 0;     //  ptr1, ptr2, ptr3 will be initialized with &num
    int num1 = 10;
    int num2 = 42;
    int num3 = 33;

    const int * ptr1 = &num;     // pointer to constant int
    int const * ptr2 = &num;     // pointer to constant int
    int * const ptr3 = &num;     // constant int pointer

    cout << "Initial values:" << endl;
    cout << "num1=" << num1 << "  ptr1=" << ptr1 << " *ptr1=" << *ptr1 << endl;;
    cout << "num2=" << num2 << "  ptr2=" << ptr2 << " *ptr2=" << *ptr2 << endl;;
    cout << "num3=" << num3 << "  ptr3=" << ptr3 << " *ptr3=" << *ptr3 << endl;;

    ptr1 = &num1;
    ptr2 = &num2;
    // ptr3 = &num3;    // ERROR: Can't assign to constant pointer

    cout << endl << "After assigning address:" << endl;
    cout << "num1=" << num1 << "  ptr1=" << ptr1 << " *ptr1=" << *ptr1 << endl;;
    cout << "num2=" << num2 << "  ptr2=" << ptr2 << " *ptr2=" << *ptr2 << endl;;
    cout << "num3=" << num3 << "  ptr3=" << ptr3 << " *ptr3=" << *ptr3 << endl;;

    // *ptr1 = 1111;       // ERROR: Can't modify value pointed to by ptr1
    // *ptr2 = 2222;       // ERROR: Can't modify value pointed to by ptr2
    *ptr3 = 3333; 

    cout << endl << "After assigning value to dereference:" << endl;
    cout << "num1=" << num1 << "  ptr1=" << ptr1 << " *ptr1=" << *ptr1 << endl;;
    cout << "num2=" << num2 << "  ptr2=" << ptr2 << " *ptr2=" << *ptr2 << endl;;
    cout << "num3=" << num3 << "  ptr3=" << ptr3 << " *ptr3=" << *ptr3 << endl;;

    return 0;
}