#ifndef SQUARE_HPP
#define SQUARE_HPP

#include<iostream>
#include"rectangle.hpp"

class Square : public Rectangle {
    public:
        explicit Square(float s, const std::string &t="Square")
            : Rectangle(s, s, t) {}

        void  print() const;
};
#endif