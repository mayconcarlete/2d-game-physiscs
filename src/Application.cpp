#include "Application.hpp"
#include "SDL2/SDL.h"
#include <memory>
#include <cstdint>
#include <iostream>
#include "Physics/Vec2.hpp"
#include "Physics/Particle.hpp"
#include "Physics/Constants.hpp"
#include "Physics/Force.hpp"

bool Application::IsRunning(){
    return m_running;
}

void Application::Setup(){

    std::uint32_t width = window_width;
    std::uint32_t height = window_height;
    m_graphics = new Graphics(width, height);
    m_running = m_graphics->OpenWindow();
    auto smallParticle = new Particle(50.0f, 50.0f, 1.0f, 4);
    // auto bigParticle = std::make_shared<Particle>(100.0f, 50.0f, 4.0f, 12);
    particles.push_back(smallParticle);
    // particles.push_back(bigParticle);

    pushForce = Vec2();

    // test Force class
    auto result = Force::GenerateFragForce(*smallParticle, 10);
    liquid.x = 0;
    liquid.y = window_height / 2;
    liquid.w = window_width;
    liquid.h = window_height / 2;
}

void Application::Input(){
    SDL_Event event;
    while(SDL_PollEvent(&event)){
        switch(event.type){
            case SDL_QUIT:
                m_running = false;
                break;
            case SDL_KEYDOWN:
                if(event.key.keysym.sym == SDLK_ESCAPE){
                    m_running = false;
                }
                if(event.key.keysym.sym == SDLK_UP){
                    pushForce.y = -50 * PIXELS_PER_METER;
                }
                if(event.key.keysym.sym == SDLK_DOWN){
                    pushForce.y = 50 * PIXELS_PER_METER;
                }
                if(event.key.keysym.sym == SDLK_LEFT){
                    pushForce.x = -50 * PIXELS_PER_METER;
                }
                if(event.key.keysym.sym == SDLK_RIGHT){
                    pushForce.x = 50 * PIXELS_PER_METER;
                }
                break;
            case SDL_KEYUP:
                if(event.key.keysym.sym == SDLK_UP){
                    pushForce.y = 0;
                }
                if(event.key.keysym.sym == SDLK_DOWN){
                    pushForce.y = 0;
                }
                if(event.key.keysym.sym == SDLK_LEFT){
                    pushForce.x = 0;
                }
                if(event.key.keysym.sym == SDLK_RIGHT){
                    pushForce.x = 0;
                }
                break;
            
            case SDL_MOUSEBUTTONDOWN:
                if(event.button.button == SDL_BUTTON_LEFT){
                    std::int32_t x, y;
                    SDL_GetMouseState(&x, &y);
                    const auto newParticle = new Particle(static_cast<float>(x), static_cast<float>(y), 2.0f, 4);
                    particles.push_back(newParticle);
                }
                break;
        }
    }
}

void Application::Update(){
    static std::uint32_t timePreviousFrame;
    std::int32_t waitTime = MILLISECONDS_PER_FRAME - (SDL_GetTicks64() - timePreviousFrame);
    if(waitTime > 0){
        SDL_Delay(waitTime);
    }

    float deltaTime = (SDL_GetTicks64() - timePreviousFrame) / 1000.0f;
    // to protect the code on debugger for example
    if(deltaTime > 0.016){
        deltaTime = 0.016;
    }
    timePreviousFrame = SDL_GetTicks64();

    for(auto &particle: particles){
        // wind force
        // const auto wind = Vec2(3.0 * PIXELS_PER_METER, 0.0 * PIXELS_PER_METER);
        // particle->AddForce(wind);

        // weight force
        const auto weight = Vec2(0.0f, 9.8f * particle->mass * PIXELS_PER_METER);
        particle->AddForce(weight);
        particle->AddForce(pushForce);

        // drag force
        if(particle->position.y >= liquid.y){
            const auto dragForce = Force::GenerateFragForce(*particle, 0.04);
            particle->AddForce(dragForce);
        }
    }
    

    for(auto &particle: particles){
        particle->Integrate(deltaTime);

        // check particle position
        if(particle->position.y - particle->radius <= 0){
            particle->position.y = particle->radius;
            particle->velocity.y *= -0.8;
        } else if(particle->position.y + particle->radius >= window_height){
            particle->position.y = window_height - particle->radius;
            particle->velocity.y *= -0.8;
        }

        if(particle->position.x - particle->radius <= 0){
            particle->position.x = particle->radius;
            particle->velocity.x *= -0.8;
        } else if (particle->position.x + particle->radius >= window_width){
            particle->position.x = window_width - particle->radius;
            particle->velocity.x *= -0.8;
        }
    }
    
}
// std::vector<Vec2> v {Vec2(0,0), Vec2(100, 0), Vec2(100, 100), Vec2(0, 100)};
void Application::Render(){
    m_graphics->ClearScreen(0xFF056263);
    m_graphics->DrawFillRect(liquid.x + liquid.w / 2, liquid.y + liquid.h / 2, liquid.w, liquid.h, 0xFF6E3713);
    for(auto &particle: particles){   
        m_graphics->DrawFillCircle(particle->position.x, particle->position.y, particle->radius, 0xFFFFFFFF);
        
        // graphics->DrawGizmo(particle->velocity.Normalize(), 2.0);
    }
    // draw the liquid in the screen
    m_graphics->RenderFrame();
}

void Application::Destroy(){
    // delete particles
    for(auto particle: particles){
        delete particle;
    }

    // delete graphics
    m_graphics->CloseWindow();
    delete m_graphics;
}