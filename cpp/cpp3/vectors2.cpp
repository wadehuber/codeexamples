#include<iostream>
#include<vector>

using namespace std;

class MyClass {
    private:
        int num;
    public:
        explicit MyClass(int x=0) : num(x) {}
        MyClass(const MyClass & original) { 
            cout << "   Copy constructor" << original.num << endl;
            num = original.num;
        }
        void print() const { cout << "num = " << num << endl; }
        void change(int x) { num = x; }
};

void printMyClassVector(const vector<MyClass>& v) {
    cout << "Printing from printMyClassVector:" << endl;
    for (MyClass const &ii : v) {
        cout << "  ";
        ii.print();
    }
    cout << endl;
}

int main() {
    vector<MyClass> vec1;    // Vector of objects
    vector<MyClass*> vec2;   // Vector of pointers
    MyClass var;

    // Add elements to the vector
    for (int ii=1;ii<=5;ii++) {
        cout << "Adding MyClass " << ii << ": " << endl;;
        var.change(ii);
        vec1.push_back(var);
        // vec2.push_back(&var);  // This adds same pointer to the vector
        vec2.push_back(new MyClass(ii*10));
        cout << endl;
    }

    cout << endl << endl << "vec1: " << endl;
    for (MyClass const &ii : vec1) {
        ii.print();
    }
    cout << endl;

    cout << "vec2: " << endl;
    for (MyClass * const&ii : vec2) {
        ii->print();
    }

    cout << endl;
    printMyClassVector(vec1);
    // printMyClassVector(vec2);  // ERROR: vec2 holds a different type than vec1

}
