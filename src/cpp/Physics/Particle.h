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
    void SetXPosition(float x);
    void SetYPosition(float y);
    void SetVelocity(float x, float y);
    float GetXVelocity() const;
    float GetYVelocity() const;
    void AddPosition(Vec2 position);
    Vec2 GetVelocity() const;
};

#endif