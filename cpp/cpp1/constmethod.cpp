#include<iostream>

class ConstClass {
private:
    int num;
public:
    ConstClass(int x) { num = x; }

    // print() should not change the object, so we declare it const
    void print() const { std::cout << "num=" << num << std::endl;}

    // const is part of the method signature, so func() is overloaded
    void func() { std::cout << "func (non-const) " << num << std::endl; }
    void func() const { std::cout << "func (const) " << num << std::endl; }
};

// obj is passed by constant reference
void stuff(const ConstClass& obj) {
    std::cout << "stuff function:" << std::endl;
    obj.print();
    obj.func();
    std::cout << std::endl;
}

int main() {
    ConstClass nonConstObj(20);
    const ConstClass constObj(10);

    ConstClass * ptr = &nonConstObj;
    const ConstClass * constPtr = &constObj;

    std::cout << "nonConstObj:" << std::endl;
    nonConstObj.print();
    nonConstObj.func();
    std::cout << std::endl;

    std::cout << "constObj:" << std::endl;
    constObj.print();
    constObj.func();
    std::cout << std::endl;

    std::cout << "non-const pointer to nonConstObj:" << std::endl;
    ptr->print();
    ptr->func();
    std::cout << std::endl;

    std::cout << "const pointer to constObj:" << std::endl;
    constPtr->print();
    constPtr->func();
    std::cout << std::endl;

    constPtr = &nonConstObj;
    std::cout << "const pointer to nonConstObj:" << std::endl;
    constPtr->print();
    constPtr->func();
    std::cout << std::endl;

    std::cout << "stuff(nonConstObj):" << std::endl;
    stuff(nonConstObj);
    std::cout << std::endl;

    std::cout << "stuff(constObj):" << std::endl;
    stuff(constObj);
    std::cout << std::endl;

    return 0;
}
