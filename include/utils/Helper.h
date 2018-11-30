#ifndef HELPER_H
#define HELPER_H

#include "stdafx.h"
#include "Triangle.h"

class Helper{
public:
    static Eigen::Vector3d cloneVector3d(Eigen::Vector3d &vector);
    static std::vector<Triangle> cloneTriangles(std::vector<Triangle> &vector);

    static double degreesToRadians(double degrees);
    static double radiansToDegrees(double radians);
};

#endif // HELPER_H
