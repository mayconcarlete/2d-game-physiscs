#ifndef VEC2_H
#define VEC2_H

struct  Vec2 {
    double x;
    double y;
};

struct Vec2 *New_Vec2(double x, double y);
void Free_Vec2(struct Vec2 *this);
void Vec2_Print(struct Vec2 *this);

double Vec2_Magnitude(struct Vec2 *this);

void Vec2_Add(struct Vec2 *this, struct Vec2 v);
struct Vec2 *Vec2_Add_Static(struct Vec2 *v1, struct Vec2 *v2);

void Vec2_Sub(struct Vec2 *this, struct Vec2 v);
struct Vec2 *Vec2_Sub_Static(struct Vec2 *v1, struct Vec2 *v2);

void Vec2_Scale(struct Vec2 *this, double number);
struct Vec2 *Vec2_Scale_Static(struct Vec2 *this, double number);

/*
*****Dot Product or Scalar product*****
Pense como se fosse o quão alinhado os vetores estão, ou quanta "sombra" o vetor2 faz sobre o vetor1.
Se eles forem paralelos o valor é 1.
Se eles forem perpendiculares o valor é 0;
Se eles forem contrarios(negativos) o valor vai tendendo para -1.
*/
double Vec2_Dot_Product(struct Vec2 *v1, struct Vec2 *v2);

#endif