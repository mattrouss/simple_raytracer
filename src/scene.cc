//
// Created by mattrouss on 2/14/20.
//

#include "scene.hh"

#include <iostream>

Color Scene::cast_ray(const Vector3 &dir) {
    for(auto &o: objects_)
    {
        if (o.intersects({{0, 0, 0}, dir}) != -1)
        {
            auto [kd, kl, color] = o.get_texture_elms({0, 0, 0});
            return color;
        }
    }
    return Color(0, 0, 0);
}

void Scene::add_object(Sphere o) {
    objects_.push_back(o);
}
