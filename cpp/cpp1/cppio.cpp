#include<iostream>
#include<string>

int main() {
  int count;
  std::string str;

  std::cout << "Enter a number: ";
  std::cin >> count;

  std::cout << "Enter a word: ";
  std::cin >> str; // Note: this ONLY gets characters until the next whitespace!

  for (int ii=0; ii<count; ii++) {
    std::cout << ii+1 << " : " << str << std::endl;
  }


  // Clear stdin by reading to the next newline
  getline(std::cin, str);

  std::cout << std::endl;
  std::cout << "Enter a string: ";
  getline(std::cin, str);

  for (int ii=0; ii<count; ii++) {
    std::cout << ii+1 << " : " << str << std::endl;
  }

  return 0;
}
