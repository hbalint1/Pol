#ifndef PROTOCOL_H
#define PROTOCOL_H

#include <Robot/robot.h>

class Protocol
{
public:
    Protocol(const int _lightCount, const int _snapshotCount);
    virtual ~Protocol();

    std::vector<Robot *> robots() const;

    virtual void addRobot(const Point pos) = 0;
    virtual void addRobots(const int robotCount) = 0;

private:
    virtual void setLights() = 0;

public:
    const int lightCount;
    const int snapshotCount;

protected:
    std::vector<Robot*> _robots;
    std::vector<std::string> _lights;
};

#endif // PROTOCOL_H
