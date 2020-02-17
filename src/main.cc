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
    Vector3 p = Vector3(1, 2, 3);
    Vector3 q = Vector3(1, 2, 3);
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
    float fov_x = 1.f;
    float fov_y = 1.f;
    Camera c({0, 0, 0}, {0, 0, z_min}, Vector3::up(), fov_x, fov_y, z_min);

    Scene s(c, 1024, 1024);

    Uniform_Texture ut_pink(1, 1, Color(255, 0, 150));
    Uniform_Texture ut_green(1, 1, Color(0, 200, 0));
    s.add_object(new Sphere(5, {0, 10, 30}, ut_pink));
    s.add_object(new Sphere(20, {0, 0, 60}, ut_green));
    s.add_light_source(new Point_Light(Color(255, 255, 255), Vector3(20, 10, 10)));

    Image im = s.gen_img();

    im.dump_ppm("out.ppm");

    return 0;
}
