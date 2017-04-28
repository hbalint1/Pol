#include "robot.h"

Robot::Robot(int x, int y, std::vector<std::string> lights) : _x(x), _y(y), _lights(lights)
{
}

void Robot::LCM()
{
    Look();
    Compute();
    Move();
}

int Robot::x() const
{
    return _x;
}

void Robot::setX(int x)
{
    _x = x;
}

int Robot::y() const
{
    return _y;
}

void Robot::setY(int y)
{
    _y = y;
}

std::string Robot::light() const
{
    return _light;
}

void Robot::setLight(const std::string &light)
{
    _light = light;
}

Robot::~Robot()
{

}
