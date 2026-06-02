"""Working with CSV (Comma-Separated Values) files"""

import csv
import os

print("=== READING CSV FILES ===")
# Example: reading sensor data
csv_content = """sensor,value,unit,timestamp
TEMP,72.5,F,2025-01-15 10:30
VOLTAGE,4.98,V,2025-01-15 10:31
CURRENT,2.5,A,2025-01-15 10:32
TEMP,73.1,F,2025-01-15 10:33
VOLTAGE,5.01,V,2025-01-15 10:34"""

# Create a sample file for demonstration
filename = "sensor_data.csv"
with open(filename, "w") as f:
    f.write(csv_content)

print(f"Reading from {filename}:")
with open(filename) as csvfile:
    reader = csv.reader(csvfile)
    for row in reader:
        print(f"  {row}")
print()

print("=== READING CSV WITH HEADERS (DictReader) ===")
# Using DictReader for cleaner access to columns
with open(filename) as csvfile:
    reader = csv.DictReader(csvfile)
    for row in reader:
        sensor = row['sensor']
        value = float(row['value'])
        unit = row['unit']
        print(f"  {sensor}: {value} {unit}")
print()

print("=== FILTERING CSV DATA ===")
# Extract only TEMP readings
temperatures = []
with open(filename) as csvfile:
    reader = csv.DictReader(csvfile)
    for row in reader:
        if row['sensor'] == 'TEMP':
            temperatures.append(float(row['value']))

print(f"Temperature readings: {temperatures}")
if temperatures:
    avg_temp = sum(temperatures) / len(temperatures)
    print(f"Average temperature: {avg_temp:.1f}°F")
print()

print("=== WRITING CSV FILES ===")
# Create a new CSV file with processed data
output_filename = "summary.csv"

# Process the data
summary_data = []
with open(filename) as csvfile:
    reader = csv.DictReader(csvfile)
    for row in reader:
        summary_data.append({
            'sensor': row['sensor'],
            'value': float(row['value']),
            'unit': row['unit']
        })

# Write summary (could be filtered, processed, etc.)
with open(output_filename, "w", newline='') as csvfile:
    fieldnames = ['sensor', 'value', 'unit']
    writer = csv.DictWriter(csvfile, fieldnames=fieldnames)

    writer.writeheader()
    for row in summary_data:
        writer.writerow(row)

print(f"Wrote summary to {output_filename}")
print()

print("=== AGGREGATING CSV DATA ===")
# Count readings by sensor type
from collections import defaultdict

sensor_counts = defaultdict(int)
with open(filename) as csvfile:
    reader = csv.DictReader(csvfile)
    for row in reader:
        sensor_counts[row['sensor']] += 1

print("Reading counts by sensor:")
for sensor, count in sorted(sensor_counts.items()):
    print(f"  {sensor}: {count} readings")
print()

print("=== HANDLING DIFFERENT FORMATS ===")
# CSV files can use different delimiters

# Semicolon-delimited
semicolon_data = """name;age;department
Alice;25;Engineering
Bob;30;Sales
Charlie;28;Engineering"""

semicolon_file = "semicolon.csv"
with open(semicolon_file, "w") as f:
    f.write(semicolon_data)

print(f"Reading semicolon-delimited file:")
with open(semicolon_file) as csvfile:
    reader = csv.DictReader(csvfile, delimiter=';')
    for row in reader:
        print(f"  {row['name']:10} - {row['department']}")
print()

print("=== TAB-DELIMITED FILES ===")
tab_data = "name\tvalue\tstatus\nSensor1\t42.5\tOK\nSensor2\t38.2\tOK\nSensor3\t-1.0\tERROR"

tab_file = "tab_delimited.tsv"
with open(tab_file, "w") as f:
    f.write(tab_data)

print(f"Reading tab-delimited file:")
with open(tab_file) as csvfile:
    reader = csv.DictReader(csvfile, delimiter='\t')
    for row in reader:
        status_symbol = "✓" if row['status'] == 'OK' else "✗"
        print(f"  {status_symbol} {row['name']:10} = {row['value']}")
print()

# Cleanup
print("=== CLEANUP ===")
for fname in [filename, output_filename, semicolon_file, tab_file]:
    if os.path.exists(fname):
        os.remove(fname)
        print(f"Removed {fname}")
