#include <iostream>
#include "CTriangle.h"
#include <QDebug>

using namespace std;

#define NAME "Triangle"

CTriangle::CTriangle(double x1, double y1, double x2, double y2, double x3, double y3)
{
    p1 = new CPoint(x1, y1);
    p2 = new CPoint(x2, y2);
    p3 = new CPoint(x3, y3);
    odc1 = new CSection(p1,p2);
    odc2 = new CSection(p1,p3);
    odc3 = new CSection(p2,p3);
    sections.push_back(odc1);
    sections.push_back(odc2);
    sections.push_back(odc3);

    name=NAME;
    points.push_back(p1);
    points.push_back(p2);
    points.push_back(p3);
}

void CTriangle::rotate(double degrees)
{
    p1->rotate(degrees);
    p2->rotate(degrees);
    p3->rotate(degrees);
}
void CTriangle::shift(double x, double y)
{
    p1->shift(x,y);
    p2->shift(x,y);
    p3->shift(x,y);
    qDebug()<<"Zmiana_Trojat";
}
void CTriangle::show()
{
    cout<<getName()<<" "<<p1->toString()<<" "<<p2->toString()<<" "<<p3->toString();
}
string CTriangle::getName()
{
    return name;
}
vector<CPoint*> CTriangle::getPoints()
{
    return points;
}
vector<CSection*> CTriangle::getSections()
{
    return sections;
}
bool CTriangle::isColliding(vector<CPoint*> points)
{
    qDebug()<<"Sprawdzanie kolizji punktów";
    for(int i=0;i<points.size();i++)
    {
        CPoint *tmpPoint = points[i];
        double dominator;
        double a,b,c;
        double h = p2->getY();
        dominator = (p2->getY()-p3->getY())*(p1->getX()-p3->getX()) + (p3->getX()-p2->getX())*(p1->getY()-p3->getY());
        a = ((p2->getY()-p3->getY())*(tmpPoint->getX()-p3->getX()) + (p3->getX()-p2->getX())*(tmpPoint->getY()-p3->getY()))/dominator;
        b = ((p3->getY()-p1->getY())*(tmpPoint->getX()-p3->getX()) + (p1->getX()-p3->getX())*(tmpPoint->getY()-p3->getY()))/dominator;
        c = 1-a-b;
        if(0<=a && a<=1 && 0<=b && b<=1 && 0<=c && c<=1)
        {
            return true; ///jest kolizja
        }
    }
    return false;
}
bool CTriangle::onSection(CSection *firstSection, CSection *secondSection)
{
    CPoint *p = firstSection->getPoint1();
    CPoint *q = firstSection->getPoint2();
    CPoint *r = secondSection->getPoint1();

    if(q->getX()<=max(p->getX(),r->getX()) && q->getX() >= min(p->getX(),r->getX()) &&
       q->getY()<=max(p->getY(),r->getY()) && q->getY() >= min(p->getY(),r->getY()))
        return true;
    return false;
}

CTriangle::~CTriangle()
{
    delete p1;
    delete p2;
    delete p3;
    cout<<"DTOR CTriangle"<<endl;
}
