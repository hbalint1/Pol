#ifndef ROBOTTWOGATHERLIGHT_H
#define ROBOTTWOGATHERLIGHT_H

#include "robot.h"

class RobotTwoGatherLight : public Robot
{
public:
    RobotTwoGatherLight(Point pos, std::vector<std::string> lights, std::vector<Robot*> *robots);

    // Robot interface
private:
    void Look() override;
    Point Compute() override;
    void Move(const Point& p) override;
};

#endif // ROBOTTWOGATHERLIGHT_H
