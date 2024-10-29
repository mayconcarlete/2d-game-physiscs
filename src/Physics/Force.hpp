#ifndef FORCE_H
#define FORCE_H

#include "Vec2.hpp"
#include "Particle.hpp"

class Force {
    public:
        static Vec2 GenerateFragForce(const Particle& particle, float k){
            auto res = Vec2(2, 2);
            return res;
        }
};

#endif