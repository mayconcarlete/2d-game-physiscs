#ifndef PARTICLE_H
#define PARTICLE_H

#include "Vec2.hpp"

class Particle {
    public:
        Vec2 position;
        Vec2 velocity;
        Vec2 acceleration;

        float mass;

        Particle(float x, float y, float mass);
        ~Particle();
};

#endif