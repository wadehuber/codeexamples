#include<iostream>

using namespace std;

void print() {
    cout << endl;
}

template<typename FirstType, typename... RestOfTypes>
void print(FirstType first_parameter, RestOfTypes... leftovers) {
    cout << first_parameter << " ";
    print(leftovers...);
}

// C++ 17
template<typename ...T>
auto sum(T ...x) {
    return (x + ...);
}

int main() {

    int x = 10;
    string s = "Hello";
    double d = 3.14;

    print("Hello", "world!");
    print(1, 2, 3, 4, 5);
    print(x, s, d, "That's all, folks!");

    cout << endl << endl;

    cout << "sum ints: " << sum(1,2,3,4,5,6,x) << endl;
    cout << "sum doubles: " << sum(9.99, 3.421, 1.23, d) << endl;

    return 0;
}
