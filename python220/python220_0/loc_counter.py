import os
import sys

def count_lines(filepath):
    """Count total, code, comment, and blank lines in a Python file."""
    try:
        with open(filepath, 'r', encoding='utf-8', errors='ignore') as f:
            lines = f.readlines()
    except Exception as e:
        print(f"  Error reading {filepath}: {e}")
        return None

    total = len(lines)
    blank = sum(1 for line in lines if line.strip() == '')
    comment = sum(1 for line in lines if line.strip().startswith('#'))
    code = total - blank - comment

    return {'total': total, 'code': code, 'comment': comment, 'blank': blank}

def analyze_directory(directory):
    """Recursively analyze all Python files in a directory."""
    if not os.path.isdir(directory):
        print(f"Error: '{directory}' is not a valid directory")
        return

    totals = {'total': 0, 'code': 0, 'comment': 0, 'blank': 0}
    file_count = 0

    for root, dirs, files in os.walk(directory):
        for filename in files:
            if filename.endswith('.py'):
                filepath = os.path.join(root, filename)
                stats = count_lines(filepath)

                if stats:
                    file_count += 1
                    for key in totals:
                        totals[key] += stats[key]

    # Display results
    print(f"\nPython Files Analysis: {directory}")
    print("-" * 50)
    print(f"Files analyzed: {file_count}")
    print(f"Total lines: {totals['total']}")
    print(f"Code lines: {totals['code']}")
    print(f"Comment lines: {totals['comment']}")
    print(f"Blank lines: {totals['blank']}")

if __name__ == "__main__":
    # Use provided directory or current directory
    target_dir = sys.argv[1] if len(sys.argv) > 1 else '.'
    analyze_directory(target_dir)
