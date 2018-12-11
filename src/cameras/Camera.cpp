#include "Camera.h"
#include "Helper.h"


Camera::Camera(Settings settings){
    _settings = settings;
    _fovX = settings._cameraFOVx;
    _fovY = settings._cameraFOVy;
    _position = Eigen::Vector3d();
    double x,y,z;
    x = _settings._cameraPointPositionX;
    y = settings._cameraPositionY;
    z = settings._cameraPositionZ;
    Helper::setElements(_position,x,y,z);
    _resolutionX = settings._cameraResolutionX;
    _resolutionY = settings._cameraResolutionY;
    _pointTowardsPosition = Eigen::Vector3d();
    x = settings._cameraPointPositionX;
    y = settings._cameraPointPositionY;
    z = settings._cameraPointPositionZ;
    Helper::setElements(_pointTowardsPosition,x,y,z);
    _direction = _pointTowardsPosition-_position;
    _direction.normalize();
    for(unsigned int i = 0; i<_resolutionY; i++){
        _pixelIntensities.push_back(std::vector<std::shared_ptr<SpectralIntensity>>(_resolutionX));
    }
}

void Camera::setPixelIntensity(unsigned int x,unsigned int y, std::shared_ptr<SpectralIntensity> intensity){
    _threadLock.lock();
    _pixelIntensities[y][x] = intensity;
    _threadLock.unlock();
}

Eigen::Vector3d Camera::getDirection(unsigned int x, unsigned int y){
    Eigen::Vector3d zAxis = Helper::getZAxis();
    Eigen::Vector3d xAxis = Helper::getXAxis();

    //rotate the vector '_direction' in the
    unsigned int midX = _resolutionX/2;
    unsigned int midY = _resolutionY/2;
    //Calculate the relative angle between the central pixel and pixel (x,y)
    double angleX = (x-midX)*_fovX/_resolutionX;
    double angleY = (y-midY)*_fovY/_resolutionY;
    Eigen::Vector3d temp = Helper::rotateVectorAroundAxis(_direction,zAxis,angleX);
    Eigen::Vector3d directionForPixelXY = Helper::rotateVectorAroundAxis(temp,xAxis,angleY);
    return directionForPixelXY;
}
