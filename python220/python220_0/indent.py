import random

# Examples of python indentation

# Function
def print_it(value):
    print("===============")
    print(value)
    print("===============")

print("Examples of indenting in Python")

x = random.randint(1,10)
print_it(x)

if x > 5:
    print("big")
else:
    while x <= 10:
        x = x + 1
        print("growing")