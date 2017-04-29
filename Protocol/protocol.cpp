#include "protocol.h"

Protocol::Protocol(const int _lightCount, const int _snapshotCount) :
    lightCount(_lightCount), snapshotCount(_snapshotCount)
{
    _robots = std::vector<Robot*>();
}

Protocol::~Protocol()
{
    delete(&_robots);
}

std::vector<Robot *> Protocol::robots() const
{
    return _robots;
}
