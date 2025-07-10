"""
  advancedfunctions.py

  This file contains simple functions that demonstrate the use of positional
  and keyword arguments, as well as variable-length argument lists.
"""

def greet(name, /, greeting="Hello"):
    """Greet a person with a message.

    Args:
        name (str): The name of the person.
        greeting (str, optional): The greeting message. Defaults to "Hello".

    Returns:
        str: The formatted greeting message.
    """

    return f"{greeting}, {name}!"

def stats(*nums):
    """Calculate basic statistics for a set of numbers.

    Returns:
        tuple: A tuple containing the minimum, maximum, and average of the numbers.
    """
    if not nums:
        return None, None, None

    return min(nums), max(nums), sum(nums) / len(nums)

print(greet("Leia"))
print(greet("Luke", "Use the Force"))
print(greet("Han", "Never tell me the odds"))
print(stats(7))
print(stats(10, 20, 30, 40))
