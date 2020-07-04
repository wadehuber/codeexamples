#include<iostream>
#include<vector>

using namespace std;

class RuleOf5 {
    private:
        int x;
    public:
        explicit RuleOf5(int n=1) : x(n) { cout << "Constructor x=" << n << endl; }
        ~RuleOf5() { }

        // Copy constructor & copy assignment (overloaded = operator)
        RuleOf5(const RuleOf5& that) { 
            x = that.x + 10;
            cout << "Copy Constructor " << x << endl; 
        }
        RuleOf5& operator=(const RuleOf5& that) { 
            if (this != &that) {
                x = that.x + 100;
                cout << "Copy Assignment (overloaded operator=) " << x << endl; 
            }
            return *this;
        }
        
        // Move constructor & move assignment (overloaded = operator)
        RuleOf5(const RuleOf5&& that) { 
            x = that.x + 1000;
            cout << "Move constructor " << x << endl; 
        }
        RuleOf5& operator=(const RuleOf5&& that) { 
            if (this != &that) {
                x = that.x + 10000;
                cout << "Move Assignment (overloaded operator=) " << x << endl; 
            }
            return *this;
        }
};

RuleOf5 makeRuleOf5() {
    RuleOf5 lVar(2) ;
    return lVar;
}

int main() {

    // Default constructor
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

    return 0;
}