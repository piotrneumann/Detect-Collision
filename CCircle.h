#ifndef CCIRCLE_H
#define CCIRCLE_H

#include <iostream>
#include "CShape.h"
#include "CPoint.h"
#include <Math.h>

class CCircle: public CShape
{
private:
    CPoint *p1;
    CPoint *p2;
    double r;
    string name;
    vector<CPoint*> points;
    double abs(double x);
    double delta(int a, int b, int c);

public:
    bool sectionCrosesCircle(CSection *section);
    bool isOnSection(CPoint *point1, CSection *section1);
    double distancePointPoint(CPoint *point1, CPoint *point2);
    CCircle(double xx1, double yy1, double rr1);
    virtual void rotate(double degrees);
    virtual void shift(double x, double y);
    void show();
    vector<CPoint*> getPoints();
    vector<CSection*> getSections(){}
    bool isColliding(vector<CPoint*> otherPoints);
    virtual bool isColliding(vector<CSection*> sections);
    string getName();
    double getRadius();
    virtual ~CCircle();
};
#endif
