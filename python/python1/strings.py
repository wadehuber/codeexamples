'''Examples of working with strings in Python'''

STR1 = "Hello"
STR2 = ['W', 'o', 'r', 'l', 'd']      # List of
STR3 = "".join(['e', 'n', 'd', '.'])  # Create a list by joining a list of characters together
STR4 = "This is a really long string.  Maybe too long?"

print("str1 = {} length={}".format(STR1, len(STR1)))
print("str2 = {} length={}".format(STR2, len(STR2)))
print("str3 = {} length={}".format(STR3, len(STR3)))
print("str4 = {} length={}".format(STR4, len(STR4)))

print("String 1 character by character: ")
for char in STR1:
    print("  {}".format(char))

print("String 3 ASCII values: ")
for char in STR1:
    print("  {} (ASCII={})".format(char, ord(char)))

#appending a string
STR5 = STR1 + " " + "".join(STR2) + "!"
print(STR5)

# more string functions
print(STR4.upper())
print(STR4.lower())
