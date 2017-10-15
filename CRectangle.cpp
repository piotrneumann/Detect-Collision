#include <iostream>
#include "CRectangle.h"
#include <QDebug>
using namespace std;

#define NAME "Rectangle"

CRectangle::CRectangle(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4)
{
    triangle1 = new CTriangle(x1,y1,x2,y2,x4,y4);
    triangle2 = new CTriangle(x1,y1,x3,y3,x4,y4);
    p1 = new CPoint(x1,y1);
    p2 = new CPoint(x2,y2);
    p3 = new CPoint(x3,y3);
    p4 = new CPoint(x4,y4);
    points.push_back(p1);
    points.push_back(p2);
    points.push_back(p3);
    points.push_back(p4);
    name=NAME;
}

void CRectangle::rotate(double degrees)
{
    triangle1->rotate(degrees);
    triangle2->rotate(degrees);
}
void CRectangle::shift(double x, double y)
{
    triangle1->shift(x,y);
    triangle2->shift(x,y);
    for(int i=0;i<points.size();i++) {
        points[i]->shift(x,y);
    }
    qDebug()<<"Zmiana_Prostokat";
}
void CRectangle::show()
{
    cout<<getName()<<" "<<p1->toString()<<" "<<p2->toString()<<" "<<p3->toString()<<p4->toString();
}

string CRectangle::getName()
{
    return name;
}
vector<CPoint*> CRectangle::getPoints()
{
    vector<CPoint*> tmp = triangle1->getPoints();
    for(int i=0;i<triangle2->getPoints().size();i++)
    {
        tmp.push_back(triangle2->getPoints()[i]);
    }
    //return tmp;
    return points;
}
vector<CSection*> CRectangle::getSections()
{
    vector<CSection*> tmp = triangle1->getSections();
    for(int i=0;i<triangle2->getSections().size();i++)
    {
        tmp.push_back(triangle2->getSections()[i]);
    }
    return tmp;
}
bool CRectangle::isColliding(vector<CPoint*> otherPoints)
{
    qDebug()<<"Sprawdzamy punkty";
    CPoint *p1 = triangle1->getPoints()[0];
    CPoint *p2 = triangle1->getPoints()[1];
    CPoint *p3 = triangle1->getPoints()[2];
    for(int i=0;i<otherPoints.size();i++)
    {
        CPoint *tmpPoint = otherPoints[i];
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
    p1 = triangle2->getPoints()[0];
    p2 = triangle2->getPoints()[1];
    p3 = triangle2->getPoints()[2];
    for(int i=0;i<otherPoints.size();i++)
    {
        CPoint *tmpPoint = otherPoints[i];
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

CRectangle::~CRectangle()
{
    delete triangle1;
    delete triangle2;
    delete p1;
    delete p2;
    delete p3;
    delete p4;
    cout<<"DTOR CRectangle"<<endl;
}
