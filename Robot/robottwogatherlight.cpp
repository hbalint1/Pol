#include "robottwogatherlight.h"
#include <iostream>
RobotTwoGatherLight::RobotTwoGatherLight(Point pos, std::vector<std::string> lights,
                                         std::vector<Robot *> *robots) :
    Robot(pos, lights, robots)
{
    // Initially, the lights are set to Off.
    _light = "Off";
}

void RobotTwoGatherLight::Look()
{
    TakeSnapshot();
    // Take out self from the snapshot.
    for (Snapshot s: _snapshots)
    {
        int index = 0;
        for(int i = 0; i < s.Pos.size(); i++)
        {
            if(s.Pos[i] == _pos)
            {
                index = i;
                s.Pos.erase(s.Pos.begin() + i);
            }
        }
        s.Light.erase(s.Light.begin() + index);
    }
}

Point RobotTwoGatherLight::Compute()
{
    Point p = getPos();

    Snapshot other = _snapshots[0];

    if(_light == "Off") {
        if(other.Light[0] == "Off")
        {
            // p:= Half point between me and other robot
            p = Point::midpoint(_pos, other.Pos[0]);
            _light = "Red";
        }
        else if (other.Light[0] == "Blue")
        {
            // p := Position of the robot
            p = other.Pos[0];
            _light = "Red";
        }
    } else if (_light == "Red") {
        _light = "Blue";
    } else if (_light == "Blue") {
        if(other.Light[0] == "Blue" || other.Light[0] == "Green")
        {
            _light = "Green";
        }
    } else if (_light == "Green") {
        if(other.Light[0] == "Green" || other.Light[0] == "Off")
        {
            _light = "Off";
        }
    }

    return p;
}

void RobotTwoGatherLight::Move(const Point &p)
{
    std::cout << p.x << " " << p.y << std::endl;



    // After move he deletes snapshot, becasue it's an oblivious robot.
    _snapshots.clear();
}
