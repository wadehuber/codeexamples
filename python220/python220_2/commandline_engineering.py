"""Command-line arguments for engineering scripts"""

import sys
from pathlib import Path

print("=== COMMAND-LINE ARGUMENTS ===")
print("This script demonstrates how to accept command-line arguments.")
print()

print("Script name (sys.argv[0]):", sys.argv[0])
print("Total arguments:", len(sys.argv))
print("All arguments:", sys.argv)
print()

print("=== SIMPLE ARGUMENT PROCESSING ===")
# Example: script that requires a filename argument
print("Usage example: python commandline_engineering.py <filename>")

if len(sys.argv) > 1:
    provided_file = sys.argv[1]
    print(f"You provided: {provided_file}")
else:
    print("No filename provided (but this script works without it for demo)")
print()

print("=== MULTIPLE ARGUMENTS ===")
print("Usage example: python script.py <input> <output> <mode>")

if len(sys.argv) >= 4:
    input_file = sys.argv[1]
    output_file = sys.argv[2]
    mode = sys.argv[3]
    print(f"  Input: {input_file}")
    print(f"  Output: {output_file}")
    print(f"  Mode: {mode}")
else:
    print("Not enough arguments provided (needs 3), but example shown above")
print()

print("=== OPTIONAL ARGUMENTS ===")
# Example with optional arguments
print("Usage: python script.py <input_file> [--verbose] [--output FILE]")

input_file = None
verbose = False
output_file = None

for i, arg in enumerate(sys.argv[1:], 1):
    if arg == "--verbose":
        verbose = True
    elif arg == "--output" and i < len(sys.argv) - 1:
        output_file = sys.argv[i + 1]
    elif not arg.startswith("--"):
        input_file = arg

print(f"  Input file: {input_file}")
print(f"  Verbose mode: {verbose}")
print(f"  Output file: {output_file}")
print()

print("=== DEMONSTRATING COMMON PATTERNS ===")

# Pattern 1: Script that requires a file
print("Pattern 1 - Script with required file argument:")
print("""
if len(sys.argv) != 2:
    print("Usage: python analyze.py <filename>")
    sys.exit(1)

filename = sys.argv[1]
try:
    with open(filename) as f:
        data = f.read()
except FileNotFoundError:
    print(f"Error: File not found: {filename}")
    sys.exit(1)
""")
print()

# Pattern 2: Script with optional arguments
print("Pattern 2 - Script with optional flags:")
print("""
import sys

verbose = "--verbose" in sys.argv
quiet = "--quiet" in sys.argv

if "--version" in sys.argv:
    print("v1.0")
    sys.exit(0)

# Rest of script...
""")
print()

# Pattern 3: Using argparse (more sophisticated)
print("Pattern 3 - Using argparse module (recommended):")
print("""
import argparse

parser = argparse.ArgumentParser(description='Process sensor data')
parser.add_argument('input', help='Input file path')
parser.add_argument('--output', help='Output file path')
parser.add_argument('--verbose', action='store_true')
parser.add_argument('--threshold', type=float, default=100.0)

args = parser.parse_args()

# Access as: args.input, args.output, args.verbose, args.threshold
""")
print()

print("=== EXAMPLE: LOG FILE ANALYZER ===")
print("""
# log_analyzer.py - accepts a log file as argument

import sys

if len(sys.argv) != 2:
    print("Usage: python log_analyzer.py <logfile>")
    sys.exit(1)

logfile = sys.argv[1]

counts = {}
with open(logfile) as f:
    for line in f:
        if line.strip():
            level = line.split()[0]
            counts[level] = counts.get(level, 0) + 1

print("Log Summary")
print("-" * 30)
for level, count in sorted(counts.items()):
    print(f"{level}: {count}")

# Run with: python log_analyzer.py system.log
""")
print()

print("=== EXAMPLE: UNIT CONVERTER ===")
print("""
# converter.py - converts temperatures

import sys

if len(sys.argv) != 3:
    print("Usage: python converter.py <value> <from-to>")
    print("Example: python converter.py 72.5 F-to-C")
    sys.exit(1)

value = float(sys.argv[1])
conversion = sys.argv[2]

if conversion == "F-to-C":
    result = (value - 32) * 5 / 9
    unit = "°C"
elif conversion == "C-to-F":
    result = value * 9 / 5 + 32
    unit = "°F"
else:
    print(f"Unknown conversion: {conversion}")
    sys.exit(1)

print(f"{value} {conversion} = {result:.1f} {unit}")

# Run with: python converter.py 72 F-to-C
""")
