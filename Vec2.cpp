#include "Vec2.hpp"
#include <cmath>
#include <iostream>

Vec2::Vec2():x(0), y(0){}
Vec2::Vec2(float x, float y):x(x),y(y){}

void Vec2::Print() const {
    std::cout << "X: " << x << " Y: " << y << std::endl;
}

void Vec2::Add(const Vec2& v){
    x += v.x;
    y += v.y;
}

void Vec2::Sub(const Vec2& v){
    x -= v.x;
    y -= v.y;
}

void Vec2::Scale(const float n){
    x *= n;
    y *= n;
}

Vec2 Vec2::Rotate(const float angle) const {
    Vec2 result;
    result.x = x * cos(angle) - y * sin(angle);
    result.y = x * sin(angle) + y * cos(angle);
    return result;
}

