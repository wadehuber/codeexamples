"""
File: exceptions.py

This file demonstrates how to handle exceptions in Python.
It includes examples of catching specific exceptions and using
the `raise` statement to propagate exceptions with additional context.
"""
def safe_divide(a, b):
    """
    Safely divide two numbers.

    Args:
        a (int): The numerator.
        b (int): The denominator.

    Raises:
        ValueError: If the denominator is zero.

    Returns:
        float: The result of the division.
    """
    try:
        return a / b
    except ZeroDivisionError as e:
        raise ValueError("Cannot divide by zero") from e

try:
    print(safe_divide(10, 0))
except ValueError as err:
    print("ERROR:", err)
