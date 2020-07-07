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
        cout << "Square with side " << s << " perimeter=" << perimeter(s) << " area=" << area(s) << endl;
    }    
}

namespace circle {

    const int PI = 3.14159;

    double area (int r) {
        return PI * r * r;
    }

    double perimeter (int r) {
        return 2 * r * PI;
    }

    void print(int r) {
        std::cout << "Circle with radius " << r << " perimeter=" << perimeter(r) << " area=" << area(r) << std::endl;
    }    
}

void func(int x) {
    using circle::area;
    using square::perimeter;
    
    std::cout << "Shape x=" << x << " perimeter=" << perimeter(x) << " area=" << area(x) << std::endl;
}

int main () {

    std::cout << "Namespace demonstration:" << std::endl;
    square::print(10);
    circle::print(10);

    std::cout << std::endl;
    func(4);
    func(5);

    return 0;
}