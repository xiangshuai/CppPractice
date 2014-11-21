#include <iostream>

using namespace std;

class Point
{
private:
    float x;
    float y;
public:
    Point(float x=0, float y=0);

};

Point::Point(float x, float y)
{
    this.x = x;
    this.y = y;
}

class Line
{
private:
    Point start;
    Point end;
public:
    Line()
};
