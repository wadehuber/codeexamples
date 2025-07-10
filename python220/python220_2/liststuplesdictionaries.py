"""
# File: liststuplesdictionaries.py
# This module demonstrates the use of lists, tuples, and dictionaries in Python

# It covers creation, operations, and practical examples of these data
# structures. It also includes examples of list comprehensions, tuple unpacking,
# and nested dictionaries.
"""

from collections import namedtuple

print("#" * 70)
print("LISTS - Mutable, ordered collections")
print("#" * 70)

# Creating lists
numbers = [1, 2, 3, 4, 5]
names = ["Inky", "Blinky", "Pinky", "Clyde"]
mixed = [1, "hello", 3.14, True, [1, 2, 3]]
empty_list = []

print(f"Numbers: {numbers}")
print(f"Names: {names}")
print(f"Mixed types: {mixed}")
print(f"Empty list: {empty_list}")

# List operations
print("\n--- List Operations ---")
names.append("PacMan")  # Add to end
print(f"After append: {names}")

names.insert(1, "Ms PacMan")  # Insert at index
print(f"After insert: {names}")

removed = names.pop()  # Remove and return last item
print(f"Removed: {removed}, List now: {names}")

names.remove("Clyde")  # Remove first occurrence
print(f"After removing Clyde: {names}")

# List slicing
print(f"First 3 names: {names[:3]}")
print(f"Last 2 names: {names[-2:]}")
print(f"Every other name: {names[::2]}")

# List comprehension
squares = [x**2 for x in range(1, 6)]
print(f"Squares: {squares}")

# Iterating through lists
print("\n--- Iterating through lists ---")
for i, fruit in enumerate(names):
    print(f"Index {i}: {fruit}")

print("\n" + "#" * 70)
print("TUPLES - Immutable, ordered collections")
print("#" * 70)

# Creating tuples
coordinates = (3, 4)
colors = ("red", "green", "blue")
single_item = (42,)  # Note the comma for single item
empty_tuple = ()

print(f"Coordinates: {coordinates}")
print(f"Colors: {colors}")
print(f"Single item tuple: {single_item}")
print(f"Empty tuple: {empty_tuple}")

# Tuple operations
print("\n--- Tuple Operations ---")
print(f"First color: {colors[0]}")
print(f"Last color: {colors[-1]}")
print(f"Length: {len(colors)}")

# Tuple unpacking
x, y = coordinates
print(f"Unpacked coordinates: x={x}, y={y}")

# Multiple assignment using tuples
a, b, c = colors
print(f"Unpacked colors: a={a}, b={b}, c={c}")

# Tuples as dictionary keys (since they're immutable)
locations = {(0, 0): "origin", (1, 1): "northeast", (-1, -1): "southwest"}
print(f"Locations: {locations}")

# Named tuples (from collections module)
# from collections import namedtuple
Point = namedtuple("Point", ["x", "y"])
p = Point(3, 4)
print(f"Named tuple: {p}, x={p.x}, y={p.y}")

print("\n" + "#" * 70)
print("DICTIONARIES - Mutable, key-value pairs")
print("#" * 70)

# Creating dictionaries
student = {"name": "Alice", "age": 20, "major": "Computer Science", "gpa": 3.8}

# Different ways to create dictionaries
empty_dict = {}
dict_from_list = dict([("a", 1), ("b", 2), ("c", 3)])
dict_comprehension = {x: x**2 for x in range(1, 6)}

print(f"Student: {student}")
print(f"From list: {dict_from_list}")
print(f"Comprehension: {dict_comprehension}")

# Dictionary operations
print("\n--- Dictionary Operations ---")
print(f"Student name: {student['name']}")
print(f"Student age: {student.get('age', 'Unknown')}")

# Adding/updating
student["graduation_year"] = 2025
student["age"] = 21
print(f"Updated student: {student}")

# Removing items
removed_gpa = student.pop("gpa")
print(f"Removed GPA: {removed_gpa}")
print(f"Student after removal: {student}")

# Dictionary methods
print(f"Keys: {list(student.keys())}")
print(f"Values: {list(student.values())}")
print(f"Items: {list(student.items())}")

# Iterating through dictionaries
print("\n--- Iterating through dictionaries ---")
for key, value in student.items():
    print(f"{key}: {value}")

# Nested dictionaries
students = {
    "alice": {"age": 20, "major": "CS"},
    "bob": {"age": 19, "major": "Math"},
    "charlie": {"age": 21, "major": "Physics"},
}

print(f"\nNested dictionaries: {students}")
print(f"Alice's major: {students['alice']['major']}")

print("\n" + "#" * 70)
print("COMPARISON AND CONVERSION")
print("#" * 70)

# Converting between types
list_example = [1, 2, 3, 4, 5]
tuple_from_list = tuple(list_example)
list_from_tuple = list(tuple_from_list)

print(f"Original list: {list_example}")
print(f"Tuple from list: {tuple_from_list}")
print(f"List from tuple: {list_from_tuple}")

# Dictionary keys/values to lists
dict_example = {"a": 1, "b": 2, "c": 3}
keys_list = list(dict_example.keys())
values_list = list(dict_example.values())

print(f"Dictionary keys as list: {keys_list}")
print(f"Dictionary values as list: {values_list}")

print("\n" + "#" * 70)
print("PRACTICAL EXAMPLES")
print("#" * 70)

# Example 1: Shopping cart (using dictionary)
shopping_cart = {}


def add_item(cart, product, amount):
    """Add an item to the shopping cart if it doesn't already exist."""
    if product in cart:
        cart[product] += amount
    else:
        cart[product] = amount


add_item(shopping_cart, "apples", 5)
add_item(shopping_cart, "bananas", 3)
add_item(shopping_cart, "apples", 2)

print("Shopping cart:")
for item, quantity in shopping_cart.items():
    print(f"  {item}: {quantity}")

# Example 2: Student grades (using lists and dictionaries)
grades = {
    "Alice": [85, 92, 78, 96],
    "Bob": [79, 85, 88, 92],
    "Charlie": [92, 88, 84, 90],
}

print("\nStudent averages:")
for student, grade_list in grades.items():
    average = sum(grade_list) / len(grade_list)
    print(f"  {student}: {average:.1f}")

# Example 3: Word frequency counter
TEXT = "the quick brown fox jumps over the lazy dog the fox is quick"
word_count = {}

for word in TEXT.split():
    word_count[word] = word_count.get(word, 0) + 1

print(f"\nWord frequencies: {word_count}")

# Example 4: Coordinates as tuples in a list
path = [(0, 0), (1, 1), (2, 1), (3, 2), (4, 2)]
print(f"\nPath coordinates: {path}")

# Calculate distance traveled
TOTAL_DISTANCE = 0
for i in range(1, len(path)):
    x1, y1 = path[i - 1]
    x2, y2 = path[i]
    distance = ((x2 - x1) ** 2 + (y2 - y1) ** 2) ** 0.5
    TOTAL_DISTANCE += distance

print(f"Total distance: {TOTAL_DISTANCE:.2f}")
