#ifndef VEC2_H
#define VEC2_H

class Vec2 {
  private:
  public:
    Vec2();
    Vec2(float x, float y);
    ~Vec2() = default;
    float x;
    float y;
    float GetX() const;
    float GetY() const;
    void SetX(float x);
    void SetY(float y);
    void Print() const;
    void Add(const Vec2& v);
    void Sub(const Vec2& v);
    void Scale(const float n);
    Vec2 Rotate(const float angle) const;

    float Magnitude() const;
    float MagnitudeSquared() const;

    Vec2& Normalize();
    Vec2 UnitVector() const;
    Vec2 Normal() const;

    float Dot(const Vec2& v) const;
    float Cross(const Vec2& v) const;
    Vec2& operator = (const Vec2& v); // v1 = v2
    bool operator == (const Vec2& v) const; // v1 == v2
    bool operator != (const Vec2& v) const; // v1 != v2

    Vec2 operator + (const Vec2& v) const; // v1 + v2
    Vec2 operator - (const Vec2& v) const; // v1 - v2
    Vec2 operator * (const float n) const; // v1 * n
    Vec2 operator / (const float n) const; // v1 / n
    Vec2 operator - (); // -v1

    Vec2& operator += (const Vec2& v); // v1 += v2
    Vec2& operator -= (const Vec2& v); // v1 -= v2
    Vec2& operator *= (const float n); // v1 *= n
    Vec2& operator /= (const float n); // v1 /= n
};

#endif