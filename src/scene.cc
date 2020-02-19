//
// Created by mattrouss on 2/14/20.
//

#include "scene.hh"

#include <iostream>
#include <algorithm>
#include <cstdint>
#include <tuple>
#include <limits>

bool cmp_dist(std::tuple<float, Object*> a, std::tuple<float, Object*> b)
{
    return std::get<0>(a) < std::get<0>(b);
}

std::tuple<Vector3, Object*> Scene::cast_ray(const Ray &r) const {
    Object *min = nullptr;
    Vector3 intersect_point = Vector3::zeros();
    float dist = 0;
    float min_dist = std::numeric_limits<float>::max();
    for(auto &o: objects_)
    {
        dist = o->intersects(r);
        if (dist == -1)
            continue;
        if (dist < min_dist)
        {
            min = o;
            min_dist = dist;
        }
    }
    if (min_dist > 0)
        intersect_point = r.point_at_parameter(min_dist);
    return std::make_tuple(intersect_point, min);
}

Image Scene::gen_img() const {
    Image im(img_width_, img_height_);
    for (int i = 0; i < img_height_; i++)
    {
        for (int j = 0; j < img_width_; j++)
        {
            Vector3 dir = tl_
                    + ((float)i / (float)img_height_) * screen_height_ * Vector3::down()
                    + ((float)j / (float)img_width_) * screen_width_ * Vector3::right();
            dir = (dir - cam_.origin()).normalized();
            auto [intersect_point, min] = cast_ray({cam_.origin(), dir});
            Color c(0, 0, 0);
            if (min != nullptr)
            {
                auto [kd, kl, color] = min->get_texture_elms({0, 0, 0});
                float intensity_x = 0;
                float intensity_y = 0;
                float intensity_z = 0;
                for (auto &l: lights_)
                {
                    Vector3 N = min->normal_of(intersect_point);
                    Vector3 L = l->direction_from(intersect_point);
                    intensity_x += kd * color.r_intensity() * l->intensity().r * N.dot(L);
                    intensity_y += kd * color.g_intensity() * l->intensity().g * N.dot(L);
                    intensity_z += kd * color.b_intensity() * l->intensity().b * N.dot(L);

                }
                intensity_x = std::clamp<float>(intensity_x * 255, 0, 255);
                intensity_y = std::clamp<float>(intensity_y * 255, 0, 255);
                intensity_z = std::clamp<float>(intensity_z * 255, 0, 255);
                c = Color((uint8_t) intensity_x, (uint8_t) intensity_y, (uint8_t) intensity_z);
            }
            im.set_pixel(i, j, c);
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
