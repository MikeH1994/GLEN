#ifndef SETTINGS_H
#define SETTINGS_H

class Settings{
public:
    double _cameraFOVx;
    double _cameraFOVy;
    unsigned int _cameraResolutionX;
    unsigned int _cameraResolutionY;

    double _cameraPositionX;
    double _cameraPositionY;
    double _cameraPositionZ;

    double _cameraPointPositionX;
    double _cameraPointPositionY;
    double _cameraPointPositionZ;

    double _wavelengthLowerBound;
    double _wavelengthUpperBound;
    unsigned int _wavelengthBins;
    unsigned int _angleBins;

    double _worldDimensionsX;
    double _worldDimensionsY;
    double _worldDimensionsZ;
    unsigned int _boundingBoxDivisions;

    unsigned int _numberOfAngles;
    unsigned int _maxNumberOfReflections;

public:
    Settings();
protected:
};

#endif // SETTINGS_H
