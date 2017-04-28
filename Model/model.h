#ifndef MODEL_H
#define MODEL_H

#include "Robot/robot.h"
#include <vector>

class Model
{
public:
    Model();
    ~Model();
public:
    std::vector<Robot*> _robots;
};

#endif // MODEL_H
