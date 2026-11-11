// Pure functions & referential transparency
// Compile & run:  javac PureFunctions.java && java PureFunctions

public class PureFunctions {

    // A pure function - depends only on its parameter and changes nothing else
    static int square(int x) {
        return x * x;
    }

    // An IMPURE function - it reads AND modifies state that lives outside the method
    static int count = 0;

    static int f(int x) {
        count++;                 // side effect: changes a static field
        return x + count;
    }

    // The functional fix - make the hidden state an explicit parameter
    static int fPure(int x, int count) {
        return x + count;
    }

    // Side effects hide in objects too: this method changes its argument
    static void addBonus(int[] scores) {
        for (int i = 0; i < scores.length; i++) {
            scores[i] += 5;      // the caller's array is modified
        }
    }

    public static void main(String[] args) {
        System.out.println("A pure function - same input, same output");
        System.out.println(square(5));
        System.out.println(square(5));
        System.out.println(square(5) + square(5));
        System.out.println(2 * square(5));          // same answer - the algebra works

        System.out.println();
        System.out.println("An impure function - same input, different output");
        System.out.println(f(10) + f(10));          // 11 + 12 = 23
        System.out.println(2 * f(10));              // 2 * 13 = 26 -- the algebra is broken
        System.out.println(f(10));                  // 14

        System.out.println();
        System.out.println("The functional fix");
        System.out.println(fPure(10, 1) + fPure(10, 1));
        System.out.println(2 * fPure(10, 1));       // equal again

        System.out.println();
        System.out.println("A side effect through an object reference");
        int[] scores = {80, 90, 70};
        addBonus(scores);
        addBonus(scores);                          // called twice by mistake?
        System.out.println(java.util.Arrays.toString(scores));  // [90, 100, 80]
    }
}
