#ifndef RAYTRACER_H
#define RAYTRACER_H

#include "stdafx.h"

#include "SpectralIntensity.h"
#include "World.h"
#include "Settings.h"
#include "SpectralAttenuation.h"

class RayTracer{
protected:
    std::shared_ptr<SpectralIntensity> _spectralIntensity;
    std::shared_ptr<World> _world;
    std::vector<Triangle> _objects;
    std::vector<Eigen::Vector3d> _intersectionPositions;
    std::vector<Eigen::VectorXd> _attenuations;
    std::vector<Triangle*> _collisionSurfaces;
    std::vector<double> _thetaAngles;

    Eigen::Vector3d _position;
    Eigen::Vector3d _direction;
    Settings _settings;

    double _minWavelength;
    double _maxWavelength;
    double _wavelengthBins;

    unsigned int _maxNumberOfReflections;
    unsigned int _numberOfAngleIncrements;
public:
    RayTracer(Settings settings);
    void setWorld(std::shared_ptr<World> world);
    void setWorldObjects(std::vector<Triangle> &objects);
    void setSpectralIntensity(std::shared_ptr<SpectralIntensity> spectralIntensity);
    void increment(double t);
    void nextStep(unsigned int depth);
    Triangle* getCollision(Eigen::Vector3d &position, Eigen::Vector3d &direction, double &minDist, double &theta, bool &success);
    std::shared_ptr<SpectralIntensity> run(Eigen::Vector3d pos, Eigen::Vector3d dir);
};

#endif // RAYTRACER_H
