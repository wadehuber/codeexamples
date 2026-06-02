"""Regular expressions for pattern matching and text extraction"""

import re

print("=== BASIC PATTERN MATCHING ===")
text = "The temperature is 72.5 degrees"

# Search for a pattern
match = re.search(r"temperature is (\d+\.\d+)", text)
if match:
    value = match.group(1)
    print(f"Found temperature: {value}")
print()

# Pattern explanation:
# \d = digit
# \. = literal dot
# \d+ = one or more digits
# (\d+\.\d+) = group capturing the number

print("=== EXTRACTING NUMBERS ===")
lines = [
    "TEMP=72.5F",
    "VOLTAGE=4.98V",
    "ERROR 404: device not found"
]

for line in lines:
    # Extract number from various formats
    match = re.search(r"(\d+\.?\d*)", line)
    if match:
        number = float(match.group(1))
        print(f"{line:30} -> {number}")
print()

# Extracting error codes
print("=== EXTRACTING ERROR CODES ===")
error_lines = [
    "ERROR 404: page not found",
    "ERROR 500: internal server error",
    "WARNING 201: resource created"
]

for line in error_lines:
    match = re.search(r"([A-Z]+) (\d+):", line)
    if match:
        level = match.group(1)
        code = int(match.group(2))
        print(f"Level: {level}, Code: {code}")
print()

# Pattern explanation:
# ([A-Z]+) = group capturing one or more uppercase letters
# (\d+) = group capturing one or more digits
# : = literal colon

print("=== EMAIL VALIDATION ===")
emails = [
    "user@example.com",
    "invalid.email@",
    "test.user+tag@company.org",
    "noatsign"
]

email_pattern = r"^[a-zA-Z0-9._+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,}$"

for email in emails:
    if re.match(email_pattern, email):
        print(f"✓ {email}")
    else:
        print(f"✗ {email}")
print()

# Pattern explanation:
# ^ = start of string
# [a-zA-Z0-9._+-]+ = valid username characters
# @ = literal @
# [a-zA-Z0-9.-]+ = valid domain characters
# \. = literal dot
# [a-zA-Z]{2,} = at least 2 letters for TLD
# $ = end of string

print("=== FINDING ALL MATCHES ===")
log_text = "INFO started at 10:30, WARNING issued at 10:35, ERROR at 10:40"

# Find all timestamps
times = re.findall(r"\d{2}:\d{2}", log_text)
print(f"Times found: {times}")

# Find all log levels
levels = re.findall(r"(INFO|WARNING|ERROR)", log_text)
print(f"Log levels: {levels}")
print()

# Pattern explanation:
# \d{2} = exactly 2 digits
# (INFO|WARNING|ERROR) = group matching one of these words

print("=== REPLACING WITH PATTERNS ===")
data = "2025-01-15 sensor data"

# Replace date format
result = re.sub(r"(\d{4})-(\d{2})-(\d{2})", r"\3/\2/\1", data)
print(f"Original: {data}")
print(f"Reformatted: {result}")

# Remove spaces
result = re.sub(r"\s+", "", data)
print(f"No spaces: {result}")
print()

# Pattern explanation:
# (\d{4})-(\d{2})-(\d{2}) = groups for year-month-day
# r"\3/\2/\1" = reorder to day/month/year
# \s+ = one or more whitespace characters

print("=== SPLITTING WITH PATTERNS ===")
text = "apple, banana; orange | grape"

# Split on multiple delimiters
parts = re.split(r"[,;|]", text)
print(f"Original: {text}")
print(f"Split parts: {parts}")

# Clean up whitespace
parts = [p.strip() for p in parts]
print(f"Cleaned: {parts}")
