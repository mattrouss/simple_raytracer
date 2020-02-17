//
// Created by mattrouss on 2/14/20.
//
#pragma once

#include <vector>
#include <iostream>

#include "object.hh"
#include "light.hh"
#include "camera.hh"
#include "image.hh"

class Scene {
public:
    Scene(const Camera &c, int img_width, int img_height):
    cam_(c),
    img_width_(img_width),
    img_height_(img_height)
    {
        z_min_ = c.z_min();

        screen_width_ =  2 * c.z_min() * tanf(c.fov_x());
        screen_height_ = 2 * c.z_min() * tanf(c.fov_y());
        screen_center_ = c.origin() + ((c.target() - c.origin()).normalize() * c.z_min());

        tl_ = screen_center_ + (screen_width_ / 2) * Vector3::left() + (screen_height_ / 2) * Vector3::up();
    }
    Color cast_ray(const Ray &r) const;

    Image gen_img() const;

    void add_object(Object *o);

private:
    std::vector<Object *> objects_;
    std::vector<Light> lights_;

    Camera cam_;
    Vector3 screen_center_, tl_;
    float screen_width_,
        screen_height_,
        z_min_;
    int img_width_, img_height_;
};

