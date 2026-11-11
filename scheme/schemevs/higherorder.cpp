// Higher-order functions in C++ - lambdas, std::function, and <algorithm>
// Compile & run:  g++ -std=c++17 higherorder.cpp -o higherorder && ./higherorder

#include <algorithm>    // std::transform, std::copy_if, std::max
#include <cstdlib>      // std::abs
#include <functional>   // std::function, std::minus
#include <iostream>
#include <iterator>     // std::back_inserter
#include <numeric>      // std::accumulate
#include <string>
#include <vector>
using namespace std;

void print(const vector<int>& v) {
    for (int n : v) cout << n << " ";
    cout << endl;
}

// There is no built-in map that returns a new vector, so we write small helpers
// on top of the STL algorithms. Each takes a FUNCTION as a parameter.
vector<int> mapList(function<int(int)> f, const vector<int>& lst) {
    vector<int> result;
    transform(lst.begin(), lst.end(), back_inserter(result), f);
    return result;
}

vector<int> filterList(function<bool(int)> pred, const vector<int>& lst) {
    vector<int> result;
    copy_if(lst.begin(), lst.end(), back_inserter(result), pred);
    return result;
}

// The loop version: we manage the total ourselves
int sumPosSquaresLoop(const vector<int>& lst) {
    int total = 0;
    for (int x : lst) {
        if (x > 0) total += x * x;
    }
    return total;
}

// Functional version: filter -> map -> fold, the same shape as the Scheme code
int sumPosSquares(const vector<int>& lst) {
    auto square = [](int x) { return x * x; };
    auto positive = [](int x) { return x > 0; };
    vector<int> squares = mapList(square, filterList(positive, lst));
    return accumulate(squares.begin(), squares.end(), 0);
}

// A generic higher-order function: takes a function f and a value x
template <typename F, typename T>
T applyTwice(F f, T x) {
    return f(f(x));
}

int main() {
    const vector<int> lst = {-4, 7, -2, 5, 10, -8, 3};
    auto square = [](int x) { return x * x; };          // a lambda stored in a variable

    cout << "map - apply a function to every element" << endl;
    print(mapList(square, lst));
    print(mapList([](int x) { return abs(x); }, lst));
    print(mapList([](int x) { return x * 10; }, lst));

    cout << endl << "filter - keep only the elements that pass a test" << endl;
    print(filterList([](int x) { return x > 0; }, lst));
    print(filterList([](int x) { return x % 2 == 0; }, lst));
    print(filterList([](int x) { return x > 4; }, lst));

    cout << endl << "accumulate - C++'s fold" << endl;
    cout << accumulate(lst.begin(), lst.end(), 0) << endl;               // sum
    cout << accumulate(lst.begin(), lst.end(), lst[0],
                       [](int a, int b) { return max(a, b); }) << endl;  // largest value

    cout << endl << "Fold order - accumulate calls f(total, element)" << endl;
    // ((0 - 1) - 2) - 3 = -6. Racket's foldl calls (f element total) instead,
    // so (foldl - 0 '(1 2 3)) is 2. The folds only agree for operations like +.
    const vector<int> small = {1, 2, 3};
    cout << accumulate(small.begin(), small.end(), 0, minus<int>()) << endl;

    cout << endl << "Imperative version - sum of squares of the positive numbers" << endl;
    cout << sumPosSquaresLoop(lst) << endl;
    cout << "Functional version - filter -> map -> fold" << endl;
    cout << sumPosSquares(lst) << endl;
    cout << sumPosSquares({1, 2, 3}) << endl;

    cout << endl << "Functions are values - store them in a vector" << endl;
    vector<function<int(int)>> operations = {
        square,
        [](int x) { return abs(x); },
        [](int x) { return x + 100; }
    };
    for (const auto& op : operations) {
        cout << op(-5) << " ";
    }
    cout << endl;

    cout << endl << "Writing our own higher-order function" << endl;
    cout << applyTwice(square, 3) << endl;
    cout << applyTwice([](string s) { return s + "!"; }, string("Hello")) << endl;

    return 0;
}
