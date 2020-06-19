#include<iostream>
#include<string>

using namespace std;

int main() {
    string str1 = "Hello";
    string str2 = "World";
    string str3 = "String";

    // C-style string
    char cstr1[] = "C style";

    int num {10};

    // print message by appending string
    cout << str1 + ", " + str2 + "!" << endl;
    cout << str1 + ", " + cstr1 + "!" << endl;

    // Append and int to a string - convert the int to a string first
    cout << "str3 = " << str3 + to_string(num) << endl;
  
    // Replace part of a string
    string str4 = "I am a C++ programmer";
    cout << endl << "Before replace: " << str4 << endl;
    // Replace 4 characters at index 0
    str4.replace(0, 4, "You are");
    cout << endl << "After replace 1: " << str4 << endl;
    // Replace 3 characters at index 10
    str4.replace(10, 3, "Prolog");
    cout << endl << "After replace 2: " << str4 << endl;

    // Get a substring
    string str5 = str4.substr(4,3);
    cout << "str5 = " << str5 << endl;

    // Convert a C++ string to C-style string
    const char * cstr2 = str3.c_str();
    cout << "cstr2 = " << cstr2 << endl;

    return 0;
}
