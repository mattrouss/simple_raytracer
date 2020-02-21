//
// Created by mattrouss on 2/14/20.
//
#pragma once

#include "math_types.hh"
#include "object.hh"
#include "color.hh"


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
