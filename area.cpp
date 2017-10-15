#include "area.h"
#include "CShape.h"
#include "CPoint.h"
#include "QTriangle.h"
#include "QRectangle.h"
#include <QPainter>
#include <QDebug>

void Area::setFigures(QVector<CShape*> figures)
{
    this->figures=figures;
}

void Area::drawFigures(bool draw)
{
    this->draw = draw;
}

Area::Area(QWidget *parent)
    : QWidget(parent)
{
    a=1;
    setBackgroundRole(QPalette::Base);
    setAutoFillBackground(true);
    draw = false;



}

QSize Area::minimumSizeHint() const
{
    return QSize(400, 200);
}

QSize Area::sizeHint() const
{
    return QSize(400, 200);
}



void Area::paintEvent(QPaintEvent *event)
{
    update();

    painter = new QPainter(this);


    painter->drawLine(250,0,250,400);
    painter->drawLine(0,200,500,200);

    QPoint point1(10,10);
    QPoint point2(200,200);
    QPoint point3(100,200);
    //painter->drawPath(path);

//    QPoint point1(10,10);
//    QPoint point2(10,100);
//    QPoint point3(100,10);
//    QPoint point4(100,100);
//    QPolygon pols;
//    pols<<point1<<point2<<point3<<point4;
//    painter->drawPolygon(pols);

    if (draw==true)
    {

        //qInfo("RYSUJE");
        for(int i=0;i<figures.size();i++)
        {
            if (figures[i]->getName()=="Rectangle")
            {
                //qDebug()<<QString::fromStdString(figures[i]->getName()) + figures.size();
                vector<CPoint*> points = figures[i]->getPoints();
                //qDebug() << "("<<points[0]->getX()<<","<<points[0]->getY()<<")"<< "("<<points[1]->getX()<<","<<points[1]->getY()<<")"<< "("<<points[2]->getX()<<","<<points[2]->getY()<<")"<< "("<<points[3]->getX()<<","<<points[3]->getY()<<")";
                //qDebug() << points.size();
                QPoint point1(points[0]->getX(), points[0]->getY());
                //QPoint point2(points[1]->getX(), points[1]->getY());
                //QPoint point3(points[2]->getX(), points[2]->getY());
                QPoint point4(points[3]->getX(), points[3]->getY());
                QRect rect(point1, point4);
                painter->drawRect(rect);
            }
            else if (figures[i]->getName()=="Triangle")
            {
                //qDebug()<<QString::fromStdString(figures[i]->getName()) + figures.size();
                vector<CPoint*> points = figures[i]->getPoints();
                //qDebug() << points.size();
                //qDebug() << "("<<points[0]->getX()<<","<<points[0]->getY()<<")"<< "("<<points[1]->getX()<<","<<points[1]->getY()<<")"<< "("<<points[2]->getX()<<","<<points[2]->getY()<<")";
                QPoint point1(points[0]->getX(), points[0]->getY());
                QPoint point2(points[1]->getX(), points[1]->getY());
                QPoint point3(points[2]->getX(), points[2]->getY());
                QTriangle triangle(point1, point2, point3);
                painter->drawPolygon(triangle.getTriangle());
            }
            else if (figures[i]->getName()=="Circle")
            {
                    //qDebug()<<QString::fromStdString(figures[i]->getName()) + figures.size();
                vector<CPoint*> points = figures[i]->getPoints();
                //qDebug() << "("<<points[0]->getX()<<","<<points[0]->getY()<<")"<< "("<<points[1]->getX()<<","<<points[1]->getY();

                //qDebug() << points.size();
                QPoint point1(points[0]->getX(), points[0]->getY());
                painter->drawEllipse(point1, points[1]->getX(), points[1]->getX());
            }
        }
        //draw = false;
    }



            //qInfo("Czesc");
}









