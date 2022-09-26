#include "Vec2.h"
#include "Particle.h"
#include <iostream>
#include "../Graphics.h"

Particle::Particle(float x, float y, float mass){
  this->position = Vec2(x, y);
  this->acceleration = Vec2();
  this->mass = mass;
  if(mass != 0.0){
    this->invMass = 1.0 / mass;
  } else {
    this->invMass = 0.0;
  }

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
  this->position.x = x;
}

void Particle::SetYPosition(float y){
  this->position.y = y;
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

void Particle::SetAcceleration(const Vec2 v){
  this->acceleration = v;
}

void Particle::AddForce(const Vec2& force){
  this->sumForces += force;
}

void Particle::ClearForces(){
  this->sumForces = Vec2(0.0, 0.0);
}

void Particle::Integrate(const float dt){
    this->acceleration = this->sumForces * this->invMass;
    this->velocity += this->acceleration * dt;
    this->position += this->velocity * dt;
    this->ClearForces();
}

void Particle::UpdateVelocity(const float deltaTime){

    this->Integrate(deltaTime);
    if(this->position.x - this->radius <=0) {
        this->position.x = this->radius;
        this->velocity.x *= -0.5;
    } else if(this->position.x + this->radius >= Graphics::Width()){
        this->position.x = Graphics::Width() - this->radius;
        this->velocity.x *= -0.5;
    }

    if(this->position.y - this->radius <= 0 ){
        this->position.y = this->radius;
        this->velocity.y *= -0.5;
    } else if (this->position.y + this->radius >= Graphics::Height()){
        this->position.y = Graphics::Height() - this->radius;
        this->velocity.y *= -0.5;
    }
}