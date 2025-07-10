"""
This module contains various recursive functions including:
- A naive Fibonacci implementation
- A tail-recursive Fibonacci implementation
- A function to recursively find an element in an array

"""


def fib(n):
    """Naive Fibonacci implementation"""
    if n <= 1:
        return n
    return fib(n - 2) + fib(n - 1)


def fib_tail(n):
    """Tail-recursive Fibonacci implementation"""
    return fib_tail_helper(n, 1, 1)


def fib_tail_helper(n, f2, f1):
    """Helper function for tail-recursive Fibonacci implementation"""
    if n <= 2:
        return f1
    return fib_tail_helper(n - 1, f1, f1 + f2)


def find_in_array(arr, target):
    """Recursively find an element in an array"""
    if not arr:
        return False
    if target == arr[0]:
        return True
    return find_in_array(arr[1:], target)


def main():
    """Main function"""
    k = [-2, 0, 2, 4, 6, 8, 10, 9, 7, 5, 3, 1, -1, -3]

    print()
    print("Testing fib:")
    for value in range(10):
        print(f"    fib({value})={fib(value)}")

    print()
    print("Testing fib_tail:")
    for value in [1, 2, 3, 4, 5, 7, 10, 20, 50, 100]:
        print(f"    fib_tail({value})={fib_tail(value)}")

    print()
    print("Testing search_value:")
    for search_value in [3, -2, -1, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, -4]:
        if find_in_array(k, search_value):
            print(f"    {search_value} is found in array")
        else:
            print(f"    {search_value} NOT found in array")


if __name__ == "__main__":
    main()
