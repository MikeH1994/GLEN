#include "World.h"
#include "stdafx.h"
#include "Helper.h"

World::World(std::vector<Triangle> objects){
    _objects = objects;
}

World::World(World& world){
    _objects = Helper::cloneTriangles(world._objects);
    _worldDimensionsX = world._worldDimensionsX;
    _worldDimensionsY = world._worldDimensionsY;
    _worldDimensionsZ = world._worldDimensionsZ;
    _boundingBoxDivisions = world._boundingBoxDivisions;
}
std::shared_ptr<World> World::clone(){
    return std::shared_ptr<World>(new World(*this));
}
