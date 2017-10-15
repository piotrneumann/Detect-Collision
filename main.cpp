#include <iostream>
#include "CRectangle.h"
#include "CTriangle.h"
#include "CTrapeze.h"
#include "CCircle.h"
#include "CObject.h"
#include "CScene.h"
#include "CSection.h"
#include "CShape.h"
#include <QApplication>
#include "MainWindow.h"
using namespace std;

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    MainWindow window;
    window.show();
    return app.exec();

//    vector<CShape> vec;
//    CScene scene;
//    CObject ob1, ob2,ob3,ob4;
//    CObject ob5;

//    CCircle kol1(5,-2,1);
//    CCircle kol2(3,-12,3);
//    ob5.addShape(&kol2);
//    ob5.addShape(&kol1);
//    CTriangle trojkat1(6,-2,1,1,-1,-1);
//    ob2.addShape(&kol1);
//    CTriangle trojkat2(6,0,6,-2,10,-1);
//    ob3.addShape(&trojkat2);



//    cout<<ob2.isColliding(&ob3);
//    ob2.getNames();
//    trojkat1.getName();





//    scene.addObject(&ob3);
//    scene.addObject(&ob4);
//    scene.addObject(&ob1);
//    scene.addObject(&ob2);
//    cout<<endl;
//    kol1.show();
//    cout<<endl;

//    vector<CCollidingPair*> pary = scene.detectCollision();
//    //cout<<pary.size();
//    //cout<<"TAK"<<endl;
//    for(int i=0;i<pary.size();i++)
//    {
//        pary[i]->show();
//        cout<<endl<<endl;;
//    }

//cout<<endl<<endl;

    return 0;
}
