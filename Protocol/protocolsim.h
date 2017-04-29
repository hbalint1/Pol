#ifndef PROTOCOLSIM_H
#define PROTOCOLSIM_H

#include "protocol.h"


class ProtocolSIM : public Protocol
{
public:
    ProtocolSIM();

    // Protocol interface
private:
    void setLights() override;

    // Protocol interface
public:
    void addRobot(const Point pos) override;
    void addRobots(const int robotCount) override;
};

#endif // PROTOCOLSIM_H
