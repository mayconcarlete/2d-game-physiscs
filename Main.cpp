#include <memory>
#include <iostream>
#include "Vec2.hpp"

int main(){

    Vec2 a = Vec2(2,2);
    Vec2 b = Vec2(1, 1);
    
    a.Add(b);
    a.Print();

    return EXIT_SUCCESS;
}