#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtWidgets>
#include <QPainter>
#include <string>
#include "CRectangle.h"
#include "CTriangle.h"
#include "CTrapeze.h"
#include "CCircle.h"
#include "CObject.h"
#include "CScene.h"
#include "CSection.h"
#include "CShape.h"
#include <QDebug>
#include <String>

#define X0 250
#define Y0 200

#define MAX_X 500
#define MAX_Y 400

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    area = new Area;
    mainLayout = new QGridLayout;
    mainLayout->addWidget(area,0,0,1,4);
    ui->setupUi(this);
    MainWindow::setComboBox();
    MainWindow::notVisible();
    MainWindow::shiftPosition();
    ui->widget_2->setLayout(mainLayout);
    ui->horizontalSlider->setMaximum(MAX_X);
    ui->horizontalSlider->setMinimum(-MAX_X);
    ui->verticalSlider->setMaximum(MAX_Y);
    ui->verticalSlider->setMinimum(-MAX_Y);
    setMouseTracking(true);
    qDebug()<<QCursor::pos().x();
}

QVector<CShape *> MainWindow::getFigures()
{
    return figures;
}

//void MainWindow::mouseMoveEvent(QMouseEvent *event)
//{
//    qDebug()<<"ELO";
//    qDebug()<<event->x()<<" "<<event->y();
//}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setComboBox()
{
    ui->comboBox->addItem("");
    ui->comboBox->addItem("Prostokat");
    ui->comboBox->addItem("Trojkat");
    ui->comboBox->addItem("Trapez");
    ui->comboBox->addItem("Kolo");
}

void MainWindow::visibleRec()
{
    ui->lRecX1->setVisible(true);
    ui->lRecY1->setVisible(true);
   // ui->lRecX2->setVisible(true);
   // ui->lRecY2->setVisible(true);
    //ui->lRecX3->setVisible(true);
    //ui->lRecY3->setVisible(true);
    ui->lRecX4->setVisible(true);
    ui->lRecY4->setVisible(true);

    ui->tRecX1->setVisible(true);
    ui->tRecY1->setVisible(true);
    //ui->tRecX2->setVisible(true);
    //ui->tRecY2->setVisible(true);
    //ui->tRecX3->setVisible(true);
    //ui->tRecY3->setVisible(true);
    ui->tRecX4->setVisible(true);
    ui->tRecY4->setVisible(true);

    ui->tRecX1->setText("10");
    ui->tRecY1->setText("10");
    ui->tRecX2->setText("100");
    ui->tRecY2->setText("10");
    ui->tRecX3->setText("10");
    ui->tRecY3->setText("100");
    ui->tRecX4->setText("100");
    ui->tRecY4->setText("100");
}

void MainWindow::visibleCircle()
{
    ui->tCircleX1->setVisible(true);
    ui->tCircleY1->setVisible(true);
    ui->tCircleR->setVisible(true);

    ui->lCircleX1->setVisible(true);
    ui->lCircleY1->setVisible(true);
    ui->lCircleR->setVisible(true);

    ui->tCircleX1->setText("45");
    ui->tCircleY1->setText("10");
    ui->tCircleR->setText("10");
}

void MainWindow::visibleTriangle()
{
    ui->tTriangleX1_14->setVisible(true);
    ui->tTriangleY1_14->setVisible(true);
    ui->tTriangleX2_14->setVisible(true);
    ui->tTriangleY2_14->setVisible(true);
    ui->tTriangleX3_14->setVisible(true);
    ui->tTriangleY3_14->setVisible(true);

    ui->lTriangleX1_14->setVisible(true);
    ui->lTriangleY1_14->setVisible(true);
    ui->lTriangleX2_14->setVisible(true);
    ui->lTriangleY2_14->setVisible(true);
    ui->lTriangleX3_14->setVisible(true);
    ui->lTriangleY3_14->setVisible(true);


    ui->tTriangleX1_14->setText("10");
    ui->tTriangleY1_14->setText("10");
    ui->tTriangleX2_14->setText("100");
    ui->tTriangleY2_14->setText("100");
    ui->tTriangleX3_14->setText("100");
    ui->tTriangleY3_14->setText("10");


}
void MainWindow::addRectangle()
{
    double x1,x2,x3,x4,y1,y2,y3,y4;
    x1 = ui->tRecX1->text().toDouble()+X0;
    x2 = ui->tRecX2->text().toDouble()+X0;
    x3 = ui->tRecX3->text().toDouble()+X0;
    x4 = ui->tRecX4->text().toDouble()+X0;
    y1 = -ui->tRecY1->text().toDouble()+Y0;
    y2 = -ui->tRecY2->text().toDouble()+Y0;
    y3 = -ui->tRecY3->text().toDouble()+Y0;
    y4 = -ui->tRecY4->text().toDouble()+Y0;

    CRectangle *rectangle = new CRectangle(x1,y1,x4,y1,x1,y4,x4,y4);
    figures.push_back(rectangle);
}

