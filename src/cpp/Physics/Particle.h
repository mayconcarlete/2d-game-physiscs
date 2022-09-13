#ifndef PARTICLE_H
#define PARTICLE_H

#include "Vec2.h"

class Particle {
  private:
    Vec2 position;
    Vec2 velocity;
    Vec2 acceleration;
    float mass;
  public:
    Particle(float x, float y, float mass);
    ~Particle();
    float GetXPosition() const;
    float GetYPosition() const;
};

#endif