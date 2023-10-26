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

double Vec2_Magnitude(struct Vec2 *this){
    return sqrt((this->x * this->x) + (this->y * this->y));
}

void Vec2_Add(struct Vec2 *this, struct Vec2 v){
    this->x += v.x;
    this->y += v.y;
}

struct Vec2 *Vec2_Add_Static(struct Vec2 *v1, struct Vec2 *v2){
    return New_Vec2((v1->x + v2->x), (v1->y + v2->y));
}


void Vec2_Sub(struct Vec2 *this, struct Vec2 v){
    this->x -= v.x;
    this->y -= v.y;
}

struct Vec2 *Vec2_Sub_Static(struct Vec2 *v1, struct Vec2 *v2){
    return New_Vec2((v1->x - v2->x), (v1->y - v2->y));
}

void Vec2_Scale(struct Vec2 *this, double number){
    this->x *= number;
    this->y *= number;
}

struct Vec2 *Vec2_Scale_Static(struct Vec2 *this, double number){
    return New_Vec2((this->x * number), (this->y * number));
}   

double Vec2_Dot_Product(struct Vec2 *v1, struct Vec2 *v2){
    return (v1->x * v2->x) + (v1->y * v2->y);
}