#include "QTriangle.h"

QTriangle::QTriangle(double x1, double y1, double x2, double y2, double x3, double y3)
{
    point1 = new QPoint(x1,y1);
    point2 = new QPoint(x2,y2);
    point3 = new QPoint(x3,y3);
}

QTriangle::QTriangle(QPoint &point1, QPoint &point2, QPoint &point3)
{
    this->point1 = &point1;
    this->point2 = &point2;
    this->point3 = &point3;
}

QPolygon QTriangle::getTriangle()
{
    QPolygon poly;
    poly<<*point1<<*point2<<*point3;
    return poly;
}

QTriangle::~QTriangle()
{
    delete point1;
    delete point2;
    delete point3;
}
