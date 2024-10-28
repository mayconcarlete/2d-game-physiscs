#ifndef PARTICLE_H
#define PARTICLE_H

#include "Vec2.hpp"
#include <cstdint>

class Particle {
    public:
        Vec2 position;
        Vec2 velocity;
        Vec2 acceleration;

        Vec2 sumForces;

        std::uint32_t radius;
        float mass;

        Particle(float x, float y, float mass, std::uint32_t radius);
        ~Particle();

        void AddForce(const Vec2& force);
        void ClearForces();
        void Integrate(float deltaTime);
};

#endif