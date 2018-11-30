#include "Triangle.h"
#include "Helper.h"

Triangle::Triangle(Eigen::Vector3d p0,Eigen::Vector3d p1,Eigen::Vector3d p2){
    initialise(p0,p1,p2);
}

Triangle::Triangle(Triangle& triangle){
    Eigen::Vector3d p0 = triangle._p0;
    Eigen::Vector3d p1 = triangle._p1;
    Eigen::Vector3d p2 = triangle._p2;
    initialise(p0,p1,p2);
}

void Triangle::initialise(Eigen::Vector3d p0,Eigen::Vector3d p1,Eigen::Vector3d p2){
    _p0 = Helper::cloneVector3d(p0);
    _p1 = Helper::cloneVector3d(p1);
    _p2 = Helper::cloneVector3d(p2);

    _edge0 = _p1 - _p0;
    _edge1 = _p2 - _p1;
    _edge2 = _p0 - _p2;

    _normal = (_edge0).cross(_edge1);
    _d = _normal.dot(_p0); //distance from origin to plane, parallel to the normal
}


bool Triangle::rayIntersects(Eigen::Vector3d &rayOrigin, Eigen::Vector3d &rayDirection, double &t){
    //https://www.scratchapixel.com/lessons/3d-basic-rendering/ray-tracing-rendering-a-triangle/ray-triangle-intersection-geometric-solution

    double cosTheta = _normal.dot(rayDirection); // cosine of angle between ray and normal of plane
    //check if ray and plane are parralel. If so, they will not intersect
    if (cosTheta < EPS_){
        //If normal and ray are perpendicular (i.e. dot product is = 0),
        //ray is parallel to plane
        return false;
    }
    // compute distance from the ray origin to the plane of this triangle
    t = (_normal.dot(rayOrigin) + _d) / cosTheta;
    if (t < 0){
        //if distance is less than zero, the triangle is behind the ray
        return false;
    }
    //calculate the point at which the ray intersects the plane
    Eigen::Vector3d P = rayOrigin + t * rayDirection;

    //Compute inside out test
    Eigen::Vector3d C;
    //edge 0
    Eigen::Vector3d vp0 = P - _p0;
    C = _edge0.cross(vp0);
    if (_normal.dot(C) < 0){
        //P is to the right of C, therefore is outside of the triangle
        return false;
    }
    //edge 1
    Eigen::Vector3d vp1 = P - _p1;
    C = _edge1.cross(vp1);
    if (_normal.dot(C) < 0){
        return false;
    }
    //edge 2
    Eigen::Vector3d vp2 = P - _p2;
    C = _edge2.cross(vp2);
    if (_normal.dot(C) < 0){
        return false;
    }
    return true;
}

double Triangle::solidAngle(Eigen::Vector3d &origin){
    //tan(omega/2) = |ABC|/(abc + (A.B)c + (A.C)b + (B.C)a)
    //where A,B and C are the vector representations of the vertexes of the triangle,
    //and a,b,c are the magnitudes of the vector
    //as this is the solid angle viewed from the origin O, each point on this triangle is subtracted by
    //the argument 'origin' to account for this


    Eigen::Vector3d A = _p0 - origin;
    Eigen::Vector3d B = _p1 - origin;
    Eigen::Vector3d C = _p2 - origin;
    double a = A.norm();
    double b = B.norm();
    double c = C.norm();
    //using relationship |ABC| = A.(BxC), calculate RHS of eqn
    double det = A.dot(B.cross(C)) / (a*b*c + A.dot(B)*c + A.dot(C)*b + B.dot(C)*a);
    //Taking absolute value of RHS of eqn in case |ABC| is -ve
    double solidAngle = 2*atan(fabs(det));
    return solidAngle;
}
