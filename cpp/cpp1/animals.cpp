#include<iostream>
#include<string>

using namespace std;

class Animal {
  protected:
    string name;

  public:
    Animal(string s="Noname")  { name = s; }   // Default value = "Noname"

    // Pure virtual method - must be overridden by non-abstract derrived class
    virtual void speak() = 0;

    // Virtual method - can be overriddedn by the child class.  The type of the 
    //   *OBJECT*  being pointed to determines the method that gets called.
    virtual void move() { cout << "  ANIMAL " << name << ": I'm moving"  << endl; }

    // Non-virtual method - can be overriddedn by the child class.  The type 
    //   of the *POINTER* being used determines the method that gets called.
    void eat() { cout << "  ANIMAL " << name << ": I'm hungry!"  << endl; }
};

class Dog : public Animal {
  public:
    Dog(string s="Boy") : Animal(s) {}

    void speak() { cout << "  DOG " << name << ": Woof!"  << endl; }
    void move() { cout << "  DOG " << name << ": Run around"  << endl; }
    void fetch() { cout << "  DOG " << name << ": Ball! Ball!"  << endl; }
};

class Cat : public Animal {
  public:
    Cat(string s="Kitty") : Animal(s) {}
    void speak() { cout << "  CAT " << name << ": Meow!"  << endl; }
};

int main() {
  // Animal a;   // Can't instantiate an Animal object
  Animal * aptr;
  Dog d("Rufus");
  Dog * dptr;
  Dog & dogRef = d;
  Cat c("Michael");
  Cat * cptr;

  /* // Can't instantiate an Animal
  cout << endl << "Animal object: " << endl;
  a.speak(); 
  a.move(); 
  a.eat(); 

  cout << endl << "Animal pointer to an Animal object: " << endl;
  aptr = new Animal("Dale");
  aptr->speak(); 
  aptr->move(); 
  aptr->eat(); 
  */

  cout << endl << "Dog object: " << endl;
  d.speak();  
  d.move();  
  d.eat();  
  d.fetch();  

  cout << endl << "Dog pointer to Dog object: " << endl;
  dptr = new Dog("Spot"); 
  dptr->speak();
  dptr->move();
  dptr->eat();
  dptr->fetch();

  cout << endl << "Animal pointer to Dog object: " << endl;
  aptr = new Dog("Clifford"); 
  aptr->speak();
  aptr->move();
  aptr->eat();
  // aptr->fetch();    // Animal class has no 'fetch' member

  cout << endl << "Dog reference to a Dog object: " << endl;
  dogRef.speak();
  dogRef.move();
  dogRef.eat();
  dogRef.fetch();

  cout << endl << "Cat object: " << endl;
  c.speak();  
  c.move();  
  c.eat();  

  cout << endl << "Cat pointer to Cat object: " << endl;
  cptr = new Cat("Mittens"); cptr->speak();
  cptr->move();
  cptr->eat();

  cout << endl << "Animal pointer to Cat object: " << endl;
  aptr = new Cat("Snowball"); 
  aptr->speak();
  aptr->move();
  aptr->eat();

  cout << endl << "Animal reference to Cat object: " << endl;
  Animal & animalRef = c;
  animalRef.speak();
  animalRef.move();
  animalRef.eat();

  return 0;
}
