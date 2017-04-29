#include "protocolsim.h"
#include <random>
#include <time.h>
#include <Robot/robotsim.h>

ProtocolSIM::ProtocolSIM() : Protocol(6, 0)
{
    setLights();
}

void ProtocolSIM::setLights()
{
    std::vector<std::string> lights({"T", "M", "S", "F", "W", "N"});
    _lights = lights;
}

void ProtocolSIM::addRobot(const Point pos)
{
    _robots.push_back(new RobotSIM(pos, _lights));
}

void ProtocolSIM::addRobots(const int robotCount)
{
    srand(time(NULL));
    for(int i=0; i<robotCount; i++)
    {
        addRobot(Point(rand()%100, rand()%100));
    }
}
