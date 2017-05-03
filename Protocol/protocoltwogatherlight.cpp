#include "protocoltwogatherlight.h"
#include <Robot/robottwogatherlight.h>
#include <random>
#include <time.h>

ProtocolTwoGatherLight::ProtocolTwoGatherLight() : Protocol(4, 0)
{
    setLights();
}

void ProtocolTwoGatherLight::addRobot(const Point pos)
{
    _robots.push_back(new RobotTwoGatherLight(pos, _lights, &_robots));
}

void ProtocolTwoGatherLight::addRobots(const int robotCount)
{
    srand(time(NULL));
    for(int i=0; i<robotCount; i++)
    {
        addRobot(Point(rand()%100, rand()%100));
    }
}

void ProtocolTwoGatherLight::setLights()
{
    std::vector<std::string> lights({"Off", "Red", "Green", "Blue"});
    _lights = lights;
}
