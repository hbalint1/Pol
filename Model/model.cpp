#include "model.h"
#include <random>
#include <Robot/robotsim.h>
#include <time.h>

Model::Model()
{
    srand(time(NULL));

    std::vector<std::string> lights ({"T", "M", "S", "F", "W", "N"});

    _robots = std::vector<Robot*>();
    for(int i=0; i<3; i++)
    {
        _robots.push_back(new RobotSIM(rand()%100, rand()%100, lights));
    }
}

Model::~Model()
{
    delete(&_robots);
}
