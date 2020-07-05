#include<iostream>
#include<memory>

void printPointers(std::shared_ptr<int> &a, std::shared_ptr<int> &b, 
                   std::unique_ptr<int> &c, std::unique_ptr<int> &d) {
    std::cout << "Shared pointer 1: " << *a << " count " << a.use_count() << std::endl;
    std::cout << "Shared pointer 2: " << *b << " count " << b.use_count() << std::endl;
    std::cout << "Unique pointer 3: " << *c << std::endl;
    std::cout << "Unique pointer 4: " << *d << std::endl;
    std::cout << std::endl;
}

int main() {
    // Shared pointers
    std::shared_ptr<int> sptr1(new int(1));
    auto sptr2 = std::make_shared<int>(2);

    // Unique pointers
    std::unique_ptr<int> uptr3(new int(5));
    auto uptr4 = std::make_unique<int>(10);

    printPointers(sptr1, sptr2, uptr3, uptr4);

    *sptr1 = 3;
    std::cout << "sptr1 value changed: *sptr1 = 3;" << std::endl;
    printPointers(sptr1, sptr2, uptr3, uptr4);

    *uptr3 = 7;
    std::cout << "uptr1 value changed: *uptr1 = 7;" << std::endl;
    printPointers(sptr1, sptr2, uptr3, uptr4);

    sptr2 = sptr1;
    std::cout << "sptr2=sptr1" << std::endl;
    printPointers(sptr1, sptr2, uptr3, uptr4);

    //sptr2 = new int(4);
    sptr2.reset(new int(4));
    std::cout << "sptr2 changed" << std::endl;
    printPointers(sptr1, sptr2, uptr3, uptr4);

    //uptr3 = uptr4;
    uptr3 = std::move(uptr4);
    std::cout << "sptr3 = std:move(uptr4)" << std::endl;
    std::cout << "Unique pointer 3: " << *uptr3 << std::endl;

    return 0;
}
