#include<iostream>
#include"shape.hpp"
#include"circle.hpp"

using namespace std;

float Circle::area() const { return radius;  }
float Circle::perimeter() const { return radius; }
void  Circle::print() const {cout << type << " radius=" << radius << endl; }
