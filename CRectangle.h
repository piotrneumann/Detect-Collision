#ifndef CRECTANGLE_H
#define CRECTANGLE_H

#include <iostream>
#include "CShape.h"
#include "CTriangle.h"
#include "CSection.h"
using namespace std;

class CRectangle: public CShape
{
private:
    CTriangle *triangle1;
    CTriangle *triangle2;
    CPoint *p1;
    CPoint *p2;
    CPoint *p3;
    CPoint *p4;
    string name;
    vector<CPoint*> points;
    vector <CSection*> sections;
public:
    CRectangle(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4);
    virtual void rotate(double degrees);
    virtual void shift(double x, double y);
    void show();
    vector<CPoint*> getPoints();
    vector<CSection*> getSections();
    bool isColliding(vector<CPoint*> points);
    virtual bool isColliding(vector<CSection*> sections){};

    virtual ~CRectangle();
    string getName();
};

#endif
