#include <iostream>
#include "CSection.h"

using namespace std;


CSection::CSection(CPoint *pp1, CPoint *pp2)
{
    p1=pp1;
    p2=pp2;
}
bool CSection::isColliding(CSection *section)
{

}
CPoint *CSection::getPoint1()
{
    return p1;
}

CPoint *CSection::getPoint2()
{
    return p2;
}

void CSection::show()
{
    cout<<"CSection "+p1->toString()+" "+p2->toString();
}
