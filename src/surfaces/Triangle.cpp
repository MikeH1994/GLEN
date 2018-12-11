#include "Triangle.h"
#include "Helper.h"

Triangle::Triangle(Vec3d p0,Vec3d p1,Vec3d p2){
    p0.copyTo(_p0);
    p1.copyTo(_p1);
    p2.copyTo(_p2);
    initialise();
}

Triangle::Triangle(const Triangle& triangle){
    triangle._p0.copyTo(_p0);
    triangle._p1.copyTo(_p1);
    triangle._p2.copyTo(_p2);
    initialise();
}

void Triangle::initialise(){
    _p1.subtract(_p0,_edge0);
    _p2.subtract(_p1,_edge1);
    _p0.subtract(_p2,_edge2);
    _edge0.cross(_edge1,_normal);
    _d = _normal.dot(_p0); //distance from origin to plane, parallel to the normal

    _thetaAxis = _normal;
    _phiAxis = _edge0;
}

double Triangle::calculateTheta(Vec3d &direction){
    //Equation of plane P =  ax + by + cz = d
    //Normal = <a,b,c>
    //sin theta = P.D / ( |P| |D| ), where D = direction
    return asin( _normal.dot(direction) / (_normal.magnitude()*direction.magnitude()) );
}

bool Triangle::rayIntersects(Vec3d &rayOrigin, Vec3d &rayDirection, double &t){
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
    //_P = rayOrigin + t*rayDirection
    rayDirection.multiplyScalar(t,_P);
    _P.add(rayOrigin);
    //Compute inside out test for each vertex of triangle _p0, _p1 and _p2
    if (!insideOutTest(_P,_p0) || !insideOutTest(_P,_p1) || !insideOutTest(_P,_p2)){
        return false;
    }
    return true;
}

bool Triangle::insideOutTest(Vec3d &P, Vec3d &vertex){
    //_vp = P-vertex
    P.subtract(vertex,_vp);
    //_C = vertex.cross(_vp)
    vertex.cross(_vp,_C);
    if (_normal.dot(_C) < 0){
        //P is to the right of C, point is outside of the triangle
        return false;
    }
    return true;
}

double Triangle::solidAngle(Vec3d &origin){
    //tan(omega/2) = |ABC|/(abc + (A.B)c + (A.C)b + (B.C)a)
    //where A,B and C are the vector representations of the vertexes of the triangle,
    //and a,b,c are the magnitudes of the vector
    //as this is the solid angle viewed from the origin O, each point on this triangle is subtracted by
    //the argument 'origin' to account for this

    Vec3d A,B,C,norm;
    _p0.subtract(origin,A);
    _p1.subtract(origin,B);
    _p2.subtract(origin,C);
    B.cross(C,norm);
    double a = A.magnitude();
    double b = B.magnitude();
    double c = C.magnitude();
    //using relationship |ABC| = A.(BxC), calculate RHS of eqn
    double det = A.dot(norm) / (a*b*c + A.dot(B)*c + A.dot(C)*b + B.dot(C)*a);
    //Taking absolute value of RHS of eqn in case |ABC| is -ve
    double solidAngle = 2*atan(fabs(det));
    return solidAngle;
}

Vec3d Triangle::getVectorWithAnglesFromNormal(double &theta, double &phi){
    Vec3d rotated1 = Helper::rotateVectorAroundAxis(_normal,_thetaAxis,theta);//rotate in theta dirn
    Vec3d rotated2 = Helper::rotateVectorAroundAxis(rotated1,_phiAxis,phi);//rotate in phi dirn
    return rotated2;
}
