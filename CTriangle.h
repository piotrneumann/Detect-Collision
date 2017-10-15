#ifndef CTRIANGLE_H
#define CTRIANGLE_H

#include <iostream>
#include "CShape.h"
#include <vector>
#include "CSection.h"
using namespace std;

class CTriangle: public CShape
{
private:
    CPoint *p1;
    CPoint *p2;
    CPoint *p3;
    string name;
    vector <CPoint*> points;
    CSection *odc1;
    CSection *odc2;
    CSection *odc3;
    vector <CSection*> sections;
    bool onSection(CSection *firstSections, CSection *secondSection);

public:
    CTriangle(double x1, double y1, double x2, double y2, double x3, double y3);
    virtual void rotate(double degrees);
    virtual void shift(double x, double y);
    void show();
    string getName();
    vector<CPoint*> getPoints();
    vector<CSection*> getSections();
    bool isColliding(vector<CPoint*> points);
    virtual bool isColliding(vector<CSection*> sections){};
    virtual ~CTriangle();

};

#endif
