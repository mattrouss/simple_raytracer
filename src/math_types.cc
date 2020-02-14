#include "math_types.hh"



std::ostream &operator<<(std::ostream &out, Color &c) {
    return out << "Color(r=" << c.r << ", g=" << c.g << ", b=" << ")";
}


Vector3 Point3::operator+(const Point3 &p) const {
    return {
        x_ + p.x_,
        y_ + p.y_,
        z_ + p.z_
    };
}

Vector3 Point3::operator-(const Point3 &p) const {
    return {
            x_ - p.x_,
            y_ - p.y_,
            z_ - p.z_
    };
}

std::ostream& operator<<(std::ostream &out, Point3 &p) {
    return out << "Point3(" << p.x_ << ", " << p.y_ << ", " << p.z_ << ")";
}


Vector3 Vector3::operator+(const Vector3 &v) const {
    return {
            this->x_ + v.x_,
            this->y_ + v.y_,
            this->z_ + v.z_
    };
}

Vector3 Vector3::operator*(const float &l) const {
    return {
        this->x_ * l,
        this->y_ * l,
        this->z_ * l
    };
}

Vector3 Vector3::operator-(const Vector3 &v) const {
    return {
        this->x_ - v.x_,
        this->y_ - v.y_,
        this->z_ - v.z_
    };
}

float Vector3::dot(const Vector3 &v) const {
    return this->x_ * v.x_ + this->y_ * v.y_ + this->z_ * v.z_;
}

float Vector3::sqr_magnitude() const {
    return this->dot(*this);
}

Vector3 Vector3::cross(const Vector3 &v) const {
    return {
            this->y_ * v.z_ - this->z_ * v.y_,
            this->z_ * v.x_ - this->x_ * v.z_,
            this->x_ * v.y_ - this->y_ * v.x_
    };
}

std::ostream& operator<<(std::ostream &out, Vector3 &vec) {
    return out << "Vector3(" << vec.x_ << ", " << vec.y_ << ", " << vec.z_ << ")";
}
