//
// Created by mattrouss on 2/14/20.
//

#include "scene.hh"

#include <iostream>
#include <algorithm>
#include <cstdint>
#include <tuple>

bool cmp_dist(std::tuple<float, Object*> a, std::tuple<float, Object*> b)
{
    return std::get<0>(a) < std::get<0>(b);
}

Color Scene::cast_ray(const Ray &r) const {
    std::vector<std::tuple<float, Object*>> intersections;
    for(auto &o: objects_)
    {
        float t = o->intersects(r);
        if (t != -1)
            intersections.emplace_back(t, o);
    }
    if (intersections.empty()) {
        return Color(0, 0, 0);
    }
    std::sort(intersections.begin(), intersections.end(), cmp_dist);
    float dst = std::get<0>(intersections[0]);
    if (dst > 0)
    {
        auto [kd, kl, color] = std::get<1>(intersections[0])->get_texture_elms({0, 0, 0});
        float intensity_x = 0;
        float intensity_y = 0;
        float intensity_z = 0;
        Vector3 intersect_point = r.point_at_parameter(dst);
        for (auto &l: lights_)
        {
            Vector3 N = (intersect_point - std::get<1>(intersections[0])->origin()).normalized();
            Vector3 L = (l->origin() - intersect_point).normalized();
            intensity_x += kd * color.r_intensity() * l->color().r_intensity() * N.dot(L);
            intensity_y += kd * color.g_intensity() * l->color().r_intensity() * N.dot(L);
            intensity_z += kd * color.b_intensity() * l->color().r_intensity() * N.dot(L);

        }
        intensity_x = std::clamp<float>(intensity_x * 255, 0, 255);
        intensity_y = std::clamp<float>(intensity_y * 255, 0, 255);
        intensity_z = std::clamp<float>(intensity_z * 255, 0, 255);
        return Color((uint8_t) intensity_x, (uint8_t) intensity_y, (uint8_t) intensity_z);
    }
    return Color(0, 0, 0);
}

Image Scene::gen_img() const {
    Image im(img_width_, img_height_);
    for (int i = 0; i < img_height_; i++)
    {
        for (int j = 0; j < img_width_; j++)
        {
            Vector3 dir = tl_ + ((float)i / (float)img_height_) * screen_height_ * Vector3::down() + ((float)j / (float)img_width_) * screen_width_ * Vector3::right();
            dir = (dir - cam_.origin()).normalized();
            Color color = cast_ray({cam_.origin(), dir});
            im.set_pixel(i, j, color);
        }
    }
    return im;
}

void Scene::add_object(Object *o) {
    objects_.push_back(o);
}

void Scene::add_light_source(Light *l) {
    lights_.push_back(l);
}
