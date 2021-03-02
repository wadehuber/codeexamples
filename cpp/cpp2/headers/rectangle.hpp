#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include<iostream>
#include"shape.hpp"

class Rectangle : public Shape {
    protected:
        float length;
        float width;
    public:
        Rectangle(float l, float w, const std::string &t="Rectangle")
            : Shape(t), length(l), width(w) {}
        float area() const override;
        float perimeter() const override;
        void print() const ;
        void printType() const override;
};

#endif