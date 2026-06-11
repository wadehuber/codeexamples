#include<iostream>
#include<cmath>
#include"triangle.hpp"

using namespace std;

float Triangle::area() const { 
    return 0.5f * base * height;
}

float Triangle::perimeter() const { 
    // Assume right triangle
    float hypotenuse = std::sqrt(base * base + height * height);
    return base + height + hypotenuse;
}

void Triangle::print() const {
    cout << type << " base=" << base << " height=" << height << endl; 
}