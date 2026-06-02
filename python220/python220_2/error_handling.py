"""Error handling with try and except for robust scripts"""

print("=== BASIC TRY/EXCEPT ===")
text = "abc"
try:
    value = float(text)
    print(f"Converted: {value}")
except ValueError:
    print(f"Could not convert '{text}' to a number")
print()

print("=== HANDLING MULTIPLE EXCEPTION TYPES ===")
def safe_operation(operation, a, b):
    """Safely perform a mathematical operation"""
    try:
        if operation == "add":
            return a + b
        elif operation == "divide":
            return a / b
        else:
            raise ValueError(f"Unknown operation: {operation}")
    except ZeroDivisionError:
        print(f"  Error: Cannot divide by zero")
        return None
    except TypeError:
        print(f"  Error: Invalid types for operation")
        return None
    except ValueError as e:
        print(f"  Error: {e}")
        return None

print("10 + 5 =", safe_operation("add", 10, 5))
print("10 / 0 =", safe_operation("divide", 10, 0))
print("10 / '5' =", safe_operation("divide", 10, "5"))
print('"multiply" is invalid:', safe_operation("multiply", 10, 5))
print()

print("=== HANDLING FILE ERRORS ===")
# Create a test file
with open("test_file.txt", "w") as f:
    f.write("sample data")

# Try to read it
filename = "test_file.txt"
try:
    with open(filename) as f:
        contents = f.read()
    print(f"✓ Successfully read {filename}")
except FileNotFoundError:
    print(f"✗ File not found: {filename}")
except IOError:
    print(f"✗ Could not read file: {filename}")

# Try to read a nonexistent file
filename = "missing.txt"
try:
    with open(filename) as f:
        contents = f.read()
except FileNotFoundError:
    print(f"✗ File not found: {filename}")
print()

print("=== HANDLING BAD DATA IN LOOPS ===")
# Process a list with some invalid values
sensor_readings = ["72.5", "73.1", "bad-data", "74.0", "ERROR"]

total = 0
count = 0
errors = 0

print("Processing sensor readings:")
for reading in sensor_readings:
    try:
        value = float(reading)
        total += value
        count += 1
        print(f"  ✓ {reading} -> {value}")
    except ValueError:
        errors += 1
        print(f"  ✗ Skipping invalid reading: {reading}")

if count > 0:
    average = total / count
    print(f"Average of {count} readings: {average:.2f}")
    if errors > 0:
        print(f"Skipped {errors} invalid readings")
print()

print("=== USING ELSE AND FINALLY ===")
def process_file(filename):
    """Demonstrate else and finally clauses"""
    try:
        with open(filename) as f:
            lines = f.readlines()
    except FileNotFoundError:
        print(f"File not found: {filename}")
    except IOError as e:
        print(f"Error reading file: {e}")
    else:
        # This runs if no exception occurred
        print(f"✓ Successfully read {len(lines)} lines")
    finally:
        # This always runs
        print("File operation complete\n")

process_file("test_file.txt")
process_file("nonexistent.txt")

print("=== RAISING CUSTOM EXCEPTIONS ===")
def validate_sensor_reading(sensor_type, value):
    """Validate a sensor reading"""
    if sensor_type not in ["TEMP", "VOLTAGE", "CURRENT"]:
        raise ValueError(f"Unknown sensor type: {sensor_type}")
    if not isinstance(value, (int, float)):
        raise TypeError(f"Value must be numeric, got {type(value)}")
    if value < 0:
        raise ValueError(f"Sensor value cannot be negative: {value}")
    return True

print("Validating sensor readings:")
test_cases = [
    ("TEMP", 72.5),
    ("VOLTAGE", 4.98),
    ("TEMP", -10),
    ("HUMIDITY", 50),
    ("CURRENT", "5A")
]

for sensor, value in test_cases:
    try:
        validate_sensor_reading(sensor, value)
        print(f"  ✓ {sensor}: {value}")
    except ValueError as e:
        print(f"  ✗ {e}")
    except TypeError as e:
        print(f"  ✗ {e}")
print()

print("=== EXCEPTION CHAINING ===")
def convert_and_scale(text, scale_factor):
    """Convert text to number and scale it"""
    try:
        value = float(text)
    except ValueError as e:
        raise ValueError(f"Cannot convert '{text}' to number") from e

    try:
        scaled = value * scale_factor
    except TypeError as e:
        raise TypeError(f"Cannot scale by {scale_factor}") from e

    return scaled

print("Testing conversion and scaling:")
try:
    result = convert_and_scale("25.5", 2)
    print(f"  ✓ Result: {result}")
except Exception as e:
    print(f"  ✗ Error: {e}")

try:
    result = convert_and_scale("invalid", 2)
except ValueError as e:
    print(f"  ✗ Error: {e}")
print()

# Cleanup
import os
if os.path.exists("test_file.txt"):
    os.remove("test_file.txt")
