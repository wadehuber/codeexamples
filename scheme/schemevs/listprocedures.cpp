// List procedures - iterative and recursive versions of the Scheme examples
// Compile & run:  g++ -std=c++17 listprocedures.cpp -o listprocedures && ./listprocedures

#include <algorithm>   // std::find, std::count
#include <iostream>
#include <string>
#include <vector>
using namespace std;

using StrList = vector<string>;

void print(const StrList& v) {
    cout << "( ";
    for (const string& s : v) cout << s << " ";
    cout << ")" << endl;
}

// ---------- Iterative versions: loops and variables that change ----------

bool memberLoop(const string& ele, const StrList& lst) {
    for (const string& s : lst) {
        if (s == ele) return true;
    }
    return false;
}

StrList remberLoop(const string& ele, StrList lst) {   // pass by value = our own copy
    for (size_t i = 0; i < lst.size(); i++) {
        if (lst[i] == ele) {
            lst.erase(lst.begin() + i);
            break;                                      // first occurrence only
        }
    }
    return lst;
}

int countOfLoop(const string& ele, const StrList& lst) {
    int count = 0;
    for (const string& s : lst) {
        if (s == ele) count++;
    }
    return count;
}

// ---------- Recursive versions: the Scheme structure in C++ ----------
// An index i marks where "the rest of the list" starts:
// car -> lst[i]      cdr -> recur with i + 1      null? -> i == lst.size()

bool memberRec(const string& ele, const StrList& lst, size_t i = 0) {
    if (i == lst.size()) return false;
    if (lst[i] == ele) return true;
    return memberRec(ele, lst, i + 1);
}

StrList remberRec(const string& ele, const StrList& lst, size_t i = 0) {
    if (i == lst.size()) return {};
    if (lst[i] == ele) return StrList(lst.begin() + i + 1, lst.end());
    StrList rest = remberRec(ele, lst, i + 1);
    rest.insert(rest.begin(), lst[i]);                  // "cons" onto the front
    return rest;
}

int countOfRec(const string& ele, const StrList& lst, size_t i = 0) {
    if (i == lst.size()) return 0;
    int restCount = countOfRec(ele, lst, i + 1);
    return lst[i] == ele ? 1 + restCount : restCount;
}

int main() {
    const StrList lst = {"apple", "banana", "cherry", "banana", "date"};
    cout << boolalpha;                                  // print true/false, not 1/0

    cout << "member? - is an element in the list?" << endl;
    cout << memberLoop("cherry", lst) << " " << memberLoop("kiwi", lst) << endl;
    cout << memberRec("cherry", lst) << " " << memberRec("kiwi", lst) << endl;
    cout << (find(lst.begin(), lst.end(), "cherry") != lst.end()) << endl;  // the STL way

    cout << endl << "rember - remove the FIRST occurrence of an element" << endl;
    print(remberLoop("banana", lst));
    print(remberRec("banana", lst));
    print(remberRec("kiwi", lst));

    cout << endl << "countOf - how many times does an element appear?" << endl;
    cout << countOfLoop("banana", lst) << endl;
    cout << countOfRec("banana", lst) << endl;
    cout << count(lst.begin(), lst.end(), "banana") << endl;               // the STL way

    // NOTE: a C++ vector holds ONE type. A mixed list like Scheme's
    // (3 hello "World" 7.5 (1 2)) would need std::variant or std::any.
    return 0;
}
