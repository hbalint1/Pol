#include "robot.h"

Robot::Robot(Point pos, std::vector<std::string> lights) : _pos(pos), _lights(lights)
{
}

void Robot::LCM()
{
    Look();
    Compute();
    Move();
}

std::string Robot::light() const
{
    return _light;
}

Point Robot::getPos() const
{
    return _pos;
}

Robot::~Robot()
{
    delete(&_snapshots);
}
