#define SDL_MAIN_HANDLED
#include <memory>
#include <iostream>
#include "Vec2.hpp"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL2_gfxPrimitives.h>

int main(){

    Vec2 a = Vec2(1,2);
    Vec2 b = Vec2(8, 6);

    // a.Add(b);
    // a.Print();
    // a.Sub(b);
    // a.Print();
    // a.Scale(4);
    // a.Print();

    // Vec2 res = a.Rotate(3.14/2);
    // res.Print();
    // b.Normalize();
    // std::cout << "Value of normlized vector x: " <<b.x <<" Y: " << b.y  << std::endl;

    Vec2 result = b;
    result -= a;
    std::cout << "Result a - b: " << result.x << " y: " << result.y << std::endl;

    return EXIT_SUCCESS;
}