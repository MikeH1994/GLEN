#ifndef SIMPLERAYTRACER_H
#define SIMPLERAYTRACER_H

#include "Settings.h"
#include "World.h"
#include "Camera.h"

class Camera;

class RayTracingHandler{
private:
    static void dispatchThread(RayTracingHandler*);
    void eventThread();
protected:
    unsigned int _threadIndex;
    unsigned int _startPixel;
    unsigned int _endPixel;
    unsigned int _width;
    unsigned int _height;
    std::shared_ptr<World> _world;
    std::shared_ptr<Camera> _camera;
    Settings _settings;
public:
    RayTracingHandler(std::shared_ptr<World> world, std::shared_ptr<Camera> camera, Settings settings);
    RayTracingHandler(std::shared_ptr<World> world, std::shared_ptr<Camera> camera, Settings settings, unsigned int threadIndex);
    void run(int startPixel, int endPixel);
    void run();
    void join();
    ~RayTracingHandler();
};

#endif // SIMPLERAYTRACER_H
