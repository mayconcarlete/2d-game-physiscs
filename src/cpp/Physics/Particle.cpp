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

void Particle::SetXPosition(float x){
  this->position.SetX(x);
}

void Particle::SetYPosition(float y){
  this->position.SetY(y);
}

void Particle::SetVelocity(float x, float y){
  this->velocity = Vec2(x, y);
}

float Particle::GetXVelocity() const{
  return this->velocity.GetX();
}

float Particle::GetYVelocity() const {
  return this->velocity.GetY();
}