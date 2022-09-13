#include "Vec2.h"
#include <math.h>
#include <iostream>

Vec2::Vec2():x(0.0), y(0.0){}

Vec2::Vec2(float x, float y){
  this->x = x;
  this->y = y;
}

void Vec2::Print()const{
  std::cout << "X: " << this->x << std::endl;
  std::cout << "Y: " << this->y << std::endl;
}

void Vec2::Add(const Vec2& v){
  this->x += v.x;
  this->y += v.y;
}

void Vec2::Sub(const Vec2& v){
  this->x -= v.x;
  this->y -= v.y;
}

void Vec2::Scale(const float n){
  this->x *= n;
  this->y *= n;
}

Vec2 Vec2::Rotate(const float angle) const{
  Vec2 Result;
  Result.x = this->x * cos(angle) - this->y * sin(angle);
  Result.y = this->x * sin(angle) + this->y * cos(angle);
  return Result;
}

float Vec2::Magnitude()const {
  return sqrtf(this->x * this->x + this->y * this->y);
}

float Vec2::MagnitudeSquared() const{
  return (this->x * this->x + this->y * this->y);
}

Vec2& Vec2::Normalize(){
  float length = this->MagnitudeSquared();
  if(length != 0.0){
    this->x /= length;
    this->y /= length;
  }
  return *this;
}

// Vec2 Vec2::Rotate(const float angle) const {
//   Vec2 Result;
//   Result.x = x * cos(angle) - y * sin(angle);
//   Result.y = x * sin(angle) + y * cos(angle);
//   return Result;
// }

// float Vec2::Magnitude() const {
//   return sqrtf(x * x + y * y);
// }

// float Vec2::MagnitudeSquared() const {
//   return (x * x + y * y);
// }

// Vec2& Vec2::Normalize(){
//   float length = Magnitude();
//   if(length != 0.0){
//     x /= length;
//     y /= length;
//   }
//   return *this;
// }

// Vec2 Vec2::UnitVector() const {
//   float length = Magnitude();
//   Vec2 result = Vec2(0, 0);
//   if(length != 0.0){
//     result.x = x / length;
//     result.y = y / length;
//   }
//   return result;
// }

// Vec2 Vec2::Normal() const {
//   return Vec2(y, -x).Normalize();
// }

// float Vec2::Dot(const Vec2& v) const {
//   return (x * v.x) + (y * v.y);
// }

// float Vec2::Cross(const Vec2& v) const {
//   return (x * v.y) - (y * v.x);
// }

// Vec2& Vec2::operator =  (const Vec2& v){
//   x = v.x;
//   y = v.y;
//   return *this;
// }

// bool Vec2::operator == (const Vec2& v) const {
//   return x == v.x && y == v.y;
// }

// bool Vec2::operator != (const Vec2& v) const {
//   return !(*this == v);
// }

// Vec2 Vec2::operator + (const Vec2& v) const {
//   Vec2 result;
//   result.x = x + v.x;
//   result.y = y + v.y;
//   return result;
// }

// Vec2 Vec2::operator - (const Vec2& v) const {
//   Vec2 result;
//   result.x = x - v.x;
//   result.y = y - v.y;
//   return result;
// }

// Vec2 Vec2::operator * (const float n) const {
//   Vec2 result;
//   result.x = x * n;
//   result.y = y * n;
//   return result;
// }

// Vec2 Vec2::operator / (const float n) const {
//   Vec2 result;
//   result.x = x / n;
//   result.y = y / n;
//   return result;
// }

// Vec2& Vec2::operator += (const Vec2& v) {
//   x += v.x;
//   y += v.y;
//   return *this;
// }

// Vec2& Vec2::operator -= (const Vec2& v){
//   x -= v.x;
//   y -= v.y;
//   return *this;
// }

// Vec2& Vec2::operator *= (const float n) {
//   x *= n;
//   y *= n;
//   return *this;
// }

// Vec2& Vec2::operator /= (const float n){
//   x /= n;
//   y /= n;
//   return *this;
// }

// Vec2 Vec2::operator - (){
//   Vec2 result;
//   result.x = x * -1;
//   result.y = y * -1;
//   return result;
// }