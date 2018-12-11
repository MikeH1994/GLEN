#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "Settings.h"
#include "World.h"


class Controller{
protected:
    std::shared_ptr<World> _world;
    Settings _settings;
public:
    Controller(Settings &settings);
    void run();
};

#endif // CONTROLLER_H
