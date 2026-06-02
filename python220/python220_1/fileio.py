import argparse, sys, statistics, pathlib

def read_numbers(path):
    with open(path) as f:
        for line in f:
            if line.strip():      # skip blanks
                yield float(line)

def main():
    parser = argparse.ArgumentParser(
        description="Compute basic stats for a list of numbers."
    )
    parser.add_argument("file", type=pathlib.Path,
                        help="Text file with one number per line")
    parser.add_argument("--fahrenheit", action="store_true",
                        help="Treat numbers as °F instead of °C")
    args = parser.parse_args()

    nums = list(read_numbers(args.file))
    if args.fahrenheit:           # quick unit conversion demo
        nums = [(n - 32) * 5/9 for n in nums]

    print("min =", min(nums))
    print("max =", max(nums))
    print("avg =", statistics.mean(nums))

if __name__ == "__main__":
    main()