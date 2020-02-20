//
// Created by mattrouss on 2/14/20.
//
#pragma once

#include "math_types.hh"
#include "object.hh"

class Light;

struct Light_Intensity
{
    float r, g, b;

    Light_Intensity(float r_ = 0, float g_ = 0, float b_ = 0): r(r_), g(g_), b(b_) {}

    Light_Intensity operator+(const Light_Intensity &l);
    Light_Intensity operator+=(const Light_Intensity &l);

    Color to_rgb() const;

    friend std::ostream& operator<<(std::ostream &out, Light_Intensity &l);
};

class Light {
public:
    explicit Light(const Light_Intensity &intensity, const Vector3 &org): intensity_(intensity), org_(org){}

    virtual Vector3 direction_from(const Vector3 &v) const = 0;
    Light_Intensity intensity() const;
    virtual Vector3 position() const = 0;

protected:
    Light_Intensity intensity_;
    Vector3 org_;
};

class Point_Light: public Light
{
public:
    Point_Light(const Light_Intensity &intensity, const Vector3 &org): Light(intensity, org) {}

    Vector3 direction_from(const Vector3 &v) const override;
    Vector3 position() const override;
private:
};
