//
// Created by mattrouss on 2/14/20.
//

#include "scene.hh"

#include <iostream>

Color Scene::cast_ray(const Ray &r) const {
    for(auto &o: objects_)
    {
        if (o->intersects(r) != -1)
        {
            std::cout << r << std::endl;
            auto [kd, kl, color] = o->get_texture_elms({0, 0, 0});
            return color;
        }
    }
    return Color(0, 0, 0);
}

void Scene::add_object(Object *o) {
    objects_.push_back(o);
}

Image Scene::gen_img() const {
    Image im(img_width_, img_height_);
    for (int i = 0; i < img_height_; i++)
    {
        for (int j = 0; j < img_width_; j++)
        {
            Vector3 dir = tl_ + (i / screen_height_) * Vector3::down() + (j / screen_width_) * Vector3::right();
            Color color = cast_ray({cam_.origin(), dir});
            im.set_pixel(i, j, color);
        }
    }
    return im;
}
