#include<iostream>
#include"shape.hpp"
#include"square.hpp"

using namespace std;

float Square::area() const { return side;  }
float Square::perimeter() const { return side; }
void  Square::print() const {cout << type << " side=" << side << endl; }
