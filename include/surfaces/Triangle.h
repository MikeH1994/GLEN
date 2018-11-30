#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "stdafx.h"

class Triangle{
protected:
    Eigen::Vector3d _normal;
    Eigen::Vector3d _p0;
    Eigen::Vector3d _p1;
    Eigen::Vector3d _p2;
    Eigen::Vector3d _edge0;
    Eigen::Vector3d _edge1;
    Eigen::Vector3d _edge2;

    double _d; //distance from origin to plane, parallel to normal

    void initialise(Eigen::Vector3d p0, Eigen::Vector3d p1, Eigen::Vector3d p2);
public:
    Triangle(Eigen::Vector3d p0, Eigen::Vector3d p1, Eigen::Vector3d p2);
    Triangle(Triangle& triangle);//copy constructor
    /*
    \brief returns whether or not some ray intersects this triangle.
    \params rayOrigin a vector containing the ray origin
    \params rayDirection a vector containing the ray direction
    \params t the distance from the ray origin to the plane
    */
    bool rayIntersects(Eigen::Vector3d &rayOrigin, Eigen::Vector3d &rayDirection, double &t);
    /*
    \brief returns the solid angle subtended by this triangle when viewed from the point origin, calculated using
    Oosterom/Strackee equation
    */
    double solidAngle(Eigen::Vector3d &origin);
};

#endif // TRIANGLE_H
