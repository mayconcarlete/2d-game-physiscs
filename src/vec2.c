#include <math.h>
#include <stdlib.h>

#include "vec2.h"

struct Vec2 *new_vec2(double x, double y) {
    struct Vec2 *this = (struct Vec2*)malloc(sizeof(struct Vec2));
    this->x = x;
    this->y = y;
    return this;
}

void free_vec2(struct Vec2 *this){
    free(this);
}

void print_vec(struct Vec2 *this){
    printf("\n");
    printf("X: %.2f - Y: %.2f", this->x, this->y);
    printf("\n");
}

double magnitude(struct Vec2 *this){
    return sqrt((this->x * this->x) + (this->y * this->y));
}

void add(struct Vec2 *this, struct Vec2 v){
    this->x += v.x;
    this->y += v.y;
}

struct Vec2 *add_static(struct Vec2 *v1, struct Vec2 *v2){
    return new_vec2((v1->x + v2->x), (v1->y + v2->y));
}


void subtraction(struct Vec2 *this, struct Vec2 v){
    this->x -= v.x;
    this->y -= v.y;
}

struct Vec2 *subtraction_static(struct Vec2 *v1, struct Vec2 *v2){
    return new_vec2((v1->x - v2->x), (v1->y - v2->y));
}

void scale(struct Vec2 *this, double number){
    this->x *= number;
    this->y *= number;
}

struct Vec2 *scale_static(struct Vec2 *this, double number){
    return new_vec2((this->x * number), (this->y * number));
}   