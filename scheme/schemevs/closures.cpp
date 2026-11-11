// Closures & currying in C++ - functions that RETURN lambdas (C++14 and later)
// Compile & run:  g++ -std=c++17 closures.cpp -o closures && ./closures

#include <algorithm>
#include <functional>
#include <iostream>
#include <iterator>
#include <vector>
using namespace std;

void print(const vector<int>& v) {
    for (int n : v) cout << n << " ";
    cout << endl;
}

// make-adder: returns a new function each time it is called.
// [n] is the capture list - the lambda keeps its own COPY of n.
auto makeAdder(int n) {
    return [n](int x) { return x + n; };
}

bool validNumber(int n, int x, int y) {
    return n >= x && n <= y;
}

// Curried version: fix the range now, supply n later
auto validNumberCurr(int x, int y) {
    return [x, y](int n) { return validNumber(n, x, y); };
}

// quad: returns a polynomial function f(x) = ax^2 + bx + c
auto quad(double a, double b, double c) {
    return [=](double x) { return a * x * x + b * x + c; };   // [=] captures everything by copy
}

// compose: combine two functions into a new one
template <typename F, typename G>
auto compose2(F f, G g) {
    return [f, g](auto x) { return f(g(x)); };
}

// DANGER: capturing by reference [&] a variable that goes away
function<int(int)> makeBadAdder(int n) {
    return [&n](int x) { return x + n; };   // n is destroyed when this function returns!
}

int main() {
    cout << "makeAdder - returns a new function each time it is called" << endl;
    auto add5 = makeAdder(5);
    auto add100 = makeAdder(100);
    cout << add5(10) << endl;
    cout << add100(10) << endl;
    cout << makeAdder(3)(4) << endl;

    cout << endl << "Fully curried - a lambda that returns a lambda" << endl;
    auto add = [](int a) { return [a](int b) { return a + b; }; };
    cout << add(3)(4) << endl;

    cout << endl << "Currying - filter a list for numbers in a range" << endl;
    const vector<int> nums = {-10, -5, 0, 5, 10, 15, 20, 25, 30};
    vector<int> inRange;
    copy_if(nums.begin(), nums.end(), back_inserter(inRange), validNumberCurr(0, 20));
    print(inRange);

    cout << endl << "Generating polynomial functions" << endl;
    auto f1 = quad(1, 2, 3);
    auto f2 = quad(2, 0, -8);
    cout << f1(2) << endl;
    cout << f2(2) << endl;

    cout << endl << "compose - combine two functions into a new one" << endl;
    auto square = [](int x) { return x * x; };
    auto squareThenAdd5 = compose2(add5, square);
    cout << squareThenAdd5(3) << endl;

    // Uncommenting the next lines compiles, but is UNDEFINED BEHAVIOR -
    // the lambda refers to a variable that no longer exists.
    // Scheme closures never have this problem: the garbage collector keeps
    // captured values alive as long as the closure needs them.
    // auto bad = makeBadAdder(5);
    // cout << bad(10) << endl;

    return 0;
}
