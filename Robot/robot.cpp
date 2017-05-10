#include "robot.h"

Robot::Robot(Point pos, std::vector<std::string> lights, std::vector<Robot *> *robots) :
    _pos(pos), _lights(lights), _robots(robots), _size(25)
{
}

void Robot::LCM()
{
    Look();
    Point p = Compute();
    Move(p);
}

std::string Robot::getLight() const
{
    return _light;
}

Point Robot::getPos() const
{
    return _pos;
}

void Robot::TakeSnapshot()
{
    std::vector<Point> positions;
    std::vector<std::string> lights;
    for (const auto& robot: *_robots)
    {
        positions.push_back(robot->getPos());
        lights.push_back(robot->getLight());
    }
    Snapshot s(positions, lights);
    _snapshots.push_back(s);
}

Robot::~Robot()
{
    _robots = 0;
    delete(_robots);
}
