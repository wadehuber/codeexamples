// C++ is statement-oriented: most lines are instructions that DO something
// (assign, loop, print) rather than expressions that ARE something.
// Compile & run:  g++ -std=c++17 expressions.cpp -o expressions && ./expressions

#include <iostream>
using namespace std;

int square(int n) { return n * n; }
int add1(int n)   { return n + 1; }
int half(int n)   { return n / 2; }

// Statement style: control flow with return statements
char gradeStatement(int score) {
    if (score >= 90) return 'A';
    if (score >= 80) return 'B';
    if (score >= 70) return 'C';
    return 'F';
}

// Expression style: one chained conditional expression, much like cond
char gradeExpression(int score) {
    return score >= 90 ? 'A'
         : score >= 80 ? 'B'
         : score >= 70 ? 'C'
         :               'F';
}

int main() {
    cout << "Infix notation - precedence rules decide the order" << endl;
    cout << 3 + 4 << endl;
    cout << (2 + 3) * (10 - 4) << endl;
    cout << 14 - 2 * 6 << endl;                // precedence: * happens before -

    cout << endl << "if is a STATEMENT - it does not produce a value" << endl;
    int x = -7;
    int abs;
    if (x > 0) {
        abs = x;                                // we have to assign inside each branch
    } else {
        abs = -x;
    }
    cout << abs << endl;

    // The conditional (ternary) operator is C++'s expression version of if
    cout << 10 * (x > 0 ? x : -x) << endl;

    cout << endl << "A multi-way choice - statement style vs expression style" << endl;
    cout << gradeStatement(95) << " " << gradeStatement(72) << endl;
    cout << gradeExpression(88) << " " << gradeExpression(91) << " " << gradeExpression(40) << endl;

    cout << endl << "Imperative style - store each intermediate result" << endl;
    int a = add1(5);
    int b = square(a);
    int c = half(b);
    cout << c << endl;

    cout << "Functional style - compose the calls directly" << endl;
    cout << half(square(add1(5))) << endl;

    return 0;
}
