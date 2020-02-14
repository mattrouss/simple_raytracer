//
// Created by mattrouss on 2/14/20.
//

#ifndef TP1_RAYTRACER_TEXTURES_HH
#define TP1_RAYTRACER_TEXTURES_HH

#include <tuple>

#include "math_types.hh"

class Texture_Material
{
public:
    Texture_Material(float kd = 0, float ks = 0): kd_(kd), ks_(ks) {}

    virtual std::tuple<float, float> get_texture_elms(const Point3 &p) const = 0;

protected:
    float kd_, ks_;
};

class Uniform_Texture : public Texture_Material
{
public:
    std::tuple<float, float> get_texture_elms(const Point3 &p = {0, 0, 0}) const override;
};


#endif //TP1_RAYTRACER_TEXTURES_HH
