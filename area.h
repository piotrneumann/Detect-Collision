#ifndef AREA_H
#define AREA_H

#include <QBrush>
#include <QPen>
#include <QPixmap>
#include <QWidget>
#include <QVector>
#include "CShape.h"


class Area : public QWidget
{
    Q_OBJECT

public:

    void setFigures(QVector<CShape*> figures);
    void drawFigures(bool draw);
    Area(QWidget *parent = 0);
    QPainter *painter;
    QSize minimumSizeHint() const override;
    QSize sizeHint() const override;


public slots:

protected:
    void paintEvent(QPaintEvent *event) override;

private:
    QVector<CShape*> figures;
    bool draw;
    QPixmap pixmap;
    int a;
};

#endif // AREA_H
