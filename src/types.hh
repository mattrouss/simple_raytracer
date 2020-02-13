#include <ostream>
#include <cstdint>

struct Color
{
    uint8_t r, g, b;

    Color(uint8_t r_, uint8_t g_, uint8_t b_): r(r_), g(g_), b(b_) {}

    friend std::ostream& operator<<(std::ostream &out, Color &c);
};

class Point3
{
    public:
        Point3(float x, float y, float z): x_(x), y_(y), z_(z) {}

        Point3 operator+(const Point3 &p) const;

        friend std::ostream& operator<<(std::ostream &out, Point3 &p);

    private:
        float x_, y_, z_;
};

class Vector3
{
    public:
        Vector3(float x, float y, float z): x_(x), y_(y), z_(z) {}

        Vector3 operator+(const Vector3 &v) const;
        Vector3 operator*(const float &l) const;
        Vector3 operator-(const Vector3 &v) const;

        friend std::ostream& operator<<(std::ostream &out, Vector3 &vec);

        float dot(const Vector3 &v) const;
        Vector3 cross(const Vector3 &v) const;

private:
        float x_, y_, z_;
};
