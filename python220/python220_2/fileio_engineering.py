"""File I/O operations for engineering scripts"""

import os

print("=== WRITING FILES ===")
# Write text to a file
filename = "output.txt"
lines = [
    "Engineering Log",
    "===============",
    "System started at 10:00",
    "Configuration loaded",
    "Ready for operation"
]

with open(filename, "w") as f:
    for line in lines:
        f.write(line + "\n")

print(f"✓ Wrote {len(lines)} lines to {filename}")
print()

print("=== READING FILES ===")
print(f"Reading {filename}:")
with open(filename) as f:
    for line in f:
        print(f"  {line.rstrip()}")
print()

print("=== READING ENTIRE FILE ===")
with open(filename) as f:
    contents = f.read()
print(f"File contents ({len(contents)} chars):")
print(contents)
print()

print("=== PROCESSING LINE BY LINE ===")
# Create a file with sensor data
sensor_file = "readings.txt"
with open(sensor_file, "w") as f:
    f.write("72.5\n73.1\n71.8\n74.2\n")

print(f"Processing {sensor_file}:")
total = 0
count = 0
with open(sensor_file) as f:
    for line in f:
        line = line.strip()
        if line:  # Skip empty lines
            value = float(line)
            total += value
            count += 1

if count > 0:
    average = total / count
    print(f"  Average of {count} readings: {average:.2f}")
print()

print("=== APPENDING TO FILES ===")
log_file = "system.log"

# Create initial log
with open(log_file, "w") as f:
    f.write("System started\n")

# Append events
events = ["Configuration loaded", "Test passed", "Ready"]
with open(log_file, "a") as f:
    for event in events:
        f.write(f"{event}\n")

print(f"✓ Appended {len(events)} events to {log_file}")
print(f"Content of {log_file}:")
with open(log_file) as f:
    for line in f:
        print(f"  {line.rstrip()}")
print()

print("=== FILTERING FILE CONTENT ===")
# Create a file with mixed content
data_file = "data.txt"
with open(data_file, "w") as f:
    f.write("""INFO: system initialized
WARNING: low memory
INFO: loading configuration
ERROR: file not found
INFO: operation complete""")

print(f"Extracting log levels from {data_file}:")
levels = {"INFO": 0, "WARNING": 0, "ERROR": 0}

with open(data_file) as f:
    for line in f:
        line = line.strip()
        for level in levels:
            if line.startswith(level):
                levels[level] += 1
                break

for level, count in sorted(levels.items()):
    if count > 0:
        print(f"  {level}: {count}")
print()

print("=== PROCESSING STRUCTURED DATA ===")
# File with structured fields
structured_file = "sensors.txt"
with open(structured_file, "w") as f:
    f.write("""SENSOR001 TEMP 72.5
SENSOR002 VOLTAGE 4.98
SENSOR001 TEMP 73.1
SENSOR003 CURRENT 2.5""")

print(f"Processing structured data from {structured_file}:")
readings_by_sensor = {}

with open(structured_file) as f:
    for line in f:
        parts = line.strip().split()
        sensor_id = parts[0]
        sensor_type = parts[1]
        value = float(parts[2])

        if sensor_id not in readings_by_sensor:
            readings_by_sensor[sensor_id] = []
        readings_by_sensor[sensor_id].append((sensor_type, value))

for sensor_id, readings in sorted(readings_by_sensor.items()):
    print(f"  {sensor_id}: {len(readings)} reading(s)")
    for sensor_type, value in readings:
        print(f"    {sensor_type}: {value}")
print()

print("=== FILE INFORMATION ===")
import os

for fname in [filename, sensor_file, log_file, data_file, structured_file]:
    if os.path.exists(fname):
        size = os.path.getsize(fname)
        print(f"  {fname}: {size} bytes")
print()

print("=== WORKING WITH DIRECTORIES ===")
# List Python files in current directory
print("Python files in current directory:")
for fname in os.listdir("."):
    if fname.endswith(".py"):
        print(f"  {fname}")
print()

print("=== CLEANUP ===")
for fname in [filename, sensor_file, log_file, data_file, structured_file]:
    if os.path.exists(fname):
        os.remove(fname)
        print(f"✓ Removed {fname}")
