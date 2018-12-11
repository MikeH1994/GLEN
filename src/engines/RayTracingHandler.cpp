#include "stdafx.h"

#include "RayTracingHandler.h"
#include "SpectralIntensity.h"
#include "RayTracer.h"

RayTracingHandler::RayTracingHandler(std::shared_ptr<World> world, std::shared_ptr<Camera> camera,Settings settings, unsigned int threadIndex){
    _world = world;
    if (threadIndex>0){
        //if there is more than 1 thread (and this isn't the first), copy the world containing all surfaces
        _world = std::shared_ptr<World>(new World(*world));
    }
    _camera = camera;
    _settings = settings;
    _threadIndex = threadIndex;
    _width = settings._cameraResolutionX;
    _height = settings._cameraResolutionY;
}

void RayTracingHandler::eventThread(){
    Eigen::Vector3d origin = _camera->getPosition();
    Eigen::Vector3d direction;
    unsigned int x, y;
    std::shared_ptr<SpectralIntensity> spectralIntensity;
    std::shared_ptr<RayTracer> rayTracer(new RayTracer(_settings));
    for(unsigned int i = _startPixel; i<_endPixel; i++){
        x = i%_width;
        y = i/_width;
        direction = _camera->getDirection(x,y);
        spectralIntensity = rayTracer->run(origin,direction);
        _camera->setPixelIntensity(x,y,spectralIntensity);
    }
}
