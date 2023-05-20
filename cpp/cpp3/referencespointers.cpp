#include<iostream>

using namespace std;

// Function with integer paramter
void variableFunction(int parm) {
    parm = parm * 3;
}

// Function with pointer parameter
void pointerFunction(int * parm) {
    *parm = *parm * 4;
}

// Function with reference parameter
void referenceFunction(int & parm) {
    parm = parm * 5;
}

int main() {
    int x = 10;               // integer varaible
    int &ref = x;             // reference variable
    int * ptr = new int(15);  // pointer variable


    cout << " Starting: x=" << x << ", ref="  << ref << 
                  "*ptr=" << *ptr << ", ptr=" << ptr << endl;

    // Call the 3 functions with variable x
    variableFunction(x);
    pointerFunction(&x);
    referenceFunction(x);
    cout << endl << " After calling with x: x=" << x << ", ref="  << ref << 
                  "*ptr=" << *ptr << ", ptr=" << ptr << endl;

    // Call the 3 functions with pointer ptr
    variableFunction(*ptr);
    pointerFunction(ptr);
    referenceFunction(*ptr);
    cout << endl << " After calling with ptr: x=" << x << ", ref="  << ref << 
                  "*ptr=" << *ptr << ", ptr=" << ptr << endl;

    // Call the 3 functions with reference ref
    variableFunction(ref);
    pointerFunction(&ref);
    referenceFunction(ref);
    cout << endl << " After calling with ptr: x=" << x << ", ref="  << ref << 
                  "*ptr=" << *ptr << ", ptr=" << ptr << endl;

    return 0;
}
  
