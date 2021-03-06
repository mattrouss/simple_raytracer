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
#include "blob.hh"

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

    }

    ~Scene()
    {
        for (Object *obj: objects_)
            delete obj;
        for (Light *l: lights_)
            delete l;
    }
    std::tuple<Vector3, Object*> cast_ray(const Ray &r) const;
    Color_Intensity get_Color_Intensity(const Ray &ray,
            const Vector3 &intersect_point,
            const Object *obj,
            Color_Intensity &color_intensity,
            int depth) const;

    Color_Intensity trace_reflection_rec(const Ray &r, Color_Intensity &color_intensity, int depth) const;

    void init_blobs(float S);
    Image gen_img() const;

    void add_object(Object *o);
    void add_blob(const Blob &b);
    void add_light_source(Light *l);

private:
    std::vector<Object *> objects_;
    std::vector<Blob> blobs_;
    std::vector<Light *> lights_;

    Camera cam_;
    Vector3 screen_center_, tl_;
    float screen_width_,
        screen_height_,
        z_min_;
    int img_width_, img_height_;
};

