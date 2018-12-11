#include "Helper.h"




Vec3d Helper::getXAxis(){
    return Vec3d(1,0,0);
}

Vec3d Helper::getYAxis(){
    return Vec3d(0,1,0);
}

Vec3d Helper::getZAxis(){
    return Vec3d(0,0,1);
}

Vec3d Helper::rotateVectorAroundAxis(Vec3d &v, Vec3d &k, double theta){
    return v*cos(theta) + k.cross(v)*sin(theta) + k*(k.dot(v))*(1-cos(theta));
}

std::vector<Triangle> Helper::cloneTriangles(std::vector<Triangle> &triangles){
    std::vector<Triangle> copy;
    for(unsigned int i = 0; i<triangles.size(); i++){
        copy.push_back(Triangle(triangles[i]));
    }
    return copy;
}


