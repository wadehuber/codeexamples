#include<iostream>
#include"triangle.hpp"

using namespace std;

float Triangle::area() const { 
    return base * height;
}

float Triangle::perimeter() const { 
    return 0.5 * base * height;
}

void Triangle::print() const {
    cout << type << " base=" << base << " height=" << height << endl; 
}