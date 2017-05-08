#include <vector>
#include <string>
#include <iostream>
#include <math.h>

struct Point {
    int x;
    int y;

    Point() {}
    Point(int _x, int _y) : x(_x), y(_y) {}
    Point(const Point& p) : x(p.x), y(p.y) {}

    bool operator==(const Point& other) const {
        return (other.x == x && other.y == y);
    }

    Point operator *(const int& s) const {
        return Point(x * s,y * s);
    }

    Point operator +(const Point& other) const {
        return Point(x + other.x,y + other.y);
    }

    Point operator-(const Point& other) const {
        return Point(x - other.x,y - other.y);
    }

    static Point midpoint(const Point& a, const Point& b) {
        Point ret;
        ret.x = (a.x + b.x) / 2;
        ret.y = (a.y + b.y) / 2;
        return ret;
    }

    double length() {
        return sqrt(pow(x,2) + pow(y,2));
    }

    void normalize() {
        if(length()!= 0) {
            x = x/length();
            y = y/length();
        }
    }

    ~Point() {
//        delete &x;
//        delete &y;
    }
};

inline std::ostream& operator<<(std::ostream& os, const Point& p) {
    os << "(" << p.x << "," << p.y << ")" << std::endl;
    return os;
}

struct Snapshot {
    std::vector<Point> Pos;
    std::vector<std::string> Light;

    Snapshot(std::vector<Point> _pos, std::vector<std::string> _light) : Pos(_pos), Light(_light) {}
};

inline std::ostream& operator<<(std::ostream& os, const Snapshot& s) {
    for(Point p: s.Pos) {
        os << p;
    }
    for(std::string l: s.Light) {
        os << l << std::endl;
    }
    return os;
}
