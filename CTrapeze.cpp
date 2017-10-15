#include <iostream>
#include "CTrapeze.h"

using namespace std;

#define NAME "CTrapeze"

CTrapeze::CTrapeze(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4):CRectangle(x1,y1,x2,y2,x3,y3,x4,y4)
{
    name=NAME;
}

void CTrapeze::rotate(double degrees)
{
    CRectangle::rotate(degrees);
}
void CTrapeze::shift(double x, double y)
{
    CRectangle::shift(x,y);
}
void CTrapeze::show()
{
    CRectangle::show();
}
string CTrapeze::getName()
{
    return name;
}
vector<CPoint*> CTrapeze::getPoints()
{
    return CRectangle::getPoints();
}
vector<CSection*> CTrapeze::getSections()
{
    return CRectangle::getSections();
}
bool CTrapeze::isColliding(vector<CPoint*> points)
{
    return CRectangle::isColliding(points);
}
CTrapeze::~CTrapeze()
{
    cout<<"DTOR CTrapeze"<<endl;
}
