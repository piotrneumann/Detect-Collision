#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtWidgets>
#include <QVector>
#include "area.h"
#include "QLabel"
#include "CShape.h"
#include "CObject.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    QVector<CShape*> getFigures();
    //void mouseMoveEvent(QMouseEvent *);
    ~MainWindow();

private slots:

    void on_comboBox_activated(const QString &arg1);

    void on_pushButton_clicked();

    void on_Rysuj_clicked();

    void on_label_linkActivated(const QString &link);

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void getSliderValue_X(int value);

    void getSliderValue_Y(int value);


private:
    QGridLayout *mainLayout;
    Area *area;
    QVector<CShape*> figures;
    QVector<CObject*> objects;
    Ui::MainWindow *ui;
    QLabel *shapeLabel;
    void setComboBox();
    void visibleRec();
    void notVisible();
    void visibleCircle();
    void visibleTriangle();
    void addRectangle();
    void addTrapeze();
    void addCircle();
    void addTriangle();
    void shiftPosition();
};

#endif // MAINWINDOW_H
