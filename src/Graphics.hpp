#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <cstdint>
#include <vector>
#include "SDL2/SDL.h"
#include "Physics/Vec2.hpp"

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

        void DrawLine(std::int32_t x0, std::int32_t y0, std::int32_t x1, std::int32_t y1, std::uint32_t color);
        void DrawCircle(std::int32_t x, std::int32_t y, std::uint32_t radius, float angle, std::uint32_t color);
        void DrawFillCircle(std::int32_t x, std::int32_t y, std::uint32_t radius, std::uint32_t color);
        void DrawRect(std::int32_t x, std::int32_t y, std::int32_t width, std::int32_t height, std::uint32_t color);
        void DrawFillRect(std::int32_t x, std::int32_t y, std::int32_t width, std::int32_t height, std::uint32_t color);
        void DrawPolygon(std::int32_t x, std::int32_t y, const std::vector<Vec2>& vertices, std::uint32_t color);
        void DrawFillPolygon(std::int32_t x, std::int32_t y, const std::vector<Vec2>& vertices, std::uint32_t color);
        void DrawTexture(std::int32_t x, std::int32_t y, std::int32_t width, std::int32_t height, float rotation, SDL_Texture* texture);

        void DrawGizmo(const Vec2& v, float magnitude);

};

 #endif