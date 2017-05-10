#include "model.h"

#include <Protocol/protocolsim.h>
#include <Protocol/protocoltwogatherlight.h>

Model::Model(int width, int height)
{
    //debug alatt TwoGatherLight a modell... később kivenni
    setProtocol(new ProtocolTwoGatherLight(width, height));
    _protocol->addRobots(2);
}

Model::~Model()
{
    _protocol = 0;
    delete(_protocol);
}

Protocol *Model::protocol() const
{
    return _protocol;
}

void Model::setProtocol(Protocol *protocol)
{
    _protocol = protocol;
}
