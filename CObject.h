#ifndef COBJECT_H
#define COBJECT_H


#include <iostream>
#include "CShape.h"
#include <vector>

using namespace std;

class CObject
{
private:
    vector<CShape*> shapes;
public:
    void addShape(CShape *shape);
    void rotate(double degrees);
    void shift(double x1, double y1);
    void show();
    void getNames();
    bool isColliding(CObject *second);
    vector<CShape*> getShapes();
    ~CObject()
    {

    }

};

#endif
