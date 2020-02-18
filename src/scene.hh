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

        screen_width_ =  2 * z_min_ * tanf(c.fov_x() / 2);
        screen_height_ = 2 * z_min_ * tanf(c.fov_y() / 2);
        screen_center_ = c.origin() + z_min_ * (c.target() - c.origin()).normalized();

        tl_ = screen_center_ + (screen_width_ / 2) * Vector3::left() + (screen_height_ / 2) * Vector3::up();

        std::cout << "Screen width: " << screen_width_ << std::endl;
        std::cout << "Screen height: " << screen_height_ << std::endl;
        std::cout << "Screen center: " << screen_center_ << std::endl;
        std::cout << tl_ << std::endl;
    }
    Color cast_ray(const Ray &r) const;

    Image gen_img() const;

    void add_object(Object *o);
    void add_light_source(Light *l);

private:
    std::vector<Object *> objects_;
    std::vector<Light *> lights_;

    Camera cam_;
    Vector3 screen_center_, tl_;
    float screen_width_,
        screen_height_,
        z_min_;
    int img_width_, img_height_;
};

