#ifndef VEC2_H
#define VEC2_H

struct  Vec2 {
    double x;
    double y;
};

struct Vec2 *new_vec2(double x, double y);
void free_vec2(struct Vec2 *this);
void print_vec(struct Vec2 *this);

double magnitude(struct Vec2 *this);

void add(struct Vec2 *this, struct Vec2 v);
struct Vec2 *add_static(struct Vec2 *v1, struct Vec2 *v2);

void subtraction(struct Vec2 *this, struct Vec2 v);
struct Vec2 *subtraction_static(struct Vec2 *v1, struct Vec2 *v2);

void scale(struct Vec2 *this, double number);
struct Vec2 *scale_static(struct Vec2 *this, double number);

#endif