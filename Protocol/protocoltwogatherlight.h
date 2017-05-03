#ifndef PROTOCOLTWOGATHERLIGHT_H
#define PROTOCOLTWOGATHERLIGHT_H

#include "protocol.h"


class ProtocolTwoGatherLight : public Protocol
{
public:
    ProtocolTwoGatherLight();

    // Protocol interface
public:
    void addRobot(const Point pos) override;
    void addRobots(const int robotCount) override;

private:
    void setLights() override;
};

#endif // PROTOCOLTWOGATHERLIGHT_H
