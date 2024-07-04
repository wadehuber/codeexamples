'''Example Python class - Animal hierarchy'''

class Animal:
    '''Animal class with speak, move, and eat methods.'''

    def __init__(self, name="NoName"):
        "Constructor for Animal class"
        print("ANIMAL: Constructor")
        self.name=name

    def speak(self):
        print("ANIMAL " + self.name + ": speaks")

    def move(self):
        print("ANIMAL " + self.name + ": I'm moving")

    def eat(self):
        print("ANIMAL " + self.name + ": I'm hungry!")

class Dog(Animal):
    '''Dog class extends Animal with fetch method.'''

    def __init__(self, name="NoName"):
        "Constructor for Dog class - calls Animal constructor first"
        super().__init__(name)
        print("DOG: Constructor")

    def speak(self):
        print("DOG " + self.name + ": Woof! Woof!")

    def move(self):
        print("DOG " + self.name + ": I'm running!")

    def fetch(self):
        print("DOG " + self.name + ": Ball! Ball!")

class Cat(Animal):
    '''Cat class extends Animal.'''

    def __init__(self, name="NoName"):
        "Constructor for Cat class - calls Animal constructor first"
        super().__init__(name)
        print("CAT: Constructor")

    def speak(self):
        print("CAT " + self.name + ": Meow!")

    def move(self):
        print("CAT " + self.name + ": Later")

if __name__ == "__main__":
    print("MAIN: Python class example")

    a=Animal('George')
    d=Dog('Spot')
    c=Cat('Eek')

    print("MAIN: Animal object:")
    a.speak()
    a.move()
    a.eat()

    print("MAIN: Dog object:")
    d.speak()
    d.move()
    d.eat()
    d.fetch()

    print("MAIN: Cat object:")
    c.speak()
    c.move()
    d.eat()
