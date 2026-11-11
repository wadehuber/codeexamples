// Higher-order functions in Java - lambdas, functional interfaces, and streams (Java 8+)
// Compile & run:  javac HigherOrder.java && java HigherOrder

import java.util.ArrayList;
import java.util.List;
import java.util.function.Function;
import java.util.function.UnaryOperator;

public class HigherOrder {

    public static void main(String[] args) {
        List<Integer> lst = List.of(-4, 7, -2, 5, 10, -8, 3);
        Function<Integer, Integer> square = x -> x * x;    // a function stored in a variable

        System.out.println("map - apply a function to every element");
        System.out.println(lst.stream().map(square).toList());
        System.out.println(lst.stream().map(Math::abs).toList());       // method reference
        System.out.println(lst.stream().map(x -> x * 10).toList());     // lambda made on the spot

        System.out.println();
        System.out.println("filter - keep only the elements that pass a test");
        System.out.println(lst.stream().filter(x -> x > 0).toList());
        System.out.println(lst.stream().filter(x -> x % 2 == 0).toList());
        System.out.println(lst.stream().filter(x -> x > 4).toList());

        System.out.println();
        System.out.println("reduce - combine all elements into one value");
        System.out.println(lst.stream().reduce(0, Integer::sum));          // sum
        System.out.println(lst.stream().reduce(lst.get(0), Math::max));    // largest value
        // reduce calls f(total, element) and REQUIRES an associative function such as
        // + or max. Subtraction is not associative, so it does not belong in reduce.

        System.out.println();
        System.out.println("Imperative version - sum of squares of the positive numbers");
        System.out.println(sumPosSquaresLoop(lst));

        System.out.println("Functional version - filter -> map -> reduce");
        System.out.println(sumPosSquares(lst));
        System.out.println(sumPosSquares(List.of(1, 2, 3)));

        System.out.println();
        System.out.println("Functions are values - store them in a list");
        List<Function<Integer, Integer>> operations =
                List.of(square, Math::abs, x -> x + 100);
        List<Integer> results = new ArrayList<>();
        for (Function<Integer, Integer> op : operations) {
            results.add(op.apply(-5));                    // note: op.apply(x), not op(x)
        }
        System.out.println(results);

        System.out.println();
        System.out.println("Writing our own higher-order function");
        System.out.println(applyTwice(x -> x * x, 3));
        System.out.println(applyTwice(s -> s + "!", "Hello"));
    }

    // The loop version: we manage the total ourselves
    static int sumPosSquaresLoop(List<Integer> lst) {
        int total = 0;
        for (int x : lst) {
            if (x > 0) {
                total += x * x;
            }
        }
        return total;
    }

    // The stream version: describe WHAT, not HOW. Reads top to bottom.
    static int sumPosSquares(List<Integer> lst) {
        return lst.stream()
                  .filter(x -> x > 0)
                  .map(x -> x * x)
                  .reduce(0, Integer::sum);
    }

    // A generic higher-order method: takes a function f and a value x
    static <T> T applyTwice(UnaryOperator<T> f, T x) {
        return f.apply(f.apply(x));
    }
}
