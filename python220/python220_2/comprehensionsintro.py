"""
    File: comprehensionsintro.py

    This file introduces comprehensions in Python, which are a concise way to
    create lists, sets, and dictionaries.  They are often more efficient than
    using loops to create these data structures.
""" 

# Examples without using comprehensions
print("Old style:")

# Create a list of letters from a word
WORD = 'hello'
lets = []
for c in WORD:
    lets.append(c)
print(lets)

# Create a list of squares of numbers
nums = [1, 2, 3, 4, 5]
squares = []
for x in nums:
    squares.append(x * x)  # append square of each number
print(squares)

# Comprehensions
print()
print("Using comprehensions:")


# Create a list of letters from a word using a list comprehension
lets = [c for c in WORD]  # list comprehension
print(lets)

# Create a list of squares of numbers using a list comprehension
squares = [x*x for x in nums] # list comprehension
print(squares)

print()
print("Set Comprehensions")
# Set comprehensions are similar to list comprehensions but create a set
# The main difference is that sets do not allow duplicate elements
nums = [1, 2, 3, 4, 5]
evens = {x for x in nums if x % 2 == 0}
print(evens) # {2, 4}

words = ['hello', 'world', 'hello', 'python']
first_letters = {word[0] for word in words}
print(first_letters) # {'h', 'w', 'p'}

print()
print("Dictionary Comprehensions")
# Dictionary comprehensions allow you to create dictionaries in a concise way
# The syntax is similar to set comprehensions but includes key-value pairs
nums = [1, 2, 3, 4, 5]
lookup = {x: x ** 3 for x in nums}
print(lookup) # {1: 1, 2: 8, 3: 27, 4: 64, 5: 125}

# Grade book example
students = ['Alice', 'Bob', 'Charlie']
grades = [85, 92, 78]
grade_book = {student: grade for student, grade in zip(students, grades)}
print(grade_book) # {'Alice': 85, 'Bob': 92, 'Charlie': 78}

# A more complicated list comprehension example
# This creates a list of products of two numbers from 0 to 9
result = [x * y
          for x in range(10)
          for y in range(10)
          if x * y > 20
          and x % 2 == 0]

# Shortcuts so that you don't have to use a comprehension
print()
print("Shortcuts:")
print(list(WORD))
print(dict(zip(students, grades)))
