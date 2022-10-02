#include "./Force.h"

Vec2 Force::GenerateDragForce(const Particle& particle, float k){
  Vec2 dragForce = Vec2(0, 0);
  if(particle.velocity.MagnitudeSquared() == 0){
    return dragForce;
  }
  Vec2 dragDirection = particle.velocity.UnitVector() * -1;
  float dragMagnitude = k * particle.velocity.MagnitudeSquared();
  dragForce = dragDirection * dragMagnitude;
  return dragForce;
}


Vec2 Force::GenerateFrictionForce(const Particle& particle, float frictionMagnitude){
  Vec2 frictionForce = Vec2(0, 0);
  Vec2 frictionDirection = particle.velocity.UnitVector() * -1;
  frictionForce = frictionDirection * frictionMagnitude;
  return frictionForce;
}