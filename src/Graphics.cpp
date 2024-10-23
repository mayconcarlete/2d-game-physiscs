#include "Graphics.hpp"
#include <cstdint>
#include "SDL2/SDL.h"
#include <string>
#include <iostream>

Graphics::Graphics(std::uint32_t width, std::uint32_t height):m_windowWidth(width), m_windowHeight(height){};

bool Graphics::OpenWindow(){
    if(SDL_Init(SDL_INIT_EVERYTHING) != 0){
        std::string error = SDL_GetError();
        std::cout << "Error SDL_Init: " << error << std::endl;
        return false;
    }
    std::string title = "Game Physics";
    m_window = SDL_CreateWindow(
        title.c_str(),
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        m_windowWidth,
        m_windowHeight,
        SDL_WINDOW_SHOWN
    );

    if(m_window == NULL){
        std::string error = SDL_GetError();
        std::cout << "Error creating window: " << error << std::endl;
        return false;
    }

    m_renderer = SDL_CreateRenderer(
        m_window,
        -1,
        0
    );

    if(m_renderer == NULL){
        std::string error = SDL_GetError();
        std::cout << "Error creating renderer: " << error << std::endl;
        return false;
    }

    return true;
}