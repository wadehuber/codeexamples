#include<iostream>

using namespace std;

class Destruct {
    public:
        int a;

        Destruct(int x=0) : a(x) {
            cout << "Constructor " << a << endl; 
        }

        ~Destruct() {
            cout << "Destructor " << a << endl;
        }

};

void destFunction(Destruct d3) {
    Destruct d4(4);
    cout << "In dest function" << endl;
}

int main() {
    cout << "Start of main" << endl;
    Destruct d1(1);
    Destruct d2(2);
    Destruct * d5 = new Destruct(5);
    
    cout << "Done declaring variables" << endl;

    cout << endl << "Calling destFunction(d1)" << endl;
    destFunction(d1);

    cout << endl << "Calling delete(d5)" << endl;
    delete(d5);

    cout << endl << "End of main" << endl;
    return 0;
}