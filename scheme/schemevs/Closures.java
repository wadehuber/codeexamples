// Closures & currying in Java - methods that RETURN functions
// Compile & run:  javac Closures.java && java Closures

import java.util.List;
import java.util.function.Function;
import java.util.function.Predicate;

public class Closures {

    // make-adder: returns a new function each time it is called
    static Function<Integer, Integer> makeAdder(int n) {
        return x -> x + n;          // the lambda "captures" n
    }

    static boolean validNumber(int n, int x, int y) {
        return n >= x && n <= y;
    }

    // Partial application: fix the range now, supply n later
    // (the course notes call this currying - see closures.scm)
    static Predicate<Integer> validNumberCurr(int x, int y) {
        return n -> validNumber(n, x, y);
    }

    public static void main(String[] args) {
        System.out.println("makeAdder - returns a new function each time it is called");
        Function<Integer, Integer> add5 = makeAdder(5);
        Function<Integer, Integer> add100 = makeAdder(100);
        System.out.println(add5.apply(10));
        System.out.println(add100.apply(10));
        System.out.println(makeAdder(3).apply(4));
        System.out.println(List.of(1, 2, 3).stream().map(makeAdder(1)).toList());

        System.out.println();
        System.out.println("Fully curried - a function that returns a function, as a VALUE");
        Function<Integer, Function<Integer, Integer>> add = a -> b -> a + b;
        System.out.println(add.apply(3).apply(4));

        System.out.println();
        System.out.println("Partial application - filter a list for numbers in a range");
        List<Integer> nums = List.of(-10, -5, 0, 5, 10, 15, 20, 25, 30);
        System.out.println(nums.stream().filter(validNumberCurr(0, 20)).toList());
        System.out.println(nums.stream().filter(validNumberCurr(-5, 5)).toList());

        System.out.println();
        System.out.println("compose - combine two functions into a new one");
        Function<Integer, Integer> square = x -> x * x;
        Function<Integer, Integer> squareThenAdd5 = add5.compose(square);   // add5(square(x))
        System.out.println(squareThenAdd5.apply(3));

        System.out.println();
        System.out.println("A Java restriction: captured local variables must be effectively final");
        int counter = 0;
        // Function<Integer, Integer> bad = x -> x + counter++;   // will not compile
        Function<Integer, Integer> ok = x -> x + counter;          // reading is fine
        System.out.println(ok.apply(10));

        System.out.println();
        System.out.println("...but that does NOT make the lambda pure");
        int[] box = {0};                     // the VARIABLE box is effectively final,
        Function<Integer, Integer> sneaky = x -> x + ++box[0];   // the ARRAY is not
        System.out.println(sneaky.apply(10));   // 11
        System.out.println(sneaky.apply(10));   // 12 - same input, different output
    }
}
