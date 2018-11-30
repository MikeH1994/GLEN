#include "SimpleRayTracer.h"

SimpleRayTracer::SimpleRayTracer(std::shared_ptr<World> world, std::shared_ptr<Camera> camera,Settings &settings, int threadIndex){
    _world = world;
    if (threadIndex>0){
        //if there is more than 1 thread (and this isn't the first), copy the world containing all
        _world = std::shared_ptr<World>(new World(*world));
    }
    _camera = camera;

}
