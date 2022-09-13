#include "Vec2.h"
#include "Particle.h"
#include <iostream>

Particle::Particle(float x, float y, float mass){
  this->position = Vec2(x, y);
  this->mass = mass;
  std::cout << "Particle constructor called!" << std::endl;
}

Particle::~Particle(){
  std::cout << "Particle destructor called!" << std::endl;
}

float Particle::GetXPosition() const {
  return this->position.GetX();
}

float Particle::GetYPosition() const {
  return this->position.GetY();
}