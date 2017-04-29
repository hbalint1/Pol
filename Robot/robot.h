#ifndef ROBOT_H
#define ROBOT_H

#include <string>
#include <vector>

#include <Utils/utils.cpp>

class Robot
{
public:
    Robot(Point pos, std::vector<std::string> lights);
    ~Robot();
    void LCM();

    std::string light() const;
    Point getPos() const;

private:
    virtual void Look() = 0;
    virtual void Compute() = 0;
    virtual void Move() = 0;

protected:
    Point _pos;
    std::vector<std::string> _lights;
    std::string _light;
    std::vector<Robot*> _snapshots;
};

#endif // ROBOT_H
