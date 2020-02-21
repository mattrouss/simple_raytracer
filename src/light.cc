//
// Created by mattrouss on 2/14/20.
//

#include "light.hh"

#include <iostream>

Color Color_Intensity::to_rgb() const {
    return {
            (uint8_t)std::clamp<float>(r * 255, 0, 255),
            (uint8_t)std::clamp<float>(g * 255, 0, 255),
            (uint8_t)std::clamp<float>(b * 255, 0, 255),
    };
}

Color_Intensity Color_Intensity::operator+=(const Color_Intensity &l) {
    r += l.r;
    g += l.g;
    b += l.b;
    return *this;
}

Color_Intensity Color_Intensity::operator+(const Color_Intensity &l) {
    *this += l;
    return *this;
}

std::ostream &operator<<(std::ostream &out, Color_Intensity &l) {
    return out << "Color_Intensity(r=" << l.r << ", g=" << l.g << ", b=" << l.b << ")";
}

Color_Intensity& Color_Intensity::add_diffuse(const float &kd,
                                             const Color &obj_color,
                                             const Light &light_source,
                                             const Vector3 &intersect_point,
                                             const Vector3 &N,
                                             const Vector3 &L) {
    float dot = kd * std::max(N.dot(L), 0.f);
    Color_Intensity light_colors = light_source.intensity_at(intersect_point);
    r += obj_color.r_intensity() * light_colors.r * dot;
    g += obj_color.g_intensity() * light_colors.g * dot;
    b += obj_color.b_intensity() * light_colors.b * dot;
    return *this;
}

Color_Intensity& Color_Intensity::add_specular(const float &ks, const float &ns,
                              const Light &light_source,
                              const Vector3 &intersect_point,
                              const Vector3 &S, const Vector3 &L) {
    float dot = std::max(S.dot(L), 0.f);
    dot = ks * powf(dot, ns);
    Color_Intensity light_colors = light_source.intensity_at(intersect_point);
    r +=  light_colors.r * dot;
    g +=  light_colors.g * dot;
    b +=  light_colors.b * dot;
    return *this;
}

Color_Intensity Light::intensity_at(const Vector3 &v) const {
    float dist = (org_ - v).magnitude();
    return {
        intensity_ * color_intensity_.r / dist,
        intensity_ * color_intensity_.g / dist,
        intensity_ * color_intensity_.b / dist
    };
}

Vector3 Point_Light::direction_from(const Vector3 &v) const {
    return (org_ - v).normalized();
}

Vector3 Point_Light::position() const {
    return org_;
}
