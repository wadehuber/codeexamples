#include<iostream>
#include<string>

using namespace std;

class Animal {
    protected:
        string name;
    public:
        Animal(const string &s="NoName") : name(s) { }   // Default value = "NoName"

        void speak() { cout << "  ANIMAL " << name << " : Hello, I'm " << name << endl; }
        void move() { cout << "  ANIMAL " << name << " : I'm moving" << endl; }
        void eat() { cout << "  ANIMAL " << name << " : I'm hungry!" << endl; }
};

int main() {
    Animal a;
    Animal * aPtr;
    Animal & aRef = a;

    cout << "Animal object:" << endl;
    a.speak();
    a.move();
    a.eat();

    cout << endl << "Animal pointer:" << endl;
    aPtr = new Animal("Dale");
    aPtr->speak();
    aPtr->move();
    aPtr->eat();

    cout << endl << "Animal reference" << endl;
    aRef.speak();
    aRef.move();
    aRef.eat();

    return 0;
}