// Towers of Hanoi in Java - a printing version and a pure version
// Compile & run:  javac Hanoi.java && java Hanoi

import java.util.ArrayList;
import java.util.List;

public class Hanoi {

    // The classic textbook version: the recursion and the output are tangled together.
    // It returns nothing, so all we can do is watch it print.
    static void hanoiPrint(int n, String source, String center, String destination) {
        if (n == 0) {
            return;
        }
        hanoiPrint(n - 1, source, destination, center);
        System.out.println("Move " + source + " -> " + destination);
        hanoiPrint(n - 1, center, source, destination);
    }

    // The pure version: same recursion, but it RETURNS the moves as data.
    static List<String> hanoiMoves(int n, String source, String center, String destination) {
        List<String> moves = new ArrayList<>();
        if (n == 0) {
            return moves;
        }
        moves.addAll(hanoiMoves(n - 1, source, destination, center));
        moves.add(source + " -> " + destination);
        moves.addAll(hanoiMoves(n - 1, center, source, destination));
        return moves;
    }

    public static void main(String[] args) {
        System.out.println("Printing version - side effects inside the recursion");
        hanoiPrint(3, "red", "middle", "blue");

        System.out.println();
        System.out.println("Pure version - side effects only here, at the edge");
        List<String> moves = hanoiMoves(3, "red", "middle", "blue");
        System.out.println(moves);

        System.out.println();
        System.out.println("Because the result is a value, we can compute with it");
        System.out.println(moves.size());                                     // 7
        System.out.println(hanoiMoves(10, "red", "middle", "blue").size());   // 1023
        System.out.println(hanoiMoves(4, "red", "middle", "blue").get(0));    // first move
    }
}
