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

    // Curried version: fix the range now, supply n later
    static Predicate<Integer> validNumberCurr(int x, int y) {
        return n -> validNumber(n, x, y);
    }

    // quad: returns a polynomial function f(x) = ax^2 + bx + c
    static Function<Double, Double> quad(double a, double b, double c) {
        return x -> a * x * x + b * x + c;
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
        System.out.println("Currying - filter a list for numbers in a range");
        List<Integer> nums = List.of(-10, -5, 0, 5, 10, 15, 20, 25, 30);
        System.out.println(nums.stream().filter(validNumberCurr(0, 20)).toList());
        System.out.println(nums.stream().filter(validNumberCurr(-5, 5)).toList());

        System.out.println();
        System.out.println("Generating polynomial functions");
        Function<Double, Double> f1 = quad(1, 2, 3);
        Function<Double, Double> f2 = quad(2, 0, -8);
        System.out.println(f1.apply(2.0));
        System.out.println(f2.apply(2.0));
        System.out.println(List.of(0.0, 1.0, 2.0, 3.0, 4.0).stream().map(f1).toList());

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
    }
}
