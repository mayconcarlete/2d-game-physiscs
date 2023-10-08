#ifndef PARTICLE_H
#define PARTICLE_H

#include "Vec2.h"
#include "Constants.h"
class Particle {
  private:
  public:
    Particle(float x, float y, float mass);
    ~Particle();
    Vec2 position;
    Vec2 velocity;
    Vec2 acceleration;
    Vec2 sumForces;
    float mass;
    float invMass;
    int radius;

    Vec2& GetPosition();
    float GetXPosition() const;
    float GetYPosition() const;
    void SetXPosition(float x);
    void SetYPosition(float y);
    void Integrate(const float dt);
    void UpdateVelocity(const float deltaTime);
    float GetXVelocity() const;
    float GetYVelocity() const;
    void AddPosition(Vec2 position);
    Vec2 GetVelocity() const;
    void SetAcceleration(const Vec2 v);
    Particle& operator += (const Vec2& v);
    void AddForce(const Vec2& force);
    void ClearForces();
};

#endif