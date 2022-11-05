#ifndef CPP_TRAININGS_VEC3D_H
#define CPP_TRAININGS_VEC3D_H

#include <ostream>

class Vec3d {
private:
    double x = 0, y = 0, z = 0;
public:
    Vec3d() = default;
    Vec3d(double x_, double y_, double z_) : x(x_), y(y_), z(z_) {};
    Vec3d(Vec3d &v) = default;

    Vec3d operator+(Vec3d &v) const {
        return {x + v.x, y + v.y, z + v.z};
    }
    Vec3d operator*(double c) const {
        return {c * x, c * y, c * z};
    }
    double operator*(Vec3d &v) const {
        return x * v.x + y * v.y + z * v.z;
    }
    Vec3d operator &(Vec3d &v) const {
        return {y * v.z - z * v.y, z * v.x - x * v.z, x * v.y - y * v.x};
    }

    friend std::ostream &operator<<(std::ostream &os, const Vec3d &d) {
        os << "(" << d.x << ", " << d.y << ", " << d.z << ")";
        return os;
    }
};

#endif //CPP_TRAININGS_VEC3D_H
