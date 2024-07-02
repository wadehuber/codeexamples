'''Python lists'''

a = [1, 2, 3, 4]
b = [2.4, 3.14, 9.99999]

array = []
for ii in range(10):
    array.append(ii * 100)

print("Array a (size={}): {}".format(len(a),a))
print("Array b (size={}): {}".format(len(b),b))
print("Array array (size={}): {}".format(len(array),array))

# Iterating through an array:
total = 0
for value in a:
    total += value
print("The sum of {} is {}".format(a, total))
