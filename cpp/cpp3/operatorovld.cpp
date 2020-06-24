#include<iostream>

using namespace std;

// ---------------- Start of MyClass ---------------- 
class MyClass {
    private:
        int a;
    public:
        MyClass(int x=0) {
            a = x;
        }
        void print() {
            cout << "  print : " << a << endl;
        }

        MyClass operator+(const MyClass& that);
        MyClass operator+(int x);

        // Friends can see private members
        friend ostream& operator<<(ostream& strm, const MyClass&m);
        friend MyClass operator+(int x, const MyClass& that);

};

MyClass MyClass::operator+(const MyClass& that) {
    MyClass ret(this->a + that.a);
    return ret;
}

MyClass MyClass::operator+(int x) {
    MyClass ret(this->a + x);
    return ret;
}

// ----------------- End of MyClass ----------------- 
ostream& operator<<(ostream& strm, const MyClass& m) {
    strm << "{" << m.a << "}";
    return strm;
}

MyClass operator+(int x, const MyClass& that) {
    MyClass ret(that.a + x);
    return ret;
}



int main() {
    MyClass c1(1);
    MyClass c2(2);
    MyClass result;
    int num = 10;

    cout << "Initial" << endl;
    c1.print();
    c2.print();
    result.print();

    cout << endl;
    cout << "result = c1 + c2" << endl;
    result = c1 + c2;    // result = c1.operator+(c2);
    result.print(); 

    cout << endl;
    cout << "c1.operator+(c2) = " << c1.operator+(c2) << endl;
    cout << "c1.operator+(num) = " << c1.operator+(num) << endl;

    cout << endl;
    //cout << "c1 + c2 = " << c1.a << " + " << c2.a << " = " << c1.a+c2.a << endl;
    cout << "c1 + c2 = " << c1 << " + " << c2 << " = " << c1+c2 << endl;
    cout << "c1 + num = " << c1 << " + " << num << " = " << c1+num << endl;
    cout << "num + c2 = " << num << " + " << c2 << " = " << num+c2 << endl;

    return 0;
}

