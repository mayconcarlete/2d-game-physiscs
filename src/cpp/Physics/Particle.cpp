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

Vec2& Particle::GetPosition() {
  return this->position;
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

void Particle::AddPosition(Vec2 position){
  this->position.Add(position);
}

Vec2 Particle::GetVelocity() const {
  return this->velocity;
}

Particle& Particle::operator += (const Vec2& v){
  this->position.Add(v);
  return *this;
}