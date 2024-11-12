#ifndef FORCE_H
#define FORCE_H

#include <memory>
#include <iostream>

#include "Vec2.hpp"
#include "Particle.hpp"

class Force {
    public:
        static Vec2 GenerateDragForce(const Particle& p, float k){
            auto dragForce = Vec2();
            auto magnitudeSquared = p.velocity.MagnitudeSquared();

            if(magnitudeSquared > 0){
                Vec2 dragDirection = p.velocity.UnitVector() * -1;
                float dragMagnitude = k * magnitudeSquared;
                dragForce = dragDirection * dragMagnitude;
            }
            return dragForce;
        }

        static Vec2 GenerateFrictionForce(const Particle& p, float k){
            Vec2 frictionForce = Vec2();
            // Calcula a direcao da forca de friccao(inverso da velocidade).

            Vec2 frictionDirection = p.velocity.UnitVector() * -1;
            // Calcula a magnitude da friccao(constante por agora)
            float frictionMagnitude = k;

            // Calcula o vetor final da forca de friccao
            frictionForce = frictionDirection * frictionMagnitude;
            
            return frictionForce;
        }
};

#endif