#ifndef ROBOT_H
#define ROBOT_H

#include <QObject>
#include <string>
#include <vector>
#include <Utils/utils.cpp>

class Robot : public QObject
{
    Q_OBJECT

public:
    Robot(Point pos, std::vector<std::string> lights, std::vector<Robot*> *robots);
    ~Robot();
    void LCM();

    std::string getLight() const;
    Point getPos() const;
    int _size;
signals:
    void lightChanged();
    void positionChanged();

private:
    virtual void Look() = 0;
    virtual Point Compute() = 0;
    virtual void Move(const Point& p) = 0;

protected:
    void TakeSnapshot();

protected:
    Point _pos;
    std::vector<std::string> _lights;
    std::string _light;
    std::vector<Snapshot> _snapshots;
    Point _target;
    std::vector<Robot*> *_robots;
};

#endif // ROBOT_H
