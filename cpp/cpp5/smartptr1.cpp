#include<iostream>
#include<memory>

void printPointers(std::shared_ptr<int> &a, std::shared_ptr<int> &b, std::unique_ptr<int> &c, std::unique_ptr<int> &d) {
    std::cout << "Shared pointer1: " << *a << std::endl; 
    std::cout << "Shared pointer2: " << *b << std::endl; 
    std::cout << "Unique pointer3: " << *c << std::endl; 
    std::cout << "Unique pointer4: " << *d << std::endl; 
    std::cout << std::endl;
}

int main() {

    std::shared_ptr<int> sptr1(new int(1));
    std::shared_ptr<int> sptr2(new int(2));
    std::unique_ptr<int> uptr3(new int(10));
    auto uptr4 = std::make_unique<int>(5);

    printPointers(sptr1, sptr2, uptr3, uptr4);

    *sptr1 = 3;
    std::cout << "sptr1 value changed: *sptr1 = 3" << std::endl;
    printPointers(sptr1, sptr2, uptr3, uptr4);

    *uptr3 = 7;
    std::cout << "uptr3 value changed: *uptr3 = 7" << std::endl;
    printPointers(sptr1, sptr2, uptr3, uptr4);

    sptr2 = sptr1;
    std::cout << "sptr2=sptr1 " << std::endl;
    printPointers(sptr1, sptr2, uptr3, uptr4);

    // sptr2 = new int(4);
    sptr2.reset(new int(4));
    std::cout << "sptr2 changed" << std::endl;
    printPointers(sptr1, sptr2, uptr3, uptr4);

    // uptr3 = uptr4;
    // uptr3 = make_unique(uptr4);
    uptr3 = std::move(uptr4);
    // printPointers(sptr1, sptr2, uptr3, uptr4);

    return 0;
}
