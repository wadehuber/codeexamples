#include <iostream>

using namespace std;

class MyMemoryClass {
  private:
    int *a;
    int *b;
    string name;

  public:
        // Constructor
        MyMemoryClass(int size=5, const string & s="") : name(s){
            cout << "CONSTRUCTOR " << name << endl;
            a = new int;
            *a = size;
            b = new int[size];
            for (int ii=0;ii<*a;ii++) {
                b[ii] = ii+1;
            }
        }

        // Copy Constructor
        MyMemoryClass(const MyMemoryClass & original) {
            name = original.name + "_copy";
            cout << "COPY CONSTRUCTOR " << name << endl;
            a = new int;
            *a = *original.a;
            b = new int[*a];
            for (int ii=0;ii<*a;ii++) {
              b[ii] = original.b[ii];
            }
        }

        // Destructor
        ~MyMemoryClass() {
            cout << "DESTRUCTOR " << name << endl;
            delete a;
            a = nullptr;
            delete[] b;  // Use delete[] when you use new with []
            b = nullptr;
            
        }

        // Overloaded assignment operator
        MyMemoryClass& operator=(const MyMemoryClass& otherObject) {
            cout << "ASSIGNMENT OPERATOR " << name << endl;
            if (this !=  &otherObject) {
                
                // Allocate new memory for a & b
                int * newA = nullptr;
                int * newB = nullptr;
                try {
                    newA = new int;
                }
                catch (...) {
                    if (newA != nullptr) {
                        delete newA;
                    }
                }
                try {
                    newB = new int[*(otherObject.a)];
                }
                catch (...) {
                    if (newA != nullptr) {
                        delete newA;
                    }
                    if (newB != nullptr) {
                        delete newB;
                    }
                    throw;
                }

                // Have new memory for a & b, now do the assignments
                name = otherObject.name + "_assigned";
                *newA =  *(otherObject.a);
                for (int ii=0;ii<*newA;ii++) {
                  newB[ii] = otherObject.b[ii];
                }

                delete a;
                a = newA;
                delete[]b;
                b = newB;
            }
            return *this;
        }

        void print() {
            cout << "  MyMemoryClass " << name << " {" << a << "} {" << b << "} " 
                 << *a << ": " ;
            for(int ii=0;ii<*a;ii++) {
                cout << b[ii] << " ";
            }
            cout << endl;
        }
};

void func(MyMemoryClass x) {
    cout << "FUNC: ";
    x.print();
}

int main() {
    MyMemoryClass c1(10, "c1");      // value semantics
    MyMemoryClass * c2;
    c2 = new MyMemoryClass(5, "c2"); // reference semantics

    MyMemoryClass c3(14, "c3");
    //MyMemoryClass c3 = c1;
  
    cout << "C1: " << endl;
    c1.print();
    cout << "C2: " << endl;
    c2->print();
    cout << "C3: " << endl;
    c3.print();
  
    cout << endl;
    cout << "C3 = C1: " << endl; 
    c3 = c1;
    c1.print();
    c3.print();

    cout << endl << "Calling functions: " << endl; 
    func(c1);
    func(c3);

    cout << endl;
    delete(c2);
    cout << endl << "End of program" << endl;
    return 0; 
}
