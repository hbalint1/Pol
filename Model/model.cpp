#include "model.h"

Model::Model()
{
    _robots = std::vector<Robot>(); //?
    _robots.push_back(Robot(100, 100));
    _robots.push_back(Robot(100, 200));
}

Model::~Model()
{
    delete(&_robots);
}
