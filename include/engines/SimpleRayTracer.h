#ifndef SIMPLERAYTRACER_H
#define SIMPLERAYTRACER_H

#include "Settings.h"
#include "World.h"

class Camera;

class SimpleRayTracer{
protected:
    std::shared_ptr<World> _world;
public:
    SimpleRayTracer(Settings &settings, int numberOfThreads, int threadIndex);
    ~SimpleRayTracer();
};

#endif // SIMPLERAYTRACER_H
