#ifndef HELPER_H
#define HELPER_H

#include "stdafx.h"
#include "Triangle.h"

class Helper{
public:
    static void rotateVectorAroundAxis(Vec3d &vec, Vec3d &axis, Vec3d &dst, double theta);
    static void getXAxis();
    static void getYAxis();
    static void getZAxis();

    static std::vector<Triangle> cloneTriangles(std::vector<Triangle> &vector);
    static double degreesToRadians(double degrees);
    static double radiansToDegrees(double radians);

};

#endif // HELPER_H
