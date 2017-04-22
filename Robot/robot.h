#ifndef ROBOT_H
#define ROBOT_H


class Robot
{
public:
    Robot();
    Robot(int x, int y);
    ~Robot();
    void LCM();
private:
    void Look();
    void Compute();
    void Move();
public:
    int _x;
    int _y;
};

#endif // ROBOT_H
