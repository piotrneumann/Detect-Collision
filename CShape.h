#ifndef CSHAPE_H
#define CSHAPE_H

#include <iostream>
#include <vector>
#include "CPoint.h"
#include "CSection.h"
class CShape
{
private:
public:
    CShape()
    {

    }
    virtual void rotate(double degrees) = 0;
    virtual void shift(double x, double y) = 0;
    virtual void show() = 0;
    virtual string getName() = 0;
    virtual bool isColliding(vector<CPoint*> points) = 0;
    virtual bool isColliding(vector<CSection*> sections) = 0;
    virtual vector<CPoint*> getPoints() = 0;
    virtual vector<CSection*> getSections() = 0;
    virtual ~CShape()
    {
        cout<<"DTOR figura"<<endl;
    }
};

#endif
