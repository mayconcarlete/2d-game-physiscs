#include "Particle.hpp"
#include "Vec2.hpp"
#include <iostream>

Particle::Particle(float x, float y, float mass){
    position = Vec2(x, y);
    mass = mass;
    radius = 4;
    std::cout << "Particle Constructor called!" << std::endl;
};

Particle::~Particle(){
    std::cout << "Particle destructor called!" << std::endl;
}

void Particle::Integrate(float deltaTime){
    velocity += acceleration * deltaTime;
    position += velocity * deltaTime;
}