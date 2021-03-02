#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include<iostream>
#include"shape.hpp"

#define PI 3.14159

class Circle : public Shape {
    private:
        float radius;
    public:
        // NOTES: 
        //   - The explicit keyword here prevents the compiler from making
        //       an implicit conversion from float to Circle
        //   - The string parameter is passed as a constant reference as
        //       we should not be modifying it in the function
        explicit Circle(float r, const std::string &t="Circle")
            : Shape(t), radius(r) {}

        // NOTE: The const identifier indicates that these functions will not
        //         modify the state of the object when they were called.
        // NOTE: The area and perimeter methods are marked with the override
        //          identifier since they override functions from the base class
        float area() const override;
        float perimeter() const override;
        // print is NOT marked with the override identifier since print is
        //   a non-virtual method in the base class
        void  print() const;
};

#endif