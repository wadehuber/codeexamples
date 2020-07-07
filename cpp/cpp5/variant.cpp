#include<iostream>
#include<variant>

using namespace std;

void checkType(variant<int, double, string> v);

int main() {
    variant<int, double, string> values;

    values = 10;
    cout << "Values = " << get<int>(values) << endl;

    values = 83.242;
    cout << "Values = " << get<double>(values) << endl;

    values = "HELLO";
    cout << "Values = " << get<string>(values) << endl;
    cout << endl;

    checkType(values);
    values = 3.14;
    checkType(values);
    values = 7;
    checkType(values);

    return 0;
}

// Check to see what type a variant holds
void checkType(variant<int, double, string> v) {
    if (holds_alternative<int>(v)) {
        cout << "The parameter holds an int value = " << get<int>(v) << endl;
    }
    if (holds_alternative<double>(v)) {
        cout << "The parameter holds an double value = " << get<double>(v) << endl;
    }
    if (holds_alternative<string>(v)) {
        cout << "The parameter holds an string value = " << get<string>(v) << endl;
    }
}
