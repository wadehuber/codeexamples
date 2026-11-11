// Java is statement-oriented: most lines are instructions that DO something
// (assign, loop, print) rather than expressions that ARE something.
// Compile & run:  javac Expressions.java && java Expressions

public class Expressions {

    public static void main(String[] args) {

        System.out.println("Infix notation - precedence rules decide the order");
        System.out.println(3 + 4);
        System.out.println((2 + 3) * (10 - 4));
        System.out.println(14 - 2 * 6);           // precedence: * happens before -

        System.out.println();
        System.out.println("if is a STATEMENT - it does not produce a value");
        int x = -7;
        int abs;
        if (x > 0) {
            abs = x;                               // we have to assign inside each branch
        } else {
            abs = -x;
        }
        System.out.println(abs);

        // The conditional (ternary) operator is Java's expression version of if
        System.out.println(10 * (x > 0 ? x : -x));

        System.out.println();
        System.out.println("A multi-way choice - statement style vs expression style");
        System.out.println(gradeStatement(95) + " " + gradeStatement(72));
        System.out.println(gradeExpression(88) + " " + gradeExpression(91) + " " + gradeExpression(40));

        System.out.println();
        System.out.println("Imperative style - store each intermediate result");
        int a = add1(5);
        int b = square(a);
        int c = half(b);
        System.out.println(c);

        System.out.println("Functional style - compose the calls directly");
        System.out.println(half(square(add1(5))));

        System.out.println();
        System.out.println("Careful - int / int is INTEGER division in Java");
        System.out.println(half(3));               // 1 (Scheme's (half 3) is the rational 3/2)
        System.out.println(3 / 2.0);               // 1.5 - one double operand gives a double
    }

    // Statement style: control flow with return statements
    static char gradeStatement(int score) {
        if (score >= 90) return 'A';
        if (score >= 80) return 'B';
        if (score >= 70) return 'C';
        return 'F';
    }

    // Expression style: a switch expression (Java 14+) evaluates to a value. It works like
    // Scheme's case, not cond: it matches ONE value against constants instead of testing
    // conditions, which is why the score has to be divided by 10 first.
    // Math.min caps the score at 100 so that 110, 120, ... still map to 'A' and the
    // result agrees with gradeStatement (and the Scheme and C++ versions) for every int.
    static char gradeExpression(int score) {
        return switch (Math.min(score, 100) / 10) {
            case 10, 9 -> 'A';
            case 8     -> 'B';
            case 7     -> 'C';
            default    -> 'F';
        };
    }

    static int square(int n) { return n * n; }
    static int add1(int n)   { return n + 1; }
    static int half(int n)   { return n / 2; }   // integer division: half(3) is 1
}
