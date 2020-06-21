#include<iostream>
#include<string>
#include<string.h>
#include<stdio.h>

using namespace std;

// C-style structure
struct myStruct {
    int a;
    char c[16];

    myStruct(int x, const string & y)  : a(x) {
        cout << "myStruct constructor" << endl;
        strncpy(c, y.c_str(), y.length() + 1);
    }
    void dump(unsigned int x=16) {
        cout << endl << "myStruct: a=" << a << " c=" << c << endl;
        char * ptr = (char *) this;
        for(unsigned int ii=0;ii<x;ii++) {
            printf("%3u:  %5c %5x  %5d\n", ii, *(ptr+ii), *(ptr+ii), *(ptr+ii));
        }
    }
};

// C++ class
class myClass {
    int a;
    string c;

    public:
        myClass(int x, const string & y)  : a(x), c(y) {
              cout << "myClass constructor" << endl;
        }

        void dump(unsigned int x=16) {
            cout << endl << "myClass: a=" << a << " c=" << c << endl;
            char * ptr = (char *) this;
            for(unsigned int ii=0;ii<x;ii++) {
                printf("%3u:  %5c %5x  %5d\n", ii, *(ptr+ii), *(ptr+ii), *(ptr+ii));
            }
        }
};

int main() {


    cout << "Declaring variabls:" << endl;
    struct myStruct str = {7, "Hello"};
    myClass cls(15, "World");
    cout << endl;

    cout << "Sizes: " << endl;
    cout << "myStruct size=" << sizeof(myStruct) << endl;
    cout << " myClass size=" << sizeof(myClass) << endl;
    cout << endl;

    cout << "Accessing members:" << endl;
    cout << "  myStruct.a = %d" << str.a << endl;     // struct members are public by default
    //cout << "   myClass.a = %d" << cls.a << endl;   // class members are private by default
    cout << endl;

    cout << "Calling dump():" << endl;
    str.dump(sizeof(str));
    cls.dump(sizeof(cls));

    return 0;
}
