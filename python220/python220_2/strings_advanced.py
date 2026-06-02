"""Advanced string operations: methods, formatting, and text processing"""

# String methods for text processing
print("=== STRING METHODS ===")
text = "  Hello, World!  "
print(f"Original: '{text}'")
print(f"strip(): '{text.strip()}'")
print(f"upper(): '{text.upper()}'")
print(f"lower(): '{text.lower()}'")
print(f"replace('World', 'Python'): '{text.replace('World', 'Python')}'")
print()

# Checking string content
print("=== STRING CHECKING ===")
line = "TEMP=72.5F"
print(f"'{line}'.startswith('TEMP'): {line.startswith('TEMP')}")
print(f"'{line}'.endswith('F'): {line.endswith('F')}")
print(f"'{line}'.isdigit(): {line.isdigit()}")
print("'12345'.isdigit():", '12345'.isdigit())
print()

# Splitting and joining
print("=== SPLITTING AND JOINING ===")
line = "TEMP 72.5 F"
parts = line.split()
print(f"'{line}'.split(): {parts}")

sentence = "Python is awesome"
words = sentence.split()
print(f"'{sentence}'.split(): {words}")

joined = "-".join(words)
print(f"'-'.join({words}): '{joined}'")
print()

# String formatting
print("=== STRING FORMATTING ===")
name = "Alice"
age = 25
score = 95.5

# f-strings (modern, preferred)
print(f"Name: {name}, Age: {age}, Score: {score:.1f}")

# .format() method
print("Name: {}, Age: {}, Score: {:.1f}".format(name, age, score))

# Format with alignment
print(f"'{name:>10}' (right-aligned)")
print(f"'{name:<10}' (left-aligned)")
print(f"'{name:^10}' (centered)")
print()

# Extracting data from structured text
print("=== EXTRACTING DATA FROM TEXT ===")
# Common engineering pattern: parse structured text
sensor_data = [
    "TEMP 72.5 F",
    "VOLTAGE 4.98 V",
    "CURRENT 2.5 A"
]

print("Parsing sensor readings:")
for line in sensor_data:
    parts = line.strip().split()
    sensor = parts[0]
    value = float(parts[1])
    unit = parts[2]
    print(f"  {sensor}: {value:.2f} {unit}")
print()

# Finding and locating substrings
print("=== FINDING SUBSTRINGS ===")
text = "The quick brown fox"
print(f"'{text}'.find('brown'): {text.find('brown')}")
print(f"'{text}'.find('zebra'): {text.find('zebra')}")  # Returns -1 if not found
print(f"'fox' in '{text}': {'fox' in text}")
print(f"'zebra' in '{text}': {'zebra' in text}")
print()

# String slicing and subsequences
print("=== STRING SLICING ===")
code = "ERROR404"
print(f"'{code}'[5:]: '{code[5:]}'")  # Extract error code
print(f"'{code}'.find('404'): {code.find('404')}")

filename = "data_2025_01_15.csv"
parts = filename.split('_')
print(f"Filename parts: {parts}")
print(f"Year: {parts[1]}, Month: {parts[2]}, Day: {parts[3]}")
