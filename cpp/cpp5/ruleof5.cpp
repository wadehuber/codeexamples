#include<iostream>
#include<vector>

using namespace std;

class RuleOf5 {
    private:
        int x;
    public:
        RuleOf5(int n=0) : x(n) { cout << "Constructor x=" << x << endl; }
        ~RuleOf5() { cout << "Destructor x=" << x << endl; }

        // Copy constructor
        RuleOf5(const RuleOf5 & that) {
            x = that.x + 10;
            cout << "Copy Constructor " << x << endl;
        }

        // Copy assignment - overload operator=
        RuleOf5& operator=(const RuleOf5 & that) {
            if (this != &that) {
                x = that.x + 100;
                cout << "Copy Assignment (overloaded operator=) " << x << endl;
            }
            return *this;
        }

        // Move constructor
        RuleOf5(const RuleOf5 && that) {
            x = that.x + 10;
            cout << "Move Constructor " << x << endl;
        }

        // Move assignment - overload operator=
        RuleOf5& operator=(const RuleOf5&& that) {
            if (this != &that) {
                x = that.x + 10000;
                cout << "Move Assignment (overloaded operator=) " << x << endl;
            }
            return *this;
        }
};

RuleOf5 makeRuleOf5() {
    RuleOf5 varLocal(2);
    return varLocal;
}

int main() {

    // Constructor
    RuleOf5 varOriginal(1);
    cout << endl;

    // Copy constructor
    RuleOf5 varCopyConstructor = varOriginal;
    cout << endl;

    // Copy assignment
    RuleOf5 varCopyAssignment;
    varCopyAssignment = varOriginal;
    cout << endl;

    // Move assignment
    RuleOf5 varMoveAssignment;
    varMoveAssignment = makeRuleOf5();
    cout << endl;

    // Move constructor
    vector<RuleOf5> v;
    v.push_back(RuleOf5(3));
    cout << endl;
    
    // std::move
    RuleOf5 varStdMove;
    varStdMove = std::move(varOriginal);
    // After this point, varOriginal is no longer valid
    cout << endl;

    return 0;
}
