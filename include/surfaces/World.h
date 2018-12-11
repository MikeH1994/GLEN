#ifndef WORLD_H
#define WORLD_H

#include "Triangle.h"
#include "BRDF.h"


class World{
    double _worldDimensionsX;
    double _worldDimensionsY;
    double _worldDimensionsZ;
    int _boundingBoxDivisions;


    void fillBoundingBox();
public:
    World(std::vector<Triangle> objects);
    World(World& world);
    std::shared_ptr<World> clone();

    std::vector<BRDF> _BDFs;
    std::vector<Triangle> _objects;
    std::vector<std::vector<Triangle>> _boundingBoxes;
};

#endif // WORLD_H
