#include<iostream>
#include<string>

using namespace std;

class Animal {
    protected:
        string name;

    public:
        Animal(string s="Noname")  : name(s) { }   // Default value = "Noname"

        // Pure virtual method - must be overridden by non-abstract derived class
        virtual void speak() = 0;

        // Virtual method - can be overridden by the child class.  The type of the
        //   *OBJECT* being pointed to determines the method that gets called.
        virtual void move() { cout << "  ANIMAL " << name << " : I'm moving"  << endl; }

        // Non-virtual method - can be overridden by the child class.  The type 
        //   of the *POINTER* being used determines the method that gets called.
        void eat() { cout << "  ANIMAL " << name << " : I'm hungry!"  << endl; }
};

class Dog : public Animal {
    public:
        Dog(string s="GoodBoy") : Animal(s) {}
        void speak() override { cout << "  DOG " << name << " : Woof!" << endl; }
        void move() override { cout << "  DOG " << name << " : I'm running!"  << endl; }
        void fetch() { cout << "  DOG " << name << " : Ball! Ball!"  << endl; }
};

class Cat : public Animal {
    public:
        Cat(string s="Kitty") : Animal(s) {}
        void speak() override { cout << "  CAT " << name << " : Meow!" << endl; }
        virtual void move() override { cout << "  CAT " << name << " : Later."  << endl; }
};
        

int main() {
  /* // Can't instantiate an Animal object
  Animal a;
  Animal * aPtr;
  Animal & aRef = a;
  */

  Animal * adPtr;

  Dog d("Spot");
  Dog * dPtr;
  Dog & dRef = d;

  Cat c("Eek");
  Cat * cPtr;
  Cat & cRef = c;

  Animal & acRef = c;

  /* // Can't instantiate an Animal object
  cout << endl << "Animal object: " << endl;
  a.speak(); 
  a.move(); 
  a.eat(); 

  cout << endl << "Animal pointer to an Animal object: " << endl;
  aPtr = new Animal("Dale");
  aPtr->speak(); 
  aPtr->move(); 
  aPtr->eat(); 

  cout << endl << "Animal reference to an animal object: " << endl;
  aRef.speak();  
  aRef.move();  
  aRef.eat();  
  */

  cout << endl << "Dog object: " << endl;
  d.speak(); 
  d.move(); 
  d.eat(); 
  d.fetch(); 

  cout << endl << "Dog pointer to an Dog object: " << endl;
  dPtr = new Dog("Felix");
  dPtr->speak(); 
  dPtr->move(); 
  dPtr->eat(); 
  dPtr->fetch(); 

  cout << endl << "Animal pointer to an Dog object: " << endl;
  adPtr = &d;
  adPtr->speak(); 
  adPtr->move(); 
  adPtr->eat(); 
  // adPtr->fetch();    // Animal class has no 'fetch' member

  cout << endl << "Dog reference to an dog object: " << endl;
  dRef.speak();  
  dRef.move();  
  dRef.eat();  
  dRef.fetch();  

  cout << endl << "Cat object: " << endl;
  c.speak(); 
  c.move(); 
  c.eat(); 

  cout << endl << "Cat pointer to an Cat object: " << endl;
  cPtr = new Cat("Mittens");
  cPtr->speak(); 
  cPtr->move(); 
  cPtr->eat(); 

  cout << endl << "Cat reference to an cat object: " << endl;
  cRef.speak();  
  cRef.move();  
  cRef.eat();  

  cout << endl << "Animal reference to an cat object: " << endl;
  acRef.speak();  
  acRef.move();  
  acRef.eat();  

  return 0;
}
