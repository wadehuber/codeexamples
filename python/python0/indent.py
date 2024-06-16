import random

# Examples of python indentation

# Functions
def print_it(value):
    print(value)

x = random.randint(1,10)
print_it("x = " + str(x))

if x >=5:
    print("big")
else:
    while x <= 10:
        x = x + 1
        print("growing")
