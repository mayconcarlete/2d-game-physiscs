#include <math.h>
#include <stdlib.h>

#include "vec2.h"

struct Vec2 *New_Vec2(double x, double y) {
    struct Vec2 *this = (struct Vec2*)malloc(sizeof(struct Vec2));
    this->x = x;
    this->y = y;
    return this;
}

void Free_Vec2(struct Vec2 *this){
    free(this);
}

void Print_Vec2(struct Vec2 *this){
    printf("\n");
    printf("X: %.2f - Y: %.2f", this->x, this->y);
    printf("\n");
}

double Magnitude(struct Vec2 *this){
    return sqrt((this->x * this->x) + (this->y * this->y));
}

void Add_Vec2(struct Vec2 *this, struct Vec2 v){
    this->x += v.x;
    this->y += v.y;
}

struct Vec2 *Add_Vec2_Static(struct Vec2 *v1, struct Vec2 *v2){
    return New_Vec2((v1->x + v2->x), (v1->y + v2->y));
}


void Sub_Vec2(struct Vec2 *this, struct Vec2 v){
    this->x -= v.x;
    this->y -= v.y;
}

struct Vec2 *Sub_Vec2_Static(struct Vec2 *v1, struct Vec2 *v2){
    return New_Vec2((v1->x - v2->x), (v1->y - v2->y));
}

void Scale_Vec2(struct Vec2 *this, double number){
    this->x *= number;
    this->y *= number;
}

struct Vec2 *scale_static(struct Vec2 *this, double number){
    return New_Vec2((this->x * number), (this->y * number));
}   

double dot_product(struct Vec2 *v1, struct Vec2 *v2){
    return (v1->x * v2->x) + (v1->y * v2->y);
}