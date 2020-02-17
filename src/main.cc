#include <iostream>
#include <cmath>

#include "math_types.hh"
#include "object.hh"
#include "image.hh"
#include "camera.hh"
#include "scene.hh"

int main(int argc, char* argv[])
{
    /*
    Point3 p = Point3(1, 2, 3);
    Point3 q = Point3(1, 2, 3);
    p = p + q;
    std::cout << p << "\n";

    Vector3 v = Vector3(2, 4, 6);
    std::cout << v.dot(v) << "\n";
    Image im = Image::test_image();
    Sphere sp(15, {10, 10, 10});

    Ray r({0, 0, 0}, {1, 1, 1});

    std::cout << sp.intersects(r);
    */
    float z_min = 1.f;
    float fov_x = 2.f;
    float fov_y = 2.f;
    Camera c({0, 0, 0}, {0, 0, z_min}, Vector3::up(), fov_x, fov_y, z_min);

    Scene s(c, 500, 500);

    Uniform_Texture ut(1, 1, {255, 0, 0});
    s.add_object(new Sphere(15, {0, 20, 20}, ut));

    Image im = s.gen_img();

    im.dump_ppm("out.ppm");


    return 0;
}
