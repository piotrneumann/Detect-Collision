#ifndef CPOINT_H
#define CPOINT_H

#include <iostream>

using namespace std;

class CPoint
{
private:
    double x;
    double y;
    double stateX;
    double stateY;

public:
    CPoint(double x, double y);
    void rotate(double degree);
    void shift(double x, double y);
    string toString();
    double getX();
    double getY();
};

#endif
