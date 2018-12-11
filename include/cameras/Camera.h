#ifndef CAMERA_H
#define CAMERA_H

#include "stdafx.h"
#include "Settings.h"
#include "Vec3d.h"


class Camera{
protected:
    Settings _settings;
    double _fovX;
    double _fovY;
    unsigned int _resolutionX;
    unsigned int _resolutionY;
    Vec3d _position;
    Vec3d _pointTowardsPosition;
    Vec3d _direction;
    std::vector<std::vector<std::shared_ptr<VecXd>>> _pixelIntensities;
    std::mutex _threadLock;
public:
    Camera(Settings settings);


    //getter methods

    void getFOV(double &fovX,double &fovY);
    void getResolution(int &resolutionX, int &resolutionY);
    void getDirection(unsigned int x, unsigned int y, Vec3d &dst);

    //setter methods
    void setPixelIntensity(unsigned int x, unsigned int y, std::shared_ptr<VecXd> intensity);
};

#endif // CAMERA_H
