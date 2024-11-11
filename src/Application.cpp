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
    m_particles.push_back(smallParticle);
    // particles.push_back(bigParticle);

    m_pushForce = Vec2();

    // test Force class
    auto result = Force::GenerateDragForce(*smallParticle, 10);
    m_liquid.x = 0;
    m_liquid.y = window_height / 2;
    m_liquid.w = window_width;
    m_liquid.h = window_height / 2;
}
static bool mouseButtonClicked = false;
static std::int32_t mouseXBegin = 0, mouseYBegin = 0;
static std::int32_t mouseXFinal = mouseXBegin, mouseYFinal = mouseYBegin;

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
                    m_pushForce.y = -50 * PIXELS_PER_METER;
                }
                if(event.key.keysym.sym == SDLK_DOWN){
                    m_pushForce.y = 50 * PIXELS_PER_METER;
                }
                if(event.key.keysym.sym == SDLK_LEFT){
                    m_pushForce.x = -50 * PIXELS_PER_METER;
                }
                if(event.key.keysym.sym == SDLK_RIGHT){
                    m_pushForce.x = 50 * PIXELS_PER_METER;
                }
                break;
            case SDL_KEYUP:
                if(event.key.keysym.sym == SDLK_UP){
                    m_pushForce.y = 0;
                }
                if(event.key.keysym.sym == SDLK_DOWN){
                    m_pushForce.y = 0;
                }
                if(event.key.keysym.sym == SDLK_LEFT){
                    m_pushForce.x = 0;
                }
                if(event.key.keysym.sym == SDLK_RIGHT){
                    m_pushForce.x = 0;
                }
                break;

            case SDL_MOUSEMOTION:
                mouseCursor.x = event.motion.x;
                mouseCursor.y = event.motion.y;
                break;

            case SDL_MOUSEBUTTONDOWN:
                if(!mouseButtonClicked && event.button.button == SDL_BUTTON_LEFT){
                    mouseButtonClicked = true;
                    int x,y;
                    SDL_GetMouseState(&x, &y);
                    mouseCursor.x = x;
                    mouseCursor.y = y;
                }
                break;

            case SDL_MOUSEBUTTONUP:
                if(mouseButtonClicked && event.button.button == SDL_BUTTON_LEFT){
                    mouseButtonClicked = false;
                    Vec2 impulseDirection = (m_particles[0]->position - mouseCursor).UnitVector();
                    float impulseMagnitude = (m_particles[0]->position - mouseCursor).Magnitude() * 5.0f;
                    m_particles[0]->velocity = impulseDirection * impulseMagnitude;
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

    for(auto &particle: m_particles){
        // wind force
        // const auto wind = Vec2(3.0 * PIXELS_PER_METER, 0.0 * PIXELS_PER_METER);
        // particle->AddForce(wind);

        // weight force
        // const auto weight = Vec2(0.0f, 9.8f * particle->mass * PIXELS_PER_METER);
        // particle->AddForce(weight);

        // Friction Force
        Vec2 frictionForce = Force::GenerateFrictionForce(*particle, 10.0f * PIXELS_PER_METER);
        // particle->AddForce(m_pushForce);
        particle->AddForce(frictionForce);
        particle->AddForce(m_mouse_force * PIXELS_PER_METER);
        // drag force
        // if(particle->position.y >= m_liquid.y){
        //     const auto dragForce = Force::GenerateFragForce(*particle, 0.04);
        //     particle->AddForce(dragForce);
        // }
    }
    

    for(auto &particle: m_particles){
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
    m_graphics->DrawFillRect(m_liquid.x + m_liquid.w / 2, m_liquid.y + m_liquid.h / 2, m_liquid.w, m_liquid.h, 0xFF6E3713);
    if(mouseButtonClicked){
        int x, y;
        x;
        y;
        SDL_GetMouseState(&x, &y);
        // std::cout << "Mouse click up." << " X0: " << mouseXBegin  << " Y0: " <<mouseYBegin << " X: " <<mouseXFinal << " Y: " <<mouseYFinal << "\n";
        m_graphics->DrawLine(mouseCursor.x, mouseCursor.y ,mouseXFinal, mouseYFinal, 0xFF0000FF);
    }
    for(auto &particle: m_particles){   
        m_graphics->DrawFillCircle(particle->position.x, particle->position.y, particle->radius, 0xFFFFFFFF);
        
        // graphics->DrawGizmo(particle->velocity.Normalize(), 2.0);
    }
    // draw the liquid in the screen
    m_graphics->RenderFrame();
}

void Application::Destroy(){
    // delete particles
    for(auto particle: m_particles){
        delete particle;
    }

    // delete graphics
    m_graphics->CloseWindow();
    delete m_graphics;
}