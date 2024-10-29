#include "Graphics.hpp"
#include <cstdint>
#include "SDL2/SDL.h"
#include <string>
#include <iostream>
#include <SDL2/SDL2_gfxPrimitives.h>
#include <cmath>
#include "Physics/Vec2.hpp"
#include <vector>

Graphics::Graphics(std::uint32_t width, std::uint32_t height):m_windowWidth(width), m_windowHeight(height){};

bool Graphics::OpenWindow(){
    if(SDL_Init(SDL_INIT_EVERYTHING) != 0){
        std::string error = SDL_GetError();
        std::cout << "Error SDL_Init: " << error << std::endl;
        return false;
    }
    std::string title = "Game Physics";
    std::cout << "width: " << m_windowWidth << " Height: " << m_windowHeight << std::endl;
    m_window = SDL_CreateWindow(
        "Game Physics",
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
void Graphics::CloseWindow(){
    SDL_DestroyRenderer(m_renderer);
    SDL_DestroyWindow(m_window);
    SDL_Quit();
}

void Graphics::ClearScreen(std::uint32_t color){
    SDL_SetRenderDrawColor(m_renderer, color >> 16, color >> 8, color, 255); // 120, 180, 255, 255
    SDL_RenderClear(m_renderer);
}

void Graphics::RenderFrame(){
    SDL_Delay(10);
    SDL_RenderPresent(m_renderer);
}

void Graphics::DrawLine(std::int32_t x0, std::int32_t y0, std::int32_t x1, std::int32_t y1, std::uint32_t color){
    lineColor(m_renderer, x0, y0, x1, y1, color);
}

void Graphics::DrawCircle(std::int32_t x, std::int32_t y, std::uint32_t radius, float angle, std::uint32_t color){
    circleColor(m_renderer, x, y, radius, color);
    lineColor(m_renderer, x, y, x + cos(angle) * radius, y * sin(angle) * radius, color);
}

void Graphics::DrawFillCircle(std::int32_t x, std::int32_t y, std::uint32_t radius, std::uint32_t color){
    filledCircleColor(m_renderer, x, y, radius, color);
}

void Graphics::DrawRect(std::int32_t x, std::int32_t y, std::int32_t width, std::int32_t height, std::uint32_t color){
    lineColor(m_renderer, x - width / 2.0, y - height / 2.0, x + width / 2.0, y - height / 2.0, color);
    lineColor(m_renderer, x + width / 2.0, y - height / 2.0, x + width / 2.0, y + height / 2.0, color);
    lineColor(m_renderer, x + width / 2.0, y + height / 2.0, x - width / 2.0, y + height / 2.0, color);
    lineColor(m_renderer, x - width / 2.0, y + height / 2.0, x - width / 2.0, y - height / 2.0, color);
}

void Graphics::DrawFillRect(std::int32_t x, std::int32_t y, std::int32_t width, std::int32_t height, std::uint32_t color){
    boxColor(m_renderer, x - width / 2.0, y - height / 2.0, x + width / 2.0, y + height / 2.0, color);
}

void Graphics::DrawPolygon(std::int32_t x, std::int32_t y, const std::vector<Vec2>& vertices, std::uint32_t color){
    for(std::uint32_t i = 0; i < vertices.size(); ++i){
        std::uint32_t currentIndex = i;
        std::uint32_t nextIndex = (i + 1) % vertices.size();
        lineColor(m_renderer, vertices[currentIndex].x, vertices[currentIndex].y, vertices[nextIndex].x, vertices[nextIndex].y, color);
    }
    filledCircleColor(m_renderer, x, y, 1, color);
}

void Graphics::DrawFillPolygon(std::int32_t x, std::int32_t y, const std::vector<Vec2>& vertices, std::uint32_t color) {
    std::vector<short> vx;
    std::vector<short> vy;
    for (int i = 0; i < vertices.size(); i++) {
        vx.push_back(static_cast<int>(vertices[i].x));
    }
    for (int i = 0; i < vertices.size(); i++) {
        vy.push_back(static_cast<int>(vertices[i].y));
    }
    filledPolygonColor(m_renderer, &vx[0], &vy[0], vertices.size(), color);
    filledCircleColor(m_renderer, x, y, 1, 0xFF000000);
}

void Graphics::DrawTexture(std::int32_t x, std::int32_t y, std::int32_t width, std::int32_t height, float rotation, SDL_Texture* texture) {
    SDL_Rect dstRect = {x - (width / 2), y - (height / 2), width, height};
    float rotationDeg = rotation * 57.2958;
    SDL_RenderCopyEx(m_renderer, texture, NULL, &dstRect, rotationDeg, NULL, SDL_FLIP_NONE);
}

void Graphics::DrawGizmo(const Vec2& v, float magnitude){
    // filledTrigonColor(m_renderer, 10, 10, 30, 10, 15, 30, 0xFF0000FF);
    // length = 100

    this->DrawLine(0, 0, v.x, v.y, 0xFFFF00FF);
    filledCircleColor(m_renderer, 30, 30, 3, 0xFF0000FF);
}