#include "Helper.h"


Eigen::Vector3d Helper::cloneVector3d(Eigen::Vector3d &vec){
    Eigen::Vector3d copy = Eigen::Vector3d(vec[0],vec[1],vec[2]);
    return copy;
}

std::vector<Triangle> Helper::cloneTriangles(std::vector<Triangle> &triangles){
    std::vector<Triangle> copy;
    for(unsigned int i = 0; i<triangles.size(); i++){
        copy.push_back(Triangle(triangles[i]));
    }
    return copy;
}
