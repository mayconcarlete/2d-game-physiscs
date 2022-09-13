#include "./Physics/Vec2.h"
#include <memory>
#include <iostream>
int main(int argc, char *args[]) {
    // Application app;
    std::unique_ptr<Vec2> vec2 = std::make_unique<Vec2>(6, 8);
    std::unique_ptr<Vec2> vec3 = std::make_unique<Vec2>(4, 5);

    vec2->Print();

    return 0;
}