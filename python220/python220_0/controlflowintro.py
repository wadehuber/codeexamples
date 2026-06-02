n = 7                    # dynamic typing: no type declarations
parity = "even" if n % 2 == 0 else "odd"
print(f"{n} is {parity}")

total = 0
for i in range(1, n + 1):
    total += i
print("sum 1..n =", total)

while n > 0:
    n -= 2
    print("n is now", n)
