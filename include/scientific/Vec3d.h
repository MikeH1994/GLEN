#ifndef VEC3D_H
#define VEC3D_H

#include "VecXd.h"

class Vec3d : public VecXd{
private:
    double _arr[3];
public:
    Vec3d();
    Vec3d(double a, double b, double c);
    Vec3d(double* data);
    void cross(VecXd &other, VecXd &dst);
    void cross(VecXd &other);
};

#endif // VEC3D_H
