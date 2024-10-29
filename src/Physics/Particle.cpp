#include "Particle.hpp"
#include "Vec2.hpp"
#include <iostream>
#include <cstdint>

Particle::Particle(float x, float y, float mass, std::uint32_t radius){
    position = Vec2(x, y);
    this->mass = mass;
    if(this->mass > 0){
        this->invMass = 1.0f/this->mass;
    } else {
        this->invMass = 0.0f;
    }
    this->radius = radius;
    sumForces = Vec2();
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
    acceleration = sumForces * this->invMass;
    velocity += acceleration * deltaTime;
    position += velocity * deltaTime;
    ClearForces();
}