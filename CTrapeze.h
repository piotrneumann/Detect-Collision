#ifndef CTRAPEZE_H
#define CTRAPEZE_H

#include <iostream>
#include "CRectangle.h"
#include "CSection.h"
using namespace std;

class CTrapeze: public CRectangle
{
private:
    CPoint *p1;
    CPoint *p2;
    CPoint *p3;
    CPoint *p4;
    string name;
    vector<CPoint*> points;
    vector <CSection*> sections;
public:
    CTrapeze(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4);
    virtual void rotate(double degrees);
    virtual void shift(double x, double y);
    vector<CPoint*> getPoints();
    vector<CSection*> getSections();
    bool isColliding(vector<CPoint*> points);
    virtual bool isColliding(vector<CSection*> sections){};
    void show();
    string getName();
    virtual ~CTrapeze();
};
#endif
