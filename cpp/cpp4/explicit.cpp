#include<iostream>

using namespace std;

class ImplicitClass {
    private:
        int member;
    public:
        ImplicitClass(int x) : member(x) {};
        void print() const { cout << "ImplicitClass : " << member << endl; }
};

class ExplicitClass {
    private:
        int member;
    public:
        explicit ExplicitClass(int x) : member(x) {};
        void print() const { cout << "ExplicitClass : " << member << endl; }
};

void checkImplicitClass(ImplicitClass p) {
    p.print();
}
void checkExplicitClass(ExplicitClass p) {
    p.print();
}

int main() {
    ImplicitClass imp(10);
    ExplicitClass exp(20);

    checkImplicitClass(imp);
    checkExplicitClass(exp);

    checkImplicitClass(40);
    // checkExplicitClass(50);  // Not allowed since the constructor is explicit

    return 0;
}
