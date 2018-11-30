#ifndef SIMPLERAYTRACER_H
#define SIMPLERAYTRACER_H

#include "Settings.h"
#include "World.h"

class Camera;

class SimpleRayTracer{
protected:
    int _threadIndex;
    std::shared_ptr<World> _world;
    std::shared_ptr<Camera> _camera;
    Settings settings;
public:
    SimpleRayTracer(std::shared_ptr<World> world, std::shared_ptr<Camera> camera, Settings settings, int threadIndex);
    ~SimpleRayTracer();
};

#endif // SIMPLERAYTRACER_H
