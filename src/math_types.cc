#include "math_types.hh"


Vector3& Vector3::operator+=(const Vector3 &v) {
    x_ += v.x_;
    y_ += v.y_;
    z_ += v.z_;

    return *this;
}

Vector3& Vector3::operator-=(const Vector3 &v) {
    x_ -= v.x_;
    y_ -= v.y_;
    z_ -= v.z_;

    return *this;
}

Vector3& Vector3::operator*=(const float &l) {
    x_ *= l;
    y_ *= l;
    z_ *= l;

    return *this;
}

Vector3&  Vector3::operator/=(const float &l) {
    x_ /= l;
    y_ /= l;
    z_ /= l;

    return *this;
}


Vector3 operator*(const float &l, Vector3 v) {
    return v *= l;
}

Vector3 operator*(Vector3 v, const float &l) {
    return v *= l;
}

Vector3 operator/(const float &l, Vector3 v) {
    return v /= l;
}

Vector3 operator/(Vector3 v, const float &l) {
    return v /= l;
}

float Vector3::x() const {
    return x_;
}

float Vector3::y() const {
    return y_;
}

float Vector3::z() const {
    return z_;
}

float Vector3::dot(const Vector3 &v) const {
    return x_ * v.x_ + y_ * v.y_ + z_ * v.z_;
}

float Vector3::sqr_magnitude() const {
    return this->dot(*this);
}

float Vector3::magnitude() const {
    return std::sqrt(sqr_magnitude());
}

Vector3 Vector3::cross(const Vector3 &v) const {
    return {
            y_ * v.z_ - z_ * v.y_,
            z_ * v.x_ - x_ * v.z_,
            x_ * v.y_ - y_ * v.x_
    };
}

Vector3 Vector3::normalized() const {
    Vector3 copy = *this;
    copy /= magnitude();
    return copy;
}


std::ostream& operator<<(std::ostream &out, const Vector3 &vec) {
    return out << "Vector3(" << vec.x_ << ", " << vec.y_ << ", " << vec.z_ << ")";
}

Vector3 Vector3::zeros() {
    return Vector3(0, 0, 0);
}

Vector3 Vector3::up() {
    return Vector3(0, 1, 0);
}

Vector3 Vector3::down() {
    return Vector3(0, -1, 0);
}

Vector3 Vector3::left() {
    return Vector3(1, 0, 0);
}

Vector3 Vector3::right() {
    return Vector3(-1, 0, 0);
}

Vector3 Vector3::forward() {
    return Vector3(0, 0, 1);
}

Vector3 Vector3::backward() {
    return Vector3(0, 0, -1);
}

Vector3 Vector3::diagXY() {
    return Vector3(1, 1, 0);
}

Vector3 Vector3::diagYZ() {
    return Vector3(0, 1, 1);
}

Vector3 Vector3::diagXZ() {
    return Vector3(1, 0, 1);
}

Vector3 Vector3::diagXYZ() {
    return Vector3(1, 1, 1);
}

void Vector3::add_x(const float x) {
    x_ += x;
}

void Vector3::add_y(const float y) {
    y_ += y;
}

void Vector3::add_z(const float z) {
    z_ += z;
}

std::ostream &operator<<(std::ostream &out, const Ray &r) {

    out << "Ray (Origin: " << r.org;
    out << ", Direction: " << r.dir << ")" << std::endl;
    return out;
}

Vector3 Ray::point_at_parameter(float t) const {
    return org + t * dir;
}
