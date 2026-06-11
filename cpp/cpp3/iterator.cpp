#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    vector<int> v1 {4, 8, 15, 16, 23, 42};
    vector<string> v2 {"Sawyer", "Locke", "Kate", "Hurley", "Jack", "Sayid", "Desmond"};

    // Loop through a vector using an iterator.
    //     begin(v1) points to the first element.
    //  end(v1) points one past the last element.
    int sum = 0;

    for (auto itr = begin(v1); itr != end(v1); itr++) {
        sum += *itr;  // *itr gives the element the iterator points to
    }
    cout << "The sum of elements in v1 is " << sum << endl;

    // Loop backward using a reverse iterator.
    cout << "Numbers reversed: ";
    for (auto itr = rbegin(v1); itr != rend(v1); itr++) {
        cout << *itr << " ";
    }
    cout << endl;

    // Range-for loop.
    // This is simpler when you just want each value.
    cout << "Names:" << endl;
    for (auto val : v2) {
        cout << "    " << val << endl;
    }

    return 0;
}