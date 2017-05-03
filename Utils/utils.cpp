#include <vector>
#include <string>

struct Point {
    int x;
    int y;

    Point() {}
    Point(int _x, int _y) : x(_x), y(_y) {}
    Point(const Point& p) : x(p.x), y(p.y) {}

    bool operator==(const Point& other) {
        return (other.x == x && other.y == y);
    }

    Point operator-(const Point& other) {
        return Point(x - other.x,y - other.y);
    }

    static Point midpoint(const Point& a, const Point& b) {
        Point ret;
        ret.x = (a.x + b.x) / 2;
        ret.y = (a.y + b.y) / 2;
        return ret;
    }
};

struct Snapshot {
    std::vector<Point> Pos;
    std::vector<std::string> Light;

    Snapshot(std::vector<Point> _pos, std::vector<std::string> _light) : Pos(_pos), Light(_light) {}
};
