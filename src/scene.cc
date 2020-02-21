//
// Created by mattrouss on 2/14/20.
//

#include "scene.hh"

#include <iostream>
#include <algorithm>
#include <cstdint>
#include <tuple>
#include <limits>

#define INTERSECT_DELTA 1e-4

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
    intersect_point = r.point_at_parameter(min_dist);
    return std::make_tuple(intersect_point, min);
}

Light_Intensity Scene::get_diffuse(const Vector3 &intersect_point,
                                   const Object *obj) const {
    Light_Intensity diffuse;
    auto [kd, kl, color] = obj->get_texture_elms(intersect_point);
    for (auto &l: lights_)
    {
        Vector3 N = obj->normal_of(intersect_point);
        Vector3 L = l->direction_from(intersect_point);
        auto [light_intersect, intersect_obj] = cast_ray({intersect_point + (INTERSECT_DELTA * N), L});
        if (intersect_obj != nullptr && (light_intersect - intersect_point).sqr_magnitude() < (l->position() - intersect_point).sqr_magnitude())
            continue;
        float dot = N.dot(L);
        diffuse.r += kd * color.r_intensity() * l->intensity().r * dot;
        diffuse.g += kd * color.g_intensity() * l->intensity().g * dot;
        diffuse.b += kd * color.b_intensity() * l->intensity().b * dot;
    }
    return diffuse;
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
                Light_Intensity pixel_intensity;
                pixel_intensity += get_diffuse(intersect_point, min);
                c = pixel_intensity.to_rgb();
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
