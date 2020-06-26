#include<iostream>

using namespace std;

template<class T, class T2>
class TwoThings {
    private:
        T thing1;
        T2 thing2;

    public:
        TwoThings(const T &t1, const T2 &t2) : thing1{t1}, thing2{t2} {};

        T getOne() const { return thing1; };
        T2 getTwo() const { return thing2; };

        void setOne(const T &t1) { thing1 = t1; };
        void setTwo(const T2 &t1) { thing2 = t1; };

        void print() const {
            cout << "thing1= " << thing1 << "  thing2=" << thing2 << endl;
        }
};

int main() {
    TwoThings<int, int> nums(1, 5);
    TwoThings<string, string> strings("CSC", "220");
    TwoThings<int, string> atyourpost(421, "TK");

    cout << "Two TwoThings:" << endl;
    nums.print();
    strings.print();

    cout << endl;
    cout << "accessors:" << endl;
    cout << "  nums.thing1 = " << nums.getOne() << endl;
    cout << "  strings.thing2 = " << strings.getTwo() << endl;

    cout << endl;
    cout << "mutators:" << endl;
    nums.setOne(-11);
    strings.setTwo("240");
    nums.print();
    strings.print();

    cout << endl;
    cout << "atyourpost:" << endl;
    atyourpost.print();
    cout << "  accessors:" << endl;
    cout << "    thing1 = " << atyourpost.getOne() << endl;
    cout << "    thing2 = " << atyourpost.getTwo() << endl;

    return 0;
}
