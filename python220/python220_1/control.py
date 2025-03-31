''' Example of python control structures '''

a = 5

b = int(input("Enter an integer: "))

# If-then-else statement
if a < b:
    print('{} is less than {}'.format(a,b))
elif a > b:
    print('{} is greater than {}'.format(a,b))
else:
    print('{} is equal to {}'.format(a,b))

# While loop
ii = 0
print("While loop:")
while ii <= b:
    print(  "Your number = {}, loop variable = {}".format(b,ii))
    ii+=1

# For loop
print("For loop:")
for ii in range(b):
    print("  for:  loop variable = {}".format(ii))

print("Iterate over a list:")
for ss in ['This is', 'a list', 'of strings']:
    print(ss)

# break & continue
for ii in range(100000):
    if ii > b:
        print("Breaking at {}".format(ii))
        break

print("Continue if not divisible by 3:")
for ii in range(b+1):
    if not (ii % 3) == 0:
        continue
    print("  {}".format(ii))
