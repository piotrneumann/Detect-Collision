#ifndef QRECTANGLE_H
#define QRECTANGLE_H
#include <QPoint>
#include <QPainter>


class QRectangle
{
public:

    QRectangle(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4);
    QRectangle(QPoint &point1, QPoint &point2, QPoint &point3, QPoint &point4);
    QPolygon getRectangle();
    ~QRectangle();
private:
    QPoint *point1;
    QPoint *point2;
    QPoint *point3;
    QPoint *point4;
};

#endif // QRECTANGLE_H
