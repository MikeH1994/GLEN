#ifndef WORLD_H
#define WORLD_H

#include "Triangle.h"

class World{
    double _worldDimensionsX;
    double _worldDimensionsY;
    double _worldDimensionsZ;
    int _boundingBoxDivisions;

    std::vector<Triangle> _objects;
    std::vector<std::vector<Triangle>> _boundingBoxes;

    void fillBoundingBox();
public:
    World(std::vector<Triangle> objects);
    World(World& world);
    std::shared_ptr<World> clone();
};

#endif // WORLD_H
