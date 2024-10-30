#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <cstdint>

const std::uint32_t FPS = 60;
const std::uint32_t MILLISECONDS_PER_FRAME = 16;
const std::int32_t PIXELS_PER_METER = 50; // checar por que quando passamos isso para uint32_t as particulas bugam pegando velocidades altissimas.

const std::uint32_t window_width = 500;
const std::uint32_t window_height = 400;

#endif