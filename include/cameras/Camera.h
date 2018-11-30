#ifndef CAMERA_H
#define CAMERA_H

#include "stdafx.h"
#include "Settings.h"



class Camera{
protected:
    Settings _settings;
    double _fovX;
    double _fovY;
    int _resolutionX;
    int _resolutionY;
    Eigen::Vector3d _position;
    Eigen::Vector3d _pointTowardsPosition;
public:
    Camera(Settings settings);


    //getter/setter methods

    void getFOV(double &fovX,double &fovY);
    void getResolution(int &resolutionX, int &resolutionY);
    Eigen::Vector3d getPosition();
    Eigen::Vector3d getPointDirection();
};

#endif // CAMERA_H
