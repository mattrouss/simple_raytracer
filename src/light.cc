//
// Created by mattrouss on 2/14/20.
//

#include "light.hh"

#include <iostream>

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
