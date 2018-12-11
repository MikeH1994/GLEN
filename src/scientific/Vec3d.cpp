#include "Vec3d.h"

Vec3d::Vec3d(){
    _deleteOnDeconstructor = false;
    _length = 3;
    _arr[0] = 0;
    _arr[1] = 0;
    _arr[2] = 0;
    _data = _arr;
}

Vec3d::Vec3d(double a, double b, double c){
    _deleteOnDeconstructor = false;
    _length = 3;
    _arr[0] = a;
    _arr[1] = b;
    _arr[2] = c;
    _data = _arr;
}

Vec3d::Vec3d(double* data){
    _deleteOnDeconstructor = false;
    _length = 3;
    _data = data;
}


void Vec3d::cross(VecXd &other, VecXd &dst){
    double x,y,z;
    double a1 = _data[0],a2 = _data[1],a3 = _data[2];
    double b1 = other[0],b2 = other[1],b3 = other[2];
    x = a2*b3 - a3*b2;
    y = a3*b1 - a1*b3;
    z = a1*b2 - a2*b1;
    dst[0] = x;
    dst[1] = y;
    dst[2] = z;
}

void Vec3d::cross(VecXd &other){
    cross(other,*this);
}
