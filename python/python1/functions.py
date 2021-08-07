''' Writing functions in Python '''

def say_hello() :
    ''' Function with no return '''
    print("Hello!")

def add_ten(xparm) :
    ''' Function that returns a value '''
    return xparm + 10

def add_twenty(xparm) :
    ''' Function that modifies a parameter '''
    xparm = xparm + 20

def add_array(arr) :
    ''' Function that sums a list '''
    total = 0
    for value in arr:
        total += value
    return total

def enumerate_array(arr) :
    ''' Function that prints index/value pairs of a list '''
    for index, value in enumerate(arr):
        print("[{}] = {}".format(index, value))

def main() :
    ''' Main method for the module '''
    aval = 5
    bval = 0
    arr = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]

    say_hello()
    print("a={}, b={}".format(aval, bval))
    print("add_ten(a)={}, add_ten(b)={}".format(add_ten(aval), add_ten(bval)))
    print("a={}, b={}".format(aval, bval))
    print("add_twenty(b)")
    add_twenty(bval)
    print("a={}, b={}".format(aval, bval))
    print("add_ten(a)={}, add_ten(b)={}".format(add_ten(aval), add_ten(bval)))
    print("a={}, b={}".format(aval, bval))

    print("arr: {}".format(arr))

    print("add_array(arr)={}".format(add_array(arr)))
    print("enumerate_array(arr):")
    format(enumerate_array(arr))

# This code checks to see if this module is being run (versus imported).  If so, it calls main
if __name__ == '__main__' :
    main()
