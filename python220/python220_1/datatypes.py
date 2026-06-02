'''Examples of Python data types: integers, floats, complex numbers, and booleans'''

# Integers
print("=== INTEGERS ===")
x = 42
y = -17
z = 2 ** 100  # Python handles arbitrarily large integers
print(f"x = {x}, type = {type(x)}")
print(f"y = {y}, type = {type(y)}")
print(f"z = {z} (2^100)")
print(f"Large integer math: {z + 1}")
print()

# Floating-point numbers
print("=== FLOATS ===")
a = 3.14
b = -2.5
c = 1.0 / 3.0
print(f"a = {a}, type = {type(a)}")
print(f"b = {b}, type = {type(b)}")
print(f"c = 1/3 = {c}")
print(f"Floating-point rounding: 0.1 + 0.2 = {0.1 + 0.2}")
print()

# Complex numbers
print("=== COMPLEX NUMBERS ===")
complex1 = 3 + 4j
complex2 = 2 - 3j
print(f"complex1 = {complex1}, type = {type(complex1)}")
print(f"complex2 = {complex2}")
print(f"Sum: {complex1 + complex2}")
print(f"Product: {complex1 * complex2}")
print(f"Real part: {complex1.real}, Imaginary part: {complex1.imag}")
print()

# Booleans
print("=== BOOLEANS ===")
is_student = True
is_adult = False
print(f"is_student = {is_student}, type = {type(is_student)}")
print(f"is_adult = {is_adult}, type = {type(is_adult)}")
print(f"True and False = {True and False}")
print(f"True or False = {True or False}")
print(f"not True = {not True}")
print()

# Truthiness - values that evaluate to True/False in boolean context
print("=== TRUTHINESS ===")
print(f"bool(0) = {bool(0)}")
print(f"bool(1) = {bool(1)}")
print(f"bool([]) = {bool([])}")
print(f"bool([1, 2, 3]) = {bool([1, 2, 3])}")
print(f"bool('') = {bool('')}")
print(f"bool('hello') = {bool('hello')}")
print(f"bool(None) = {bool(None)}")
print()

# Type conversion
print("=== TYPE CONVERSION ===")
int_val = int(3.14)
float_val = float(42)
str_val = str(123)
bool_val = bool(0)
print(f"int(3.14) = {int_val}")
print(f"float(42) = {float_val}")
print(f"str(123) = '{str_val}' (type = {type(str_val)})")
print(f"bool(0) = {bool_val}")
