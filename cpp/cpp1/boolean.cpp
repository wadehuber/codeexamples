#include<iostream>

using namespace std;

bool bigger (int a, int b) {
    return (a > b);
}
int main() {

    bool check = true;
    bool finished { false };   
    bool myBool;

    myBool = true;

    cout << "check=" << check << "  finished=" << finished 
         << "  myBool=" << myBool << endl;

    int a = 4, b = 10;
    cout << endl;
    if (bigger(a, b)) {
        cout << "a is bigger than b" << endl;
    }
    else {
        cout << "a is not bigger than b" << endl;
    }
    
    if (bigger(b, a)) {
        cout << "b is bigger than a" << endl;
    }
    else {
        cout << "b is not bigger than a" << endl;
    }

    cout << endl;

    // Loop until we reach a multiple 7 larger than 10;
    int ii=0;
    bool multOf7 = false;
    bool bigger10 = false;
    while (!(multOf7 and bigger10)) {
        cout << ii << " ";
        ii++;
        if ((ii % 7) == 0) {
            multOf7 = true;
        }
        else {
            multOf7 = false;
        }

        bigger10 = ii > 10;
    }

    cout << endl;
    // Loop until we reach a multiple 5 larger than 16
    int jj=0;
    while (!finished) {
        cout << jj << " ";
        jj++;
        finished = ((jj % 5) == 0) ? (jj > 16) : false;
    }

    cout << endl;
    
    return 0;
}
