#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "stdafx.h"
#include "BRDF.h"
#include "Vec3d.h"
class Triangle{
protected:
    Vec3d _normal;
    Vec3d _p0;
    Vec3d _p1;
    Vec3d _p2;
    Vec3d _edge0;
    Vec3d _edge1;
    Vec3d _edge2;

    Vec3d _thetaAxis;
    Vec3d _phiAxis;
    //Vectors for inside out test
    Vec3d _P;
    Vec3d _C;
    Vec3d _vp;

    //from plane equation ax+by+cz=d
    double _d; //distance from origin to plane, parallel to normal

    std::shared_ptr<BRDF> _brdf;



    void initialise();
public:
    Triangle(Vec3d p0, Vec3d p1, Vec3d p2);
    Triangle(const Triangle &triangle);//copy constructor
    /*
    \brief returns whether or not some ray intersects this triangle.
    \params rayOrigin a vector containing the ray origin
    \params rayDirection a vector containing the ray direction
    \params t the distance from the ray origin to the plane
    */
    bool rayIntersects(Vec3d &rayOrigin, Vec3d &rayDirection, double &t);
    /*
      Perform part of the inside out test, if the intersection point is to the right of vertex
     */
    bool insideOutTest(Vec3d &intersectionPoint,Vec3d &vertex);
    /*
    \brief returns the solid angle subtended by this triangle when viewed from the point origin, calculated using
     Oosterom/Strackee equation
    */
    double solidAngle(Vec3d &origin);
    /*
     Calculate the angle between the plane of the triangle and the direction vector
    */
    double calculateTheta(Vec3d &direction);
    /*
     Returns a vector that is rotate from the normal in two (semi-arbitrary) directions
     */
    void getVectorWithAnglesFromNormal(double &theta, double &phi, Vec3d &dst);

    VecXd getSpectralIntensities(double theta);
};

#endif // TRIANGLE_H
