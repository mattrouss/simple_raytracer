//
// Created by mattrouss on 2/14/20.
//

#include <cmath>
#include <iostream>

#include "object.hh"

#define EPSILON 1e-6

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

std::tuple<float, float, float, float, Color> Sphere::get_texture_elms(const Vector3 &p) const {
    return texture_.get_texture_elms(p);
}

float Plane::intersects(const Ray &r) const {
    float denom = normal_.dot(r.dir);
    float distance = (org_ - r.org).dot(normal_) / denom;
    if (distance >= 0)
        return distance;
    return -1;
}

Vector3 Plane::normal_of(const Vector3 &v) const {
    return normal_;
}

std::tuple<float, float, float, float, Color>
Plane::get_texture_elms(const Vector3 &p) const {
    return texture_.get_texture_elms(p);
}

float Triangle::intersects(const Ray &r) const {

    Vector3 edge1, edge2, h, s, q;
    float a,f,u,v;
    edge1 = b_ - a_;
    edge2 = c_ - a_;
    h = r.dir.cross(edge2);
    a = edge1.dot(h);
    if (a > -EPSILON && a < EPSILON)
        return -1;    // Ray is parallel to triangle

    f = 1.0f/a;
    s = r.org - a_;
    u = f * (s.dot(h));
    if (u < 0.0 || u > 1.0)
        return -1;
    q = s.cross(edge1);
    v = f * r.dir.dot(q);
    if (v < 0.0 || u + v > 1.0)
        return -1;

    float t = f * edge2.dot(q);
    if (t > EPSILON)
        return t;
    else
        return -1;
}

Vector3 Triangle::normal_of(const Vector3 &v) const {
    return normal_;
}

std::tuple<float, float, float, float, Color>
Triangle::get_texture_elms(const Vector3 &p) const {
    return texture_.get_texture_elms(p);
}
