#ifndef SQUARE_HPP
#define SQUARE_HPP

#include<iostream>
#include"rectangle.hpp"

#define PI 3.14159

class Square : public Rectangle {
    private:
        float side;
    public:
        explicit Square(float s, const std::string &t="Square")
            : Rectangle(s, s, t), side(s) {}

        float area() const override;
        float perimeter() const override;
        void  print() const;
};
#endif