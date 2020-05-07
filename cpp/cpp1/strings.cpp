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

  // Append an int to a string - convert the int to a string first
  cout << "str3 = " << str3 + to_string(num) << endl;

  // Replace part of the string
  std::string str4 = "I am a C++ programmer";
  std::cout << "  Before replace: " << str4 << std::endl;
  // Replace 4 characters at index 0
  str4.replace(0,4,"You are");
  std::cout << " After replace 1: " << str4 << std::endl;
  // Replace 3 characters at index 10
  str4.replace(10,3,"Prolog");
  std::cout << " After replace 2: " << str4 << std::endl;

  // Get a substring
  std::string str5 = str4.substr(4,3);
  std::cout << "str5: " << str5 << std::endl;

  // Convert string to a C-style string
  const char * cstr2 = str3.c_str();
  std::cout << "cstr2: " << cstr2 << std::endl;

  return 0;
}
