#include<iostream>
#include"rectangle.hpp"

using namespace std;

float Rectangle::area() const {
    return length * width;
}

float Rectangle::perimeter() const {
    return 2 * length + 2 * width;
}

void Rectangle::print() const {
    cout << type << " length=" << length << " width=" << width << endl;
}

void Rectangle::printType() const {
    if (length == width) {
        cout << "RECTANGLE: " << "Square" << endl;
    }
    else {
        cout << "RECTANGLE: " << type << endl;
    }
}