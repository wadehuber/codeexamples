// Summing a list - the same problem three ways.
// Compile & run:  g++ -std=c++17 sumlist.cpp -o sumlist && ./sumlist

#include <iostream>
#include <numeric>     // std::accumulate
#include <vector>
using namespace std;

// To understand this function, we trace how total and i change over time.
int sumLoop(const vector<int>& values) {
    int total = 0;
    for (size_t i = 0; i < values.size(); i++) {
        total = total + values[i];
    }
    return total;
}

// A vector has no car/cdr, so we use an index to mark "the rest of the list."
// Base case: past the end -> 0.  Otherwise: first item + sum of the rest.
int sumRecursive(const vector<int>& values, size_t index) {
    if (index == values.size()) {
        return 0;
    }
    return values[index] + sumRecursive(values, index + 1);
}

// Tail-recursive: the recursive call is the last thing that happens.
// The C++ standard makes NO guarantee about tail calls. Optimizing compilers
// (g++ -O2) often eliminate them, but you cannot rely on it.
int sumAcc(const vector<int>& values, size_t index, int total) {
    if (index == values.size()) {
        return total;
    }
    return sumAcc(values, index + 1, total + values[index]);
}

int main() {
    // const: the vector cannot be changed after it is created
    const vector<int> values = {4, 8, 15, 16, 23, 42};

    cout << "Imperative sum - a loop that changes total and i" << endl;
    cout << sumLoop(values) << endl;

    cout << endl << "Recursive sum - the same structure as the Scheme version" << endl;
    cout << sumRecursive(values, 0) << endl;

    cout << endl << "Tail-recursive style - the running total is a parameter" << endl;
    cout << sumAcc(values, 0, 0) << endl;

    cout << endl << "Higher-order sum - std::accumulate is C++'s fold" << endl;
    cout << accumulate(values.begin(), values.end(), 0) << endl;

    return 0;
}
