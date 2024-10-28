#include "Particle.hpp"
#include "Vec2.hpp"
#include <iostream>

Particle::Particle(float x, float y, float mass){
    position = Vec2(x, y);
    this->mass = mass;
    radius = 4;
    std::cout << "Particle Constructor called!" << std::endl;
};

Particle::~Particle(){
    std::cout << "Particle destructor called!" << std::endl;
}

void Particle::AddForce(const Vec2& force){
    sumForces += force;
}

void Particle::ClearForces(){
    sumForces = Vec2();
}

void Particle::Integrate(float deltaTime){
    acceleration = sumForces / mass;
    std::cout << "Sumx: " << sumForces.x << " Y: " << sumForces.y << " mass: " << mass << std::endl;
    acceleration.Print();
    velocity += acceleration * deltaTime;
    position += velocity * deltaTime;
    ClearForces();
}