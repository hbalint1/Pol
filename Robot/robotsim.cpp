#include "robotsim.h"

RobotSIM::RobotSIM(Point pos, std::vector<std::string> lights, std::vector<Robot *> *robots) :
    Robot(pos, lights, robots)
{

}

void RobotSIM::Look()
{

}

Point RobotSIM::Compute()
{
    return Point();
}

void RobotSIM::Move(const Point &p)
{

}
