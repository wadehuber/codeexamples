#include<iostream>

void myFunc(int & parm) {
    parm = parm * 2;
}

// Return a reference to the smaller argument
int& whichIsSmaller(int &x, int &y) {
    if (x <= y) {
        return x;
    }
    else {
        return y;
    }
}

void display(const std::string str1, int a, 
             const std::string str2, int b, 
             const std::string str3, const int& ref) {
    std::cout << str1 << " = " << a << std::endl;
    std::cout << str2 << " = " << b << std::endl;
    std::cout << str3 << " = " << ref << std::endl << std::endl;
}

int main() {
    int x = 10;
    int y = x;
    int num1 = 10;
    int num2 = 20;

    int &ref = x;    // reference variable
    //int &ref2;     // references must be initialized!
    int & numRef = num1;

    //Print the variables
    display("x", x, "y", y, "ref", ref);

    std::cout << "Setting x = 20" << std::endl;
    x = 20;
    display("x", x, "y", y, "ref", ref);
  
    std::cout << "Setting ref = 30" << std::endl;
    ref = 30;
    display("x", x, "y", y, "ref", ref);
  
    std::cout << "Calling myFunc(x)" << std::endl;
    myFunc(x);
    display("x", x, "y", y, "ref", ref);
   
    std::cout << "Calling myFunc(ref)" << std::endl;
    myFunc(ref);
    display("x", x, "y", y, "ref", ref);
   
    std::cout << "Setting ref = y" << std::endl;
    ref = y;
    display("x", x, "y", y, "ref", ref);
  
    std::cout << "Calling myFunc(ref)" << std::endl;
    myFunc(ref);
    display("x", x, "y", y, "ref", ref);
   
    std::cout << std::endl;
    display("num1", num1, "num2", num2, "numRef", numRef);

    std::cout << "Setting numRef = 15" << std::endl;
    numRef = 15;
    display("num1", num1, "num2", num2, "numRef", numRef);

    // use reference returned from a function
    whichIsSmaller(num1, num2) = 100;
    display("num1", num1, "num2", num2, "numRef", numRef);
    std::cout << "The smaller number is now " << whichIsSmaller(num1, num2) << std::endl;

    return 0;
}
  
