#ifndef FORCE_H
#define FORCE_H

#include <memory>

#include "Vec2.hpp"
#include "Particle.hpp"

class Force {
    public:
        static Vec2 GenerateFragForce(const std::shared_ptr<Particle> p, float k){
            auto dragForce = Vec2();
            auto magnitudeSquared = p->velocity.MagnitudeSquared();

            if(magnitudeSquared > 0){
                Vec2 dragDirection = p->velocity.UnitVector() * -1;
                float dragMagnitude = k * magnitudeSquared;
                dragForce = dragDirection * dragMagnitude;
            }
            return dragForce;
        }
};

#endif