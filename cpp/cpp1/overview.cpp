#include<iostream>
#include<vector>

using namespace std;

int main() {
    // Initialization C++
    double a = 1.2;
    double b {2.3};
    double c = {2.3};

    int d = 3.14;
    // int e = {3.14};    // Compiler error due to incompatible types

    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    cout << "c = " << c << endl;
    cout << "d = " << d << endl;
    cout << endl;

    // Automatic types - deduced from the initalizer
    auto m = 3;
    auto n = 3.14;
    auto o = 'x';
    auto p = "Hello";

    cout << "m = " << m << endl;
    cout << "n = " << n << endl;
    cout << "o = " << o << endl;
    cout << "p = " << p << endl;
    cout << endl;

    // Constants
    const int cint = 10;
    constexpr int cexp = 20;

    cout << "cint = " << cint << endl;
    cout << "cexp = " << cexp << endl;
    cout << endl;

    // Range-for (or for-each)
    vector<int> v = {1, 2, 3, 4};
    cout << "v = ";
    for (auto const &ii : v) {
        cout << ii << " ";
    }
    cout << endl;

    // Pointer
    int * ptr = nullptr;    //* Null pointer
    if (ptr == nullptr) {
        cout << "ptr is null (nullptr)" << endl;
    }
    else {
        cout << "ptr is not null" << endl;
    }

    return 0;
}
