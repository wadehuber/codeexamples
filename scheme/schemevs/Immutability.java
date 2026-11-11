// Immutability - modifying data in place vs building new data
// Compile & run:  javac Immutability.java && java Immutability

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class Immutability {

    public static void main(String[] args) {

        System.out.println("Imperative: double each element IN PLACE");
        int[] arr = {1, 2, 3, 4, 5};
        int[] alias = arr;                       // a second reference to the SAME array
        for (int i = 0; i < arr.length; i++) {
            arr[i] = arr[i] * 2;
        }
        System.out.println(Arrays.toString(arr));
        System.out.println(Arrays.toString(alias));   // alias changed too - surprise!

        System.out.println();
        System.out.println("Functional: return a NEW list, leave the original alone");
        List<Integer> lst = List.of(1, 2, 3, 4, 5);   // List.of creates an immutable list
        System.out.println(doubleList(lst));
        System.out.println(lst);                       // the original is untouched

        System.out.println();
        System.out.println("The same thing with a stream");
        System.out.println(lst.stream().map(n -> n * 2).toList());   // Java 16+

        System.out.println();
        System.out.println("Immutable lists refuse to change");
        try {
            lst.set(0, 100);
        } catch (UnsupportedOperationException e) {
            System.out.println("Cannot modify: " + e.getClass().getSimpleName());
        }

        System.out.println();
        System.out.println("Insert into a sorted list - returns a new sorted list");
        System.out.println(insertSorted(3, List.of(1, 2, 4, 5)));
        System.out.println(insertSorted(0, lst));
        System.out.println(insertSorted(9, lst));
        System.out.println(lst);                       // still [1, 2, 3, 4, 5]
    }

    // Builds and returns a new list; the parameter is never modified
    static List<Integer> doubleList(List<Integer> lst) {
        List<Integer> result = new ArrayList<>();
        for (int n : lst) {
            result.add(n * 2);
        }
        return result;
    }

    // Copy, then insert into the copy
    static List<Integer> insertSorted(int n, List<Integer> lst) {
        List<Integer> result = new ArrayList<>(lst);
        int i = 0;
        while (i < result.size() && result.get(i) < n) {
            i++;
        }
        result.add(i, n);
        return result;
    }
}
