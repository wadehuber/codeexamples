#include<iostream>

namespace square {
    using namespace std;

    int area (int s) {
        return s * s;
    }

    int perimeter (int s) {
        return 4 * s;
    }

    void print(int s) {
        cout << "Square with side " << s << " perimeter=" 
                    << perimeter(s) << " area=" << area(s) << endl;
    }
}

namespace circle {
    constexpr double PI = 3.14159;

    double area(int r) {
        return PI * r * r;
    }

    double perimeter(int r) {
        return 2 * PI * r;
    }
    
    void print(int s) {
        std::cout << "Circle with radius " << s << " perimeter=" 
                    << perimeter(s) << " area=" << area(s) << std::endl;
    }
}

void circlesquare(int x) {
    using circle::area;
    using square::perimeter;

    std::cout << "The area of a circle with radius " << x << " is " << area(x) << std::endl;
    std::cout << "The perimeter of a square with side " << x << " is " << perimeter(x) << std::endl;
}

int main () {

    std::cout << "print function:" << std::endl;
    square::print(10);
    circle::print(10);

    std::cout << std::endl;
    std::cout << "area & perimeter functions:" << std::endl;
    std::cout << "The area of a square with a side of 4 is " << square::area(4) << std::endl;
    std::cout << "The perimeter of a square with a side of 4 is " << square::perimeter(4) << std::endl;

    std::cout << "The area of a circle with radius 5 is " << circle::area(5) << std::endl;
    std::cout << "The perimeter of a circle with radius 5 is " << circle::perimeter(5) << std::endl;
    std::cout << std::endl;

    std::cout << "PI = " << circle::PI << std::endl;
    std::cout << std::endl;

    std::cout << "circlesquare:" << std::endl;
    circlesquare(7);
    circlesquare(3);

    return 0;
}