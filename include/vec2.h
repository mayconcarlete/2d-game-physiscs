#ifndef VEC2_H
#define VEC2_H

struct Vec2 {
    double x;
    double y;
};

struct Vec2* new_vec2(double x, double y);
void free_vec2(struct Vec2* vec2);

double magnitude(struct Vec2* vec2);

#endif