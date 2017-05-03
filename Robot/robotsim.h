#ifndef ROBOTSIM_H
#define ROBOTSIM_H

#include <Robot/robot.h>

class RobotSIM : public Robot
{
public:
    RobotSIM(Point pos, std::vector<std::string> lights, std::vector<Robot *> *robots);

    // Robot interface
private:
    void Look() override;
    Point Compute() override;
    void Move(const Point& p) override;
};

#endif // ROBOTSIM_H
