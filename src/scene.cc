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
#define REFLECTION_DEPTH 0

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

Color_Intensity Scene::get_Color_Intensity(const Ray &ray,
        const Vector3 &intersect_point,
        const Object *obj,
        Color_Intensity &color_intensity,
        int depth) const {
    auto [kd, ks, ns, reflectivity, color] = obj->get_texture_elms(intersect_point);
    Vector3 N = obj->normal_of(intersect_point);
    Vector3 S = (ray.dir - (2 * ray.dir.dot(N) * N)).normalized();
    for (auto &l: lights_)
    {
        Vector3 L = l->direction_from(intersect_point);
        auto [light_intersect, intersect_obj] = cast_ray({intersect_point + (INTERSECT_DELTA * N), L});
        if (intersect_obj != nullptr && (light_intersect - intersect_point).sqr_magnitude() < (l->position() - intersect_point).sqr_magnitude())
            continue;

        Color_Intensity light_colors = l->intensity_at(intersect_point);
        color_intensity.add_diffuse(kd, color, light_colors, N, L);
        color_intensity.add_specular(ks, ns, light_colors, S, L);

        Ray reflect_ray(intersect_point, S);
        if (depth < REFLECTION_DEPTH)
        {
            auto [reflect_intersect, reflect] = cast_ray(reflect_ray);
            if (reflect == nullptr)
                return color_intensity;
            color_intensity +=  reflectivity * get_Color_Intensity(reflect_ray, reflect_intersect, reflect, color_intensity, depth + 1);
        }
    }
    return color_intensity;
}

Color_Intensity Scene::trace_reflection_rec(const Ray &ray,
        Color_Intensity &color_intensity,
        int depth) const {
    auto [reflect_intersect, reflect] = cast_ray(ray);
    if (reflect == nullptr)
        return color_intensity;
    Vector3 N = reflect->normal_of(reflect_intersect);
    Vector3 S_rec = (ray.dir - (2 * ray.dir.dot(N) * N)).normalized();
    auto [kd, ks, ns, reflectivity, color] = reflect->get_texture_elms(reflect_intersect);
    color_intensity += color.to_intensity();

    return trace_reflection_rec({reflect_intersect, S_rec}, color_intensity, depth + 1);
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
            Ray ray(cam_.origin(), dir);
            auto [intersect_point, min] = cast_ray(ray);
            Color c(0, 0, 0);
            if (min != nullptr)
            {
                Color_Intensity acc(0, 0, 0);
                Color_Intensity pixel_intensity = get_Color_Intensity(ray, intersect_point, min, acc, 0);
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
