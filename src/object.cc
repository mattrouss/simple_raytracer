//
// Created by mattrouss on 2/14/20.
//

#include <cmath>
#include <iostream>

#include "object.hh"

float Sphere::intersects(const Ray &r) const {
    Vector3 oc = r.org - org_;
    float a = r.dir.sqr_magnitude();
    float b = 2.0f * oc.dot(r.dir);
    float c = oc.sqr_magnitude() - r_ * r_;

    float discriminant = b*b - 4*a*c;
    if (discriminant < 0)
        return - 1;
    float dist = (-b - std::sqrt(discriminant)) / (2.0f * a);
    if (dist < 0)
        return -1;
    return dist;
}

Vector3 Sphere::normal_of(const Vector3 &v) const {
    return (v - org_).normalized();
}

std::tuple<float, float, float, Color> Sphere::get_texture_elms(const Vector3 &p) const {
    return texture_.get_texture_elms(p);
}
