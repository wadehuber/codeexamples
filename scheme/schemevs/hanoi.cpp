// Towers of Hanoi in C++ - a printing version and a pure version
// Compile & run:  g++ -std=c++17 hanoi.cpp -o hanoi && ./hanoi

#include <iostream>
#include <string>
#include <vector>
using namespace std;

// The classic textbook version: the recursion and the output are tangled together.
// It returns nothing, so all we can do is watch it print.
void hanoiPrint(int n, const string& source, const string& center, const string& destination) {
    if (n == 0) return;
    hanoiPrint(n - 1, source, destination, center);
    cout << "Move " << source << " -> " << destination << endl;
    hanoiPrint(n - 1, center, source, destination);
}

// The pure version: same recursion, but it RETURNS the moves as data.
vector<string> hanoiMoves(int n, const string& source, const string& center, const string& destination) {
    if (n == 0) return {};
    vector<string> moves = hanoiMoves(n - 1, source, destination, center);
    moves.push_back(source + " -> " + destination);
    vector<string> rest = hanoiMoves(n - 1, center, source, destination);
    moves.insert(moves.end(), rest.begin(), rest.end());
    return moves;
}

int main() {
    cout << "Printing version - side effects inside the recursion" << endl;
    hanoiPrint(3, "red", "middle", "blue");

    cout << endl << "Pure version - side effects only here, at the edge" << endl;
    vector<string> moves = hanoiMoves(3, "red", "middle", "blue");
    for (const string& m : moves) {
        cout << m << endl;
    }

    cout << endl << "Because the result is a value, we can compute with it" << endl;
    cout << moves.size() << endl;                                       // 7
    cout << hanoiMoves(10, "red", "middle", "blue").size() << endl;     // 1023
    cout << hanoiMoves(4, "red", "middle", "blue")[0] << endl;          // first move

    return 0;
}
