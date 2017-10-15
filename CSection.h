#ifndef CSECTION_H
#define CSECTION_H

#include <iostream>
#include "CPoint.h"
#include <vector>
using namespace std;

class CSection
{
private:
    CPoint *p1;
    CPoint *p2;
public:
    CSection(CPoint *pp1, CPoint *pp2);
    bool isColliding(CSection *section);
    CPoint *getPoint1();
    CPoint *getPoint2();
    void show();
};

#endif
