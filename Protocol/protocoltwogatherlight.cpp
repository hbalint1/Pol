#include "protocoltwogatherlight.h"
#include <Robot/robottwogatherlight.h>
#include <random>
#include <time.h>

ProtocolTwoGatherLight::ProtocolTwoGatherLight(int width, int height) : Protocol(4, 0)
{
    setLights();
    _width = width;
    _height = height;
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
        addRobot(Point(rand() % _width, rand() % _height));
        std::cout << _width << " " << _height << std::endl;
    }
}

void ProtocolTwoGatherLight::setLights()
{
    std::vector<std::string> lights({"Off", "Red", "Green", "Blue"});
    _lights = lights;
}
