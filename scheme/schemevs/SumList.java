// Summing a list - the same problem three ways.
// Compile & run:  javac SumList.java && java SumList

import java.util.List;

public class SumList {

    public static void main(String[] args) {
        int[] values = {4, 8, 15, 16, 23, 42};

        System.out.println("Imperative sum - a loop that changes total and i");
        System.out.println(sumLoop(values));

        System.out.println();
        System.out.println("Recursive sum - the same structure as the Scheme version");
        System.out.println(sumRecursive(values, 0));

        System.out.println();
        System.out.println("Tail-recursive style - the running total is a parameter");
        System.out.println(sumAcc(values, 0, 0));
        // NOTE: Java does NOT optimize tail calls. A large enough array would
        // still overflow the stack, so in Java the loop is the practical choice.

        System.out.println();
        System.out.println("Higher-order sum - streams (Java 8+)");
        List<Integer> lst = List.of(4, 8, 15, 16, 23, 42);
        System.out.println(lst.stream().mapToInt(Integer::intValue).sum());
        System.out.println(lst.stream().reduce(0, Integer::sum));
    }

    // To understand this method, we trace how total and i change over time.
    static int sumLoop(int[] values) {
        int total = 0;
        for (int i = 0; i < values.length; i++) {
            total = total + values[i];
        }
        return total;
    }

    // Java arrays have no car/cdr, so we use an index to mark "the rest of the list."
    // Base case: past the end -> 0.  Otherwise: first item + sum of the rest.
    static int sumRecursive(int[] values, int index) {
        if (index == values.length) {
            return 0;
        }
        return values[index] + sumRecursive(values, index + 1);
    }

    static int sumAcc(int[] values, int index, int total) {
        if (index == values.length) {
            return total;
        }
        return sumAcc(values, index + 1, total + values[index]);
    }
}
