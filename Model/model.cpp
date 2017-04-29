#include "model.h"

#include <Protocol/protocolsim.h>

Model::Model()
{
    //debug alatt SIM a modell... később kivenni
    setProtocol(new ProtocolSIM());
    _protocol->addRobots(5);
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
