#include<iostream>

int main() {
    int count;
    std::string str;

    std::cout << "Enter a number: ";
    std::cin >> count;

    std::cout << "Enter a word: ";
    std::cin >> str;  // cin only gets character until the next whitespace

    for(int ii=0; ii<count; ii++) {
        std::cout << ii+1 << " : " << str << std::endl;
    }
    getline(std::cin, str);

    std::cout << std:: endl;
    std::cout << "Enter a string: ";
    getline(std::cin, str);

    for(int ii=0; ii<count; ii++) {
        std::cout << ii+1 << " : " << str << std::endl;
    }

    return 0;
}
