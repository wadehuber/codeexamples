#include<iostream>

int quotient(int top, int bot) {
    return top / bot;
}

int shift(int a, int b) {
    return a * b;
}

void doStuff(int x, int y) {
    try {
        if ( (x==13) || (y==13) ) {
            throw 13;
        }
        std::cout << "  " << x << " * " << y << " = " << shift(x,y) << std::endl;
        if ( (y == 0) ) {
            throw 0;
        }
        std::cout << "  " << x << " / " << y << " = " << quotient(x,y) << std::endl;
    }
    catch(int e) {
        if (e == 0)
            std::cout << "Warning: attempt to devide by 0!" << std::endl;
        else 
            std::cout << "Unlucky number !" << e << "!" << std::endl;
    }
}

int main() {
    std::cout << "doStuff(2,3):" << std::endl;
    doStuff(2,3); 
    std::cout << std::endl << "doStuff(2,0):" << std::endl;
    doStuff(2,0); 
    std::cout << std::endl << "doStuff(26,13):" << std::endl;
    doStuff(13,2); 
    return 0;
}
