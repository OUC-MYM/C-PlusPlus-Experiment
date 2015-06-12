#ifndef POINT_H_INCLUDED
#define POINT_H_INCLUDED

#include <iostream>
#include <cmath>
using namespace std;

class Point
{
public:
// 默认构造函数，默认值为左上角坐标(0, 0)
    Point(int xx = 0, int yy = 0);
    void setX(int xx);
    int getX();
    void setY(int yy);
    int getY();
    void print();
    void moveRight(int offset);
    void moveDown(int offset);
    double distanceTo();
    friend bool operator> (Point p1,Point p2);
private:
    int x;
    int y;
};

Point::Point(int xx, int yy)
{
    x=xx;
    y=yy;
}

void Point::setX(int xx)
{
    x=x+xx;
}

int Point::getX()
{
    return x;
}

void Point::setY(int yy)
{
    y=y+yy;
}

int Point::getY()
{
    return y;
}

void Point::print()
{
    cout << "(" << getX() <<"," <<  getY() << ")" <<endl;
}

void Point::moveRight(int offset)
{
    setX(offset);
}

void Point::moveDown(int offset)
{
    setY(offset);
}

double Point::distanceTo()
{
    return sqrt(x*x+y*y);
}

bool operator> (Point p1,Point p2)
{
    if(p1.distanceTo()>p2.distanceTo())
        return true;
    return false;
}

#endif // POINT_H_INCLUDED
