#include<iostream>
#include<vector>

int quotient(int top, int bot) {
    if (bot == 0) {
        throw 0;
    }
    return top / bot;
}

int mult(int a, int b) {
    return a * b;
}

void doStuff(int x, int y) {
    try {
        if ( (x == 13) || (y == 13) ) {
            throw 13;
        }
        std::cout << " " << x << "*" << y << "=" << mult(x,y) << std::endl;
        std::cout << " " << x << "/" << y << "=" << quotient(x,y) << std::endl;
    }
    catch(int e) {
        if (e==0) {
            std::cout << std::endl << "Warning: attempt to divide by 0!" << std::endl;
        }
        if (e==13) {
            std::cout << std::endl << "Warning: attempt to use unlucky number!" << std::endl;
        }    

    }
}

int main() {
    std::vector<int> vec = {1, 2, 3, 4};

    std::cout << "doStuff(2,3):" << std::endl;
    doStuff(2,3);

    std::cout << std::endl;
    std::cout << "doStuff(2,0):" << std::endl;
    doStuff(2,0);

    std::cout << std::endl;
    std::cout << "doStuff(39,13):" << std::endl;
    doStuff(39,13);

    
    std::cout << std::endl;
    std::cout << "Vector: " << std::endl;
    for (auto & ii : vec) {
        std::cout << ii << " ";
    }
    std::cout << std::endl;

    std::cout << "First 10 elements of vec: " << std::endl;
    try {
        for (int ii=0;ii<10;ii++) {
            std::cout << vec.at(ii) << " ";
        }
    }
    catch (const std::out_of_range &) {
        std::cout << "You tried to access something I didn't have!" << std::endl;
    }
    std::cout << std::endl;

    return 0;
}
