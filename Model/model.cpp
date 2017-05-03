#include "model.h"

#include <Protocol/protocolsim.h>
#include <Protocol/protocoltwogatherlight.h>

Model::Model()
{
    //debug alatt TwoGatherLight a modell... később kivenni
    setProtocol(new ProtocolTwoGatherLight());
    _protocol->addRobots(2);
}

Model::~Model()
{
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
