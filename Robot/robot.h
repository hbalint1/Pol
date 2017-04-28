#ifndef ROBOT_H
#define ROBOT_H

#include <string>
#include <vector>

class Robot
{
public:
    Robot(int x, int y, std::vector<std::string> lights);
    ~Robot();
    void LCM();

    int x() const;
    void setX(int x);

    int y() const;
    void setY(int y);

    std::string light() const;
    void setLight(const std::string &light);

private:
    virtual void Look() = 0;
    virtual void Compute() = 0;
    virtual void Move() = 0;

private:
    int _x;
    int _y;
    const std::vector<std::string> _lights;
    std::string _light;
};

#endif // ROBOT_H
