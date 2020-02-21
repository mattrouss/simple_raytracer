//
// Created by mattrouss on 2/14/20.
//
#pragma once

#include "math_types.hh"
#include "object.hh"

class Light;

struct Color_Intensity
{
    float r, g, b;

    Color_Intensity(float r_ = 0, float g_ = 0, float b_ = 0): r(r_), g(g_), b(b_) {}

    Color_Intensity operator+=(const Color_Intensity &l);
    Color_Intensity operator+(const Color_Intensity &l);

    Color_Intensity& add_diffuse(const float &kd, const Color &obj_color,
            const Light &light_source,
            const Vector3 &intersect_point,
            const Vector3 &N,
            const Vector3 &L);

    Color_Intensity& add_specular(const float &ks,
            const float &ns,
            const Light &light_source,
            const Vector3 &intersect_point,
            const Vector3 &S, const Vector3 &L);

    Color to_rgb() const;

    friend std::ostream& operator<<(std::ostream &out, Color_Intensity &l);
};

class Light {
public:
    explicit Light(const float &intensity, const Color_Intensity &color_intensity, const Vector3 &org):
    intensity_(intensity), color_intensity_(color_intensity), org_(org){}

    virtual Vector3 direction_from(const Vector3 &v) const = 0;
    Color_Intensity intensity_at(const Vector3 &v) const;
    virtual Vector3 position() const = 0;

protected:
    float intensity_;
    Color_Intensity color_intensity_;
    Vector3 org_;
};

class Point_Light: public Light
{
public:
    Point_Light(const float &intensity, const Color_Intensity &color_intensity, const Vector3 &org): Light(intensity, color_intensity, org) {}

    Vector3 direction_from(const Vector3 &v) const override;
    Vector3 position() const override;
private:
};
