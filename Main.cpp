#include <memory>
#include <iostream>
#include "Vec2.hpp"

int main(){

    Vec2 a = Vec2(1,0);
    Vec2 b = Vec2(8, 6);

    // a.Add(b);
    // a.Print();
    // a.Sub(b);
    // a.Print();
    // a.Scale(4);
    // a.Print();

    Vec2 res = a.Rotate(3.14/2);
    res.Print();
    b.Normalize();
    std::cout << "Value of normlized vector x: " <<b.x <<" Y: " << b.y  << std::endl;

    return EXIT_SUCCESS;
}