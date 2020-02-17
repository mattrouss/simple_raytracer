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
    float z_min = 10;
    float fov_x = 1;
    float fov_y = 1;
    Camera c({0, 0, 0}, {0, 0, z_min}, {0, 1, 0}, fov_x, fov_y, z_min);

    Scene s(c);

    Uniform_Texture ut(1, 1, {255, 0, 0});
    s.add_object(Sphere(20, {0, 0, 50}, ut));

    float screen_width =  2 * z_min * std::tan(fov_x);
    float screen_height = 2 * z_min * std::tan(fov_y);

    int img_size = 1024;
    Image im(img_size, img_size);
    float pix_size = screen_width / img_size;
    for (int i = 0; i < img_size; i++)
    {
        for (int j = 0; j < img_size; j++)
        {
            float z_pixel = z_min;
            float x_pixel = 0 - (screen_width / 2) + j * pix_size;
            float y_pixel = 0 - (screen_height / 2) + i * pix_size;

            Color color = s.cast_ray({x_pixel, y_pixel, z_pixel});
            im.set_pixel(i, j, color);
        }
    }

    im.dump_ppm("out.ppm");


    return 0;
}