void MainWindow::addTrapeze()
{
    double x1,x2,x3,x4,y1,y2,y3,y4;
    x1 = ui->tRecX1->text().toDouble();
    x2 = ui->tRecX2->text().toDouble();
    x3 = ui->tRecX3->text().toDouble();
    x4 = ui->tRecX4->text().toDouble();
    y1 = -ui->tRecY1->text().toDouble();
    y2 = -ui->tRecY2->text().toDouble();
    y3 = -ui->tRecY3->text().toDouble();
    y4 = -ui->tRecY4->text().toDouble();
    CTrapeze *trapeze =  new CTrapeze(x1,y1,x2,y2,x3,y3,x4,y4);
    figures.push_back(trapeze);
}

void MainWindow::addCircle()
{
    double x1,y1,r;
    x1 = ui->tCircleX1->text().toDouble()+X0;
    y1 = -ui->tCircleY1->text().toDouble()+Y0;
    r = ui->tCircleR->text().toDouble();

    CCircle *circle = new CCircle(x1,y1,r);
    figures.push_back(circle);

}

void MainWindow::addTriangle()
{
    double x1,x2,x3,y1,y2,y3;
    x1 = ui->tTriangleX1_14->text().toDouble()+X0;
    x2 = ui->tTriangleX2_14->text().toDouble()+X0;
    x3 = ui->tTriangleX3_14->text().toDouble()+X0;
    y1 = -ui->tTriangleY1_14->text().toDouble()+Y0;
    y2 = -ui->tTriangleY2_14->text().toDouble()+Y0;
    y3 = -ui->tTriangleY3_14->text().toDouble()+Y0;
    qDebug()<<x1<<y1<<x2<<y2<<x3<<y3;

    CTriangle *triangle = new CTriangle(x1,y1,x2,y2,x3,y3);
    figures.push_back(triangle);

}


void MainWindow::notVisible()
{
    ui->lRecX1->setVisible(false);
    ui->lRecY1->setVisible(false);
    ui->lRecX2->setVisible(false);
    ui->lRecY2->setVisible(false);
    ui->lRecX3->setVisible(false);
    ui->lRecY3->setVisible(false);
    ui->lRecX4->setVisible(false);
    ui->lRecY4->setVisible(false);

    ui->tRecX1->setVisible(false);
    ui->tRecY1->setVisible(false);
    ui->tRecX2->setVisible(false);
    ui->tRecY2->setVisible(false);
    ui->tRecX3->setVisible(false);
    ui->tRecY3->setVisible(false);
    ui->tRecX4->setVisible(false);
    ui->tRecY4->setVisible(false);

    ui->tCircleX1->setVisible(false);
    ui->tCircleY1->setVisible(false);
    ui->tCircleR->setVisible(false);

    ui->lCircleX1->setVisible(false);
    ui->lCircleY1->setVisible(false);
    ui->lCircleR->setVisible(false);

    ui->tTriangleX1_14->setVisible(false);
    ui->tTriangleY1_14->setVisible(false);
    ui->tTriangleX2_14->setVisible(false);
    ui->tTriangleY2_14->setVisible(false);
    ui->tTriangleX3_14->setVisible(false);
    ui->tTriangleY3_14->setVisible(false);

    ui->lTriangleX1_14->setVisible(false);
    ui->lTriangleY1_14->setVisible(false);
    ui->lTriangleX2_14->setVisible(false);
    ui->lTriangleY2_14->setVisible(false);
    ui->lTriangleX3_14->setVisible(false);
    ui->lTriangleY3_14->setVisible(false);
}

void MainWindow::on_comboBox_activated(const QString &arg1)
{
    MainWindow::notVisible();
    if(arg1=="Prostokat") {
        MainWindow::visibleRec();
    } else if (arg1=="Trojkat") {
        MainWindow::visibleTriangle();
    } else if(arg1=="Trapez") {
        MainWindow::visibleRec();
    } else if (arg1=="Kolo") {
        MainWindow::visibleCircle();
    } else if (arg1=="") {
        MainWindow::notVisible();
    }
}


void MainWindow::on_pushButton_clicked()
{
    QString item = ui->comboBox->currentText();
    if(item == "Prostokat") {
        MainWindow::addRectangle();
    } else if(item == "Trojkat") {
        qInfo("TOOO");
        MainWindow::addTriangle();
    } else if(item == "Trapez") {
        MainWindow::addTrapeze();
    } else if(item == "Kolo") {
        MainWindow::addCircle();
    }
    on_Rysuj_clicked();
}

