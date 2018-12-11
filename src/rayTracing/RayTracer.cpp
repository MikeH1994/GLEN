#include "RayTracer.h"
#include "Helper.h"

RayTracer::RayTracer(Settings settings){
    _settings = settings;
    _minWavelength = _settings._wavelengthLowerBound;
    _maxWavelength = _settings._wavelengthUpperBound;
    _wavelengthBins = _settings._wavelengthBins;
    _maxNumberOfReflections = _settings._maxNumberOfReflections;
    _numberOfAngleIncrements = _settings._numberOfAngles;

    for(int i = 0; i<_maxNumberOfReflections; i++){
        _collisionSurfaces.push_back(nullptr);
        Eigen::Vector3d vec;
        _intersectionPositions.push_back(vec);
    }
    _collisionSurfaces = std::vector<Triangle*>(_maxNumberOfReflections);
    _intersectionPositions = std::vector<Eigen::Vector3d> (_maxNumberOfReflections);
}

std::shared_ptr<SpectralIntensity> RayTracer::run(Eigen::Vector3d pos, Eigen::Vector3d dir){
    _position = pos;
    _direction = dir;
    _spectralIntensity = std::shared_ptr<SpectralIntensity>(new SpectralIntensity(_minWavelength,_maxWavelength,_wavelengthBins));
    nextStep(0);
    return _spectralIntensity;
}

void RayTracer::nextStep(unsigned int depth){
    if (depth>=_maxNumberOfReflections){
        return;
    }
    bool success;
    double distance,theta;
    Triangle* triangle = getCollision(_position,_direction,distance,theta,success);
    if (!success){
        return;
    }
    increment(distance);
    _intersectionPositions[depth] = _position;
    if (depth==0){
        _attenuations[depth] = Helper::ones(_settings._wavelengthBins);
    } else{
        _attenuations[depth] = _attenuations[depth-1]*triangle->get

    }
    //TODO
    Eigen::Vector3d spectralAttenuation;
    _spectralIntensity.add(triangle->getSpectralIntensities(),);


    double theta,phi;
    for(unsigned int thetaIndex = 0; thetaIndex<_numberOfAngleIncrements; thetaIndex++){
        theta = -PI_/2 + thetaIndex*(PI_/_numberOfAngleIncrements);
        for(unsigned int phiIndex = 0; phiIndex<_numberOfAngleIncrements; phiIndex++){
            phi = phiIndex*(2*PI_/_numberOfAngleIncrements);
            Helper::copyTo(_intersectionPositions[depth],_position);
            _direction = triangle->getVectorWithAnglesFromNormal(theta,phi);
            nextStep(depth+1);
        }
    }
}

void RayTracer::increment(double t){
    Helper::add(_position,_direction,t);
}

Triangle* RayTracer::getCollision(Eigen::Vector3d &position, Eigen::Vector3d &direction, double &minDist, double &theta,bool &success){
    double t;
    unsigned int collisionIndex;
    success = false;
    Triangle* surface = nullptr;
    minDist = 1E10;
    for(unsigned int i = 0; i<_objects.size(); i++){
        if (_objects[i].rayIntersects(position,direction,t)){
            success = true;
            if (t<minDist){
                minDist = t;
                collisionIndex = i;
            }
        }
    }
    if (success){
        surface = &_objects[collisionIndex];
        theta =
    }
    return surface;
}
