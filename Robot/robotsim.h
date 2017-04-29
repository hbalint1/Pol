#ifndef ROBOTSIM_H
#define ROBOTSIM_H

#include <Robot/robot.h>

class RobotSIM : public Robot
{
public:
    RobotSIM(Point pos, std::vector<std::string> lights);

    // Robot interface
private:
    void Look() override;
    void Compute() override;
    void Move() override;
};

#endif // ROBOTSIM_H
