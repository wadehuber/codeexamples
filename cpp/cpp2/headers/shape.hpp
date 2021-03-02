#ifndef SHAPE_HPP
#define SHAPE_HPP

#include<iostream>

class Shape {
    protected:
        std::string type;

    public:
        Shape(const std::string &t="Shape") : type(t) {}  

        // non-virtual method
        void print() const { std::cout << "I am a shape" << std::endl; }
        
        // virtual method
        virtual void printType() const { std::cout << "SHAPE: " << type << std::endl; }

        // pure virtual (abstract) methods
        virtual float area() const = 0;
        virtual float perimeter() const = 0;
};

#endif