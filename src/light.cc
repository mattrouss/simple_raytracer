//
// Created by mattrouss on 2/14/20.
//

#include "light.hh"

Color Light::color() const {
    return color_;
}

Vector3 Point_Light::direction_from(const Vector3 &v) const {
    return (org_ - v).normalized();
}
