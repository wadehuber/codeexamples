// Pure functions & referential transparency
// Compile & run:  g++ -std=c++17 purefunctions.cpp -o purefunctions && ./purefunctions

#include <iostream>
#include <vector>
using namespace std;

// A pure function - depends only on its parameter and changes nothing else
int square(int x) {
    return x * x;
}

// An IMPURE function - a static local variable remembers its value between calls
int f(int x) {
    static int count = 0;
    count++;                         // side effect: hidden state changes
    return x + count;
}

// The functional fix - make the hidden state an explicit parameter
int fPure(int x, int count) {
    return x + count;
}

// Side effects through references: this function changes the caller's vector
void addBonus(vector<int>& scores) {
    for (int& s : scores) {
        s += 5;
    }
}

// A pure alternative: take a const reference, return a NEW vector
vector<int> withBonus(const vector<int>& scores) {
    vector<int> result;
    for (int s : scores) {
        result.push_back(s + 5);
    }
    return result;
}

void print(const vector<int>& v) {
    for (int n : v) cout << n << " ";
    cout << endl;
}

int main() {
    cout << "A pure function - same input, same output" << endl;
    cout << square(5) << endl;
    cout << square(5) << endl;
    cout << square(5) + square(5) << endl;
    cout << 2 * square(5) << endl;            // same answer - the algebra works

    cout << endl << "An impure function - same input, different output" << endl;
    cout << f(10) + f(10) << endl;             // 11 + 12 = 23
    cout << 2 * f(10) << endl;                 // 2 * 13 = 26 -- the algebra is broken. Even starting
                                               // over from count = 0 it would be 2 * 11 = 22, not 23
    cout << f(10) << endl;                     // 14

    cout << endl << "Side effects make the ORDER of evaluation matter" << endl;
    // C++ does not define which operand of - is evaluated first, so f(10) - f(10)
    // could be -1 or 1. Separate statements force an order. (The sum above is
    // safe to write directly: 11 + 12 and 12 + 11 are the same.)
    int first = f(10);                         // 15
    int second = f(10);                        // 16
    cout << first - second << endl;            // -1

    cout << endl << "The functional fix" << endl;
    cout << fPure(10, 1) + fPure(10, 1) << endl;
    cout << 2 * fPure(10, 1) << endl;          // equal again

    cout << endl << "Modifying vs returning a new value" << endl;
    vector<int> scores = {80, 90, 70};
    addBonus(scores);
    addBonus(scores);                          // called twice by mistake?
    print(scores);                             // 90 100 80

    const vector<int> original = {80, 90, 70};
    print(withBonus(original));                // 85 95 75
    print(withBonus(original));                // 85 95 75 - same every time
    print(original);                           // 80 90 70 - unchanged
    return 0;
}
