#include <iostream>
#include "CCircle.h"
#include <QDebug>
using namespace std;

#define NAME "Circle"

CCircle::CCircle(double xx1, double yy1, double rr1)
{
    p1 = new CPoint(xx1,yy1);
    points.push_back(p1);
    r=rr1;
    name=NAME;
    p2 = new CPoint(r,r);
    points.push_back(p2);
}
bool CCircle::isColliding(vector<CPoint*> otherPoints)
{
        if(otherPoints.size()==2)
        {   qDebug()<<"TUTAJ";
            double R = otherPoints[1]->getX();
            double d = distancePointPoint(otherPoints[0],p1);
            if(R+r>d)
            {
                return true;
            }
            else
                false;
        }
        else
        {
            for(int i=0;i<otherPoints.size();i++)
            {
                double d = distancePointPoint(otherPoints[i], p1);
                if(d<=r)
                {
                    return true;
                }
            }///SPRAWDZENIE ODLEGLOSCI PUNKT OD PUNKT
        }
        return false;
}


double CCircle::getRadius()
{
    return r;
}

bool CCircle::isColliding(vector<CSection*> sections)
{
    for(int i=0;i<sections.size();i++)
    {
        if(sectionCrosesCircle(sections[i]))
        {
            qDebug()<<"PRZECINA"<<sections.size();
            return true;

        }
    }
    qDebug()<<"NIE PRZECINA";
    return false;
}

void CCircle::rotate(double degrees)
{
    p1->rotate(degrees);
}
void CCircle::shift(double x, double y)
{
    p1->shift(x,y);
}
void CCircle::show()
{
    cout<<getName()<<" "<<p1->toString()<<" "<<r;
}
string CCircle::getName()
{
    return name;
}
vector<CPoint*> CCircle::getPoints()
{
    return points;
}
double CCircle::distancePointPoint(CPoint *point1, CPoint *point2)
{
    double d = sqrt(pow(point2->getX()-point1->getX(),2) + pow(point2->getY()-point1->getY(),2));
    return d;
}

bool CCircle::sectionCrosesCircle(CSection *section)
{
        double x1 = section->getPoint1()->getX();
        double y1 = section->getPoint1()->getY();
        double x2 = section->getPoint2()->getX();
        double y2 = section->getPoint2()->getY();
        //qDebug()<<"Punkty: "<<x1<<","<<y1<<","<<x2<<","<<y2;
        double cx = p1->getX();
        double cy = p1->getY();
        double cr = r;
        double dx = x2 - x1;
        double dy = y2 - y1;
        double A = dx * dx + dy * dy;
        double B = 2 * (dx *(x1 - cx) + dy * (y1 - cy));
        double C = (x1 - cx) * (x1 - cx) + (y1 - cy) * (y1 - cy) - cr*cr;
        double det = B*B-4*A*C;
        qDebug()<<"DET = "<<det;
        //qDebug()<<"Delta: "<<det;
         if(det<0){
             return false;    /// No collision
         }else if (det == 0) {
             double t = (-B / (2 * A));
             double tx = t * dx + x1;
             double ty = t * dy + y1;
             CPoint point_tmp1(tx,ty);
             qDebug()<<"1pkt"<<tx<<ty;
             if(isOnSection(&point_tmp1,section)) return true;
             else return false;
         } else {
             double t1 = ((-B - sqrt(det))/(2*A));
             double t2 = ((-B + sqrt(det))/(2*A));
             double t1x = t1 * dx + x1;
             double t1y = t1 * dy + y1;
             double t2x = t2 * dx + x1;
             double t2y = t2 * dy + y1;
             qDebug()<<"2pkt"<<t1x<<t1y<<t2x<<t2y;
             CPoint point_tmp1(t1x,t1y);
             CPoint point_tmp2(t2x,t2y);
             if(isOnSection(&point_tmp1,section) || isOnSection(&point_tmp2,section)) return true;
             else return false;
         }
    //    double A=(y2-y1)/(x2-x1);
    //    double B= y1 - A * x1;
//         dx = x2 - x1;
//         dy = y2 - y1;
//        float a = dx * dx + dy * dy;
//        float b = 2 * (dx * (x1 - cx) + dy * (y1 - cy));
//        float c = cx * cx + cy * cy;
//        c += x1 * x1 + y1 * y1;
//        c -= 2 * (cx * x1 + cy * y1);
//        c -= cr * cr;
//        qDebug()<<"Prosta A="<<A<<", B="<<B<<", C="<<C;
//        qDebug()<<"a="<<a<<", b="<<b<<", c="<<c;
//        float bb4ac = b * b - 4 * a * c;
//        qDebug()<<"DELTA"<<bb4ac;
        return false;
    //    if(bb4ac<0){
    //        return false;    /// No collision
    //    }else{
    //        double z1,z2,t1,t2;
    //        z1=(-b-sqrt(bb4ac))/(2*a)*2;
    //        z2=(-b+sqrt(bb4ac))/(2*a)*2;
    //        t1=A*x1+B;
    //        t2=A*x2+B;
    //        CPoint p_tmp1(z1,t1);
    //        CPoint p_tmp2(z2,t2);
    //        qDebug()<<"("<<z1<<","<<t1<<")";
    //        qDebug()<<"("<<z2<<","<<t2<<")";
    //        if(isOnSection(&p_tmp1,section) || isOnSection(&p_tmp2,section))
    //        {
    //          return true;      ///Collision
    //        }

    //      }
}
bool CCircle::isOnSection(CPoint *p1, CSection *odc1)
{
    double x1 = odc1->getPoint1()->getX();
    double y1 = odc1->getPoint1()->getY();
    double x2 = odc1->getPoint2()->getX();
    double y2 = odc1->getPoint2()->getY();
    double px=p1->getX();
    double py=p1->getY();
    if(px>=min(x1,x2) && px<=max(x1,x2) && py>=min(y1,y2) && py<=max(y1,y2))
        return true;
    else
        return false;
}
double CCircle::delta(int a, int b, int c)
{
    double delta;
    delta=b*b-4*a*c;
    return delta;
}
double CCircle::abs(double x)
{
    if(x<0)
        return x*(-1);
    else return x;
}

CCircle::~CCircle()
{
    delete p1;
    delete p2;
    cout<<"DTOR CCircle"<<endl;
}
