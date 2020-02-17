//
// Created by mattrouss on 2/14/20.
//

#include <cmath>

#include "object.hh"

float Sphere::intersects(const Ray &r) const {
    Vector3 oc = r.org - org_;
    float a = r.dir.dot(r.dir);
    float b = 2.0f * oc.dot(r.dir);
    float c = oc.sqr_magnitude() - r_ * r_;

    float discriminant = b*b - 4*a*c;
    if (discriminant < 0)
        return - 1;
    return (-b - std::sqrt(discriminant)) / (2.0f * a);
}

Vector3 Sphere::normal_of(Point3 &p) {
    return p - org_;
}

std::tuple<float, float, Color> Sphere::get_texture_elms(const Point3 &p) {
    return texture_.get_texture_elms();
}
