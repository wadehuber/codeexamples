// Immutability - modifying data in place vs building new data
// Compile & run:  g++ -std=c++17 immutability.cpp -o immutability && ./immutability

#include <iostream>
#include <vector>
using namespace std;

void print(const vector<int>& v) {
    for (int n : v) cout << n << " ";
    cout << endl;
}

// Builds and returns a new vector; the const parameter cannot be modified
vector<int> doubleList(const vector<int>& lst) {
    vector<int> result;
    for (int n : lst) {
        result.push_back(n * 2);
    }
    return result;
}

// Pass by value gives us our own copy to work with - the caller's vector is safe
vector<int> insertSorted(int n, vector<int> lst) {
    auto pos = lst.begin();
    while (pos != lst.end() && *pos < n) {
        ++pos;
    }
    lst.insert(pos, n);
    return lst;
}

int main() {
    cout << "Imperative: double each element IN PLACE" << endl;
    vector<int> arr = {1, 2, 3, 4, 5};
    vector<int> copy = arr;                    // in C++, = COPIES a vector (in Java it would share it)
    vector<int>& alias = arr;                  // the & makes alias a second name for the SAME vector
    for (size_t i = 0; i < arr.size(); i++) {
        arr[i] = arr[i] * 2;
    }
    print(arr);
    print(alias);                              // alias changed too - it is the same vector
    print(copy);                               // 1 2 3 4 5 - the copy is independent

    cout << endl << "Functional: return a NEW vector, leave the original alone" << endl;
    const vector<int> lst = {1, 2, 3, 4, 5};   // const: the compiler forbids changes
    print(doubleList(lst));
    print(lst);                                // the original is untouched

    // lst[0] = 100;      // <-- uncomment this line and the program will not compile

    cout << endl << "Insert into a sorted vector - returns a new sorted vector" << endl;
    print(insertSorted(3, {1, 2, 4, 5}));
    print(insertSorted(0, lst));
    print(insertSorted(9, lst));
    print(lst);                                // still 1 2 3 4 5

    return 0;
}
