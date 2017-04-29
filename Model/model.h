#ifndef MODEL_H
#define MODEL_H

#include "Robot/robot.h"
#include <vector>
#include <Protocol/protocol.h>

class Model
{
public:
    Model();
    ~Model();

    Protocol *protocol() const;
    void setProtocol(Protocol *protocol);
    enum Protocols { SIM = 0 };

private:
    Protocol* _protocol;
};

#endif // MODEL_H
