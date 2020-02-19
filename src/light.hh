//
// Created by mattrouss on 2/14/20.
//
#pragma once

#include "math_types.hh"

class Light {
public:
    explicit Light(const Light_Intensity &intensity): intensity_(intensity) {}

    virtual Vector3 direction_from(const Vector3 &v) const = 0;
    Light_Intensity intensity() const;

protected:
    Light_Intensity intensity_;
};

class Point_Light: public Light
{
public:
    Point_Light(const Light_Intensity &intensity, const Vector3 &org): Light(intensity), org_(org) {}

    Vector3 direction_from(const Vector3 &v) const override;
private:
    Vector3 org_;
};
