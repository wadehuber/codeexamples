""" Recursion examples in Python
"""

def find_in_array(arr, target) :
    """ Check if target exists in arr """
    if not arr:
        return False
    if target == arr[0]:
        return True
    return find_in_array(arr[1:], target)

k = [-2, 0, 2,4,6,8,10,9,7,5,3,1,-1,-3]

print(find_in_array(k, -3))
print(find_in_array(k, -2))
print(find_in_array(k, -1))
print(find_in_array(k, 0))
print(find_in_array(k, 1))
print(find_in_array(k, 2))
print(find_in_array(k, 3))
print(find_in_array(k, 4))
print(find_in_array(k, 5))
print(find_in_array(k, 6))
print(find_in_array(k, 7))
print(find_in_array(k, 8))
print(find_in_array(k, 9))
print(find_in_array(k, 10))
print(find_in_array(k, 11))
print(find_in_array(k, 12))
print(find_in_array(k, -4))
