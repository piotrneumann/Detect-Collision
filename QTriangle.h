#ifndef QTRIANGLE_H
#define QTRIANGLE_H
#include <QPoint>
#include <QPainter>


class QTriangle
{
public:

    QTriangle(double x1, double y1, double x2, double y2, double x3, double y3);
    QTriangle(QPoint &point1, QPoint &point2, QPoint &point3);
    QPolygon getTriangle();
    ~QTriangle();
private:
    QPoint *point1;
    QPoint *point2;
    QPoint *point3;

};

#endif // QTRIANGLE_H
