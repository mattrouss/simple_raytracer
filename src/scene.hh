//
// Created by mattrouss on 2/14/20.
//
#pragma once

#include <vector>

#include "object.hh"
#include "light.hh"
#include "camera.hh"

class Scene {
public:
    Scene(const Camera &c): cam_(c) {}
    Color cast_ray(const Vector3 &dir);

    void add_object(Sphere o);

private:
    std::vector<Sphere> objects_;
    std::vector<Light> lights_;

    Camera cam_;
    float z_min_;
};