void MainWindow::shiftPosition()
{
        connect( ui->horizontalSlider, SIGNAL(valueChanged(int)),
                 this, SLOT(getSliderValue_X(int)) );
        connect( ui->verticalSlider, SIGNAL(valueChanged(int)),
                 this, SLOT(getSliderValue_Y(int)) );
}

void MainWindow::on_Rysuj_clicked()
{
    area->setFigures(figures);
    QString st = "";
    string str = "";
    ui->comboBox_2->clear();
    ui->comboBox_2->addItem("");

    area->drawFigures(true);
    for (int i=0;i<figures.size();i++) {
        str += figures[i]->getName()+" \n";
        ui->comboBox_2->addItem(QString::fromStdString(figures[i]->getName()));
    }
    st = QString::fromStdString(str);
    ui->label->setText(st);

}

void MainWindow::on_label_linkActivated(const QString &link)
{

}

void MainWindow::on_pushButton_2_clicked()
{
    figures.clear();

    QString st = "";

    ui->label->setText(st);
}

void MainWindow::on_pushButton_3_clicked()
{
    ui->label_2->setText("LOL");
    objects.clear();
    for (int i=0;i<figures.size();i++) {
        CObject *obj1 = new CObject();
        obj1->addShape(figures[i]);
        objects.push_back(obj1);
    }

    for(int i=0;i<figures.size();i++) {
        vector<CPoint*> points = figures[i]->getPoints();
        if(figures[i]->getName()=="Rectangle") {
            //qDebug()<<"Rectangle "<<points[0]->getX()<<points[0]->getY()<<points[1]->getX()<<points[1]->getY()<<points[2]->getX()<<points[2]->getY()<<points[3]->getX()<<points[3]->getY();
        } else if(figures[i]->getName()=="Triangle") {
            //qDebug()<<"Triangle"<<points[0]->getX()<<points[0]->getY()<<points[1]->getX()<<points[1]->getY()<<points[2]->getX()<<points[2]->getY();
        } else if(figures[i]->getName()=="Circle") {
            //qDebug()<<"Circle"<<points[0]->getX()<<points[0]->getY()<<points[1]->getX();
        }
    }

    qDebug()<<objects.size();
    for (int i=0;i<objects.size();i++) {
        for (int j=i+1;j<objects.size();j++) {
            if(objects[i]->isColliding(objects[j])) {
                //qDebug()<<i<<j;
                ui->label_2->setText("KOLIZJA");
                return;
            } else {
                ui->label_2->setText("NIE KOLIZJA");
            }
        }
    }

}

void MainWindow::getSliderValue_X(int value)
{
      ui->label->setText(QString::number(value));

      QString item = ui->comboBox->currentText();
      int index = ui->comboBox_2->currentIndex();
      if(index>0)
      {
          qDebug()<<QString::fromStdString(figures[index-1]->getName());
          figures[index-1]->shift(value, -ui->verticalSlider->value());
           vector<CPoint*> points = figures[index-1]->getPoints();
           qDebug()<<figures[index-1]->getPoints()[0]->getX();
          //qDebug() << "("<<points[0]->getX()<<","<<points[0]->getY();
          //qDebug() << "("<<points[0]->getX()<<","<<points[0]->getY()<<")"<< "("<<points[1]->getX()<<","<<points[1]->getY()<<")"<< "("<<points[2]->getX()<<","<<points[2]->getY()<<")"<< "("<<points[3]->getX()<<","<<points[3]->getY()<<")";
            on_pushButton_3_clicked();
          area->setFigures(figures);
      }
}

void MainWindow::getSliderValue_Y(int value)
{
    ui->label->setText(QString::number(value));

    QString item = ui->comboBox->currentText();
    int index = ui->comboBox_2->currentIndex();
    if(index>0)
    {
        qDebug()<<QString::fromStdString(figures[index-1]->getName());
        figures[index-1]->shift(ui->horizontalSlider->value(), -value);
         vector<CPoint*> points = figures[index-1]->getPoints();
         qDebug()<<figures[index-1]->getPoints()[0]->getX();
        //qDebug() << "("<<points[0]->getX()<<","<<points[0]->getY()<<")"<< "("<<points[1]->getX()<<","<<points[1]->getY()<<")"<< "("<<points[2]->getX()<<","<<points[2]->getY()<<")"<< "("<<points[3]->getX()<<","<<points[3]->getY()<<")";
        //qDebug() << "("<<points[0]->getX()<<","<<points[0]->getY()<<")"<< "("<<points[1]->getX()<<","<<points[1]->getY()<<")"<< "("<<points[2]->getX()<<","<<points[2]->getY()<<")"<< "("<<points[3]->getX()<<","<<points[3]->getY()<<")";
        on_pushButton_3_clicked();
        area->setFigures(figures);
    }
}
