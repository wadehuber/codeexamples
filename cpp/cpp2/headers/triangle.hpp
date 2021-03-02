#ifndef TRIANGLE_HPP
#define TRIANGLE_HPP

#include<iostream>
#include"shape.hpp"


class Triangle : public Shape {
    private:
        float base;
        float height;
    public:
        Triangle(float b, float h, const std::string &t="Triangle")
            : Shape(t), base(b), height(h) {}

        float area() const override;
        float perimeter() const override;
        void print() const;
};

#endif