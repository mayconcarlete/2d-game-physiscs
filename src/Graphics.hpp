#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <cstdint>
#include "SDL2/SDL.h"

class Graphics{
    private:
        std::uint32_t m_windowWidth;
        std::uint32_t m_windowHeight;
        SDL_Window* m_window;
        SDL_Renderer* m_renderer;
    
    public:
        Graphics(std::uint32_t width, std::uint32_t height);
        ~Graphics() = default;
        bool OpenWindow();
        void CloseWindow();
        void ClearScreen(std::uint32_t color);
        void RenderFrame();
};

 #endif