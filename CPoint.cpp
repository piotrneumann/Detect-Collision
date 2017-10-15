#include <iostream>
#include <math.h>
#include "CPoint.h"
#include <sstream>
#include <QDebug>

using namespace std;

template<typename T>
std::string to_string(const T& obj)
{
    std::stringstream ss;
    ss << obj;
    return ss.str();
}

CPoint::CPoint(double x, double y)
{
    this->x=x;
    this->y=y;
    stateX = x;
    stateY = y;
}

void CPoint::rotate(double degrees)
{
    double newX;
    double newY;
    newX = x*cos(degrees) - y*sin(degrees);
    newY = x*sin(degrees) + y*cos(degrees);
    x = round(newX);
    y = round(newY);
}

void CPoint::shift(double x, double y)
{

    this->x= stateX + x;
    this->y= stateY + y;
}

double CPoint::getX()
{
    return x;
}
double CPoint::getY()
{
    return y;
}

string CPoint::toString()
{
    string point;
    point ="("+ to_string(x)+ ","+to_string(y)+")";

    return point;
}














