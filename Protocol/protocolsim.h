#ifndef PROTOCOLSIM_H
#define PROTOCOLSIM_H

#include "protocol.h"


class ProtocolSIM : public Protocol
{
public:
    ProtocolSIM();

    // Protocol interface
public:
    void addRobot(const Point pos) override;
    void addRobots(const int robotCount) override;

private:
    void setLights() override;
};

#endif // PROTOCOLSIM_H
