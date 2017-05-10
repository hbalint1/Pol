#ifndef PROTOCOLTWOGATHERLIGHT_H
#define PROTOCOLTWOGATHERLIGHT_H

#include "protocol.h"


class ProtocolTwoGatherLight : public Protocol
{
public:
    ProtocolTwoGatherLight(int width, int height);

    // Protocol interface
public:
    void addRobot(const Point pos) override;
    void addRobots(const int robotCount) override;

private:
    void setLights() override;

    int _width;
    int _height;
};

#endif // PROTOCOLTWOGATHERLIGHT_H
