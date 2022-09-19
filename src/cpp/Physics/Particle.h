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
    int radius;
    Particle(float x, float y, float mass);
    ~Particle();
    Vec2& GetPosition();
    float GetXPosition() const;
    float GetYPosition() const;
    void SetXPosition(float x);
    void SetYPosition(float y);
    void UpdateVelocity();
    void SetXVelocity(const float x);
    void SetYVelocity(const float y);
    float GetXVelocity() const;
    float GetYVelocity() const;
    void AddPosition(Vec2 position);
    Vec2 GetVelocity() const;
    void SetAcceleration(const Vec2 v);
    Particle& operator += (const Vec2& v);
};

#endif