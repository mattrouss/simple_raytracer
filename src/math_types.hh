#pragma once

#include <ostream>
#include <cstdint>
#include <cmath>
#include <algorithm>

class Vector3;

struct Color
{
    uint8_t r, g, b;

    Color(uint8_t r_ = 0, uint8_t g_ = 0, uint8_t b_ = 0): r(r_), g(g_), b(b_) {}

    float r_intensity() const;
    float g_intensity() const;
    float b_intensity() const;

    friend std::ostream& operator<<(std::ostream &out, Color &c);
};

struct Light_Intensity
{
    float r, g, b;

    Light_Intensity(float r_ = 0, float g_ = 0, float b_ = 0): r(r_), g(g_), b(b_) {}

    Color to_rgb() const;
    friend std::ostream& operator<<(std::ostream &out, Color &c);
};

class Vector3
{
public:
    Vector3(float x = 0, float y = 0, float z = 0): x_(x), y_(y), z_(z) {}

    Vector3 operator+(const Vector3 &v) const;
    Vector3 operator-(const Vector3 &v) const;
    Vector3 operator*(const float &l) const;
    friend Vector3 operator*(const float &l, const Vector3 &v);
    Vector3 operator/(const float &l) const;

    float x() const;
    float y() const;
    float z() const;

    static Vector3 zeros();
    static Vector3 up();
    static Vector3 down();
    static Vector3 left();
    static Vector3 right();
    static Vector3 forward();
    static Vector3 backward();

    friend std::ostream& operator<<(std::ostream &out, const Vector3 &vec);

    float dot(const Vector3 &v) const;
    float sqr_magnitude() const;
    float magnitude() const;
    Vector3 cross(const Vector3 &v) const;
    Vector3 normalized() const;

private:
    float x_, y_, z_;
};

struct Ray
{
    Vector3 org;
    Vector3 dir;

    Ray(const Vector3 &org_, const Vector3 &dir_): org(org_), dir(dir_) {}

    Vector3 point_at_parameter(float t) const;

    friend std::ostream& operator<<(std::ostream &out, const Ray &r);
};

