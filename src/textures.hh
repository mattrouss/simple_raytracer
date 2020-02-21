//
// Created by mattrouss on 2/14/20.
//
#pragma once

#include <tuple>

#include "math_types.hh"
#include "color.hh"

class Texture_Material
{
public:
    explicit Texture_Material(float kd = 0, float ks = 0, float ns = 0, float reflectivity = 0):
    kd_(kd), ks_(ks), ns_(ns), reflectivity_(reflectivity) {}

    virtual std::tuple<float, float, float, float, Color> get_texture_elms(const Vector3 &p) const = 0;

protected:
    float kd_, ks_, ns_, reflectivity_;
};

class Uniform_Texture : public Texture_Material
{
public:
    Uniform_Texture(float kd, float ks, float ns, float reflectivity, const Color &color): Texture_Material(kd, ks, ns, reflectivity), color_(color) {}
    std::tuple<float, float, float, float, Color> get_texture_elms(const Vector3 &p) const override;

private:
    Color color_;
};


