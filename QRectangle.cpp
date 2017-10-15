#include "QRectangle.h"

QRectangle::QRectangle(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4)
{
    point1 = new QPoint(x1,y1);
    point2 = new QPoint(x2,y2);
    point3 = new QPoint(x3,y3);
    point4 = new QPoint(x4,y4);
}

QPolygon QRectangle::getRectangle()
{
    QRect rect = QRect(290, 20, 70, 40);
    QPolygon poly;
    return poly;
}

QRectangle::QRectangle(QPoint &point1, QPoint &point2, QPoint &point3, QPoint &point4)
{
    this->point1 = &point1;
    this->point2 = &point2;
    this->point3 = &point3;
    this->point4 = &point4;
}

QRectangle::~QRectangle()
{
    delete point1;
    delete point2;
    delete point3;
    delete point4;
}
