'''Examples of Python variables and assignment'''

# Basic variable assignment - no type declaration needed
print("=== BASIC ASSIGNMENT ===")
name = "Alice"
age = 25
height = 5.8
is_student = True

print(f"name = {name}")
print(f"age = {age}")
print(f"height = {height}")
print(f"is_student = {is_student}")
print()

# Dynamic typing - variables can change type
print("=== DYNAMIC TYPING ===")
x = 42
print(f"x = {x}, type = {type(x)}")

x = "hello"
print(f"x = {x}, type = {type(x)}")

x = [1, 2, 3]
print(f"x = {x}, type = {type(x)}")
print()

# Multiple assignment
print("=== MULTIPLE ASSIGNMENT ===")
a, b, c = 1, 2, 3
print(f"a={a}, b={b}, c={c}")

# All same value
x = y = z = 0
print(f"x={x}, y={y}, z={z}")

# Swap values
p, q = 10, 20
print(f"Before: p={p}, q={q}")
p, q = q, p
print(f"After swap: p={p}, q={q}")
print()

# Variable naming rules
print("=== VARIABLE NAMING ===")
valid_name = "OK"
_private = "OK"
CamelCase = "OK"
snake_case = "OK"
# number_123 = "OK"  # Valid - numbers OK after first char
# 123_number = "INVALID"  # Cannot start with number

print("All naming examples are valid (except those commented out)")
