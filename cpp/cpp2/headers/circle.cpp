#include<iostream>
#include"circle.hpp"

using namespace std;

float Circle::area() const {
    return PI * radius * radius;
}
float Circle::perimeter() const {
    return 2 * PI * radius;
}
void  Circle::print() const {
    cout << type << " radius=" << radius << endl;
}
