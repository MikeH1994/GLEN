#ifndef SETTINGS_H
#define SETTINGS_H

class Settings{
public:
    double _cameraFOVx;
    double _cameraFOVy;
    int _cameraResolutionX;
    int _cameraResolutionY;

    double _cameraPositionX;
    double _cameraPositionY;
    double _cameraPositionZ;

    double _cameraPointPositionX;
    double _cameraPointPositionY;
    double _cameraPointPositionZ;

    double _wavelengthLowerBound;
    double _wavelengthUpperBound;
    int _wavelengthBins;
    int _angleBins;

    double _worldDimensionsX;
    double _worldDimensionsY;
    double _worldDimensionsZ;
    int _boundingBoxDivisions;


public:
    Settings();
protected:
};

#endif // SETTINGS_H
