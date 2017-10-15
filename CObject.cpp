#include "CObject.h"
#include "Statics.h"
#include <QDebug>
#include<iostream>

using namespace std;

void CObject::addShape(CShape *shape)
{
    shapes.push_back(shape);
}
void CObject::rotate(double degrees)
{
    for(int i=0;i<shapes.size();i++)
    {
        shapes[i]->rotate(degrees);
    }
}
void CObject::shift(double x1, double y1)
{
    for(int i=0;i<shapes.size();i++)
    {
        shapes[i]->shift(x1,y1);
    }
}
void CObject::show()
{
    for(int i=0;i<shapes.size();i++)
    {
        shapes[i]->show();
        cout<<endl;
    }
}
void CObject::getNames()
{
    for(int i=0;i<shapes.size();i++)
    {
        cout<<shapes[i]->getName();
    }
}
vector<CShape*> CObject::getShapes()
{
    return shapes;
}

bool CObject::isColliding(CObject *second)
{

        vector <CShape*> vector1 = shapes;
        vector <CShape*> vector2 = second->getShapes();

        for(int i=0;i<vector1.size();i++)
        {
            for(int j=0;j<vector2.size();j++)
            {

                if(vector1[i]->getName()==RECTANGLE)
                {
                    if(vector2[j]->getName()==RECTANGLE)
                    {
                        if(vector1[i]->isColliding(vector2[j]->getPoints()) || vector2[j]->isColliding(vector1[i]->getPoints()))
                        {
                            return true;
                        }
                    }
                    else if(vector2[j]->getName()==TRIANGLE)
                    {
                        if(vector1[i]->isColliding(vector2[j]->getPoints()) || vector2[j]->isColliding(vector1[i]->getPoints()))
                        {
                            return true;
                        }
                    }
                    else if(vector2[j]->getName()==TRAPEZE)
                    {
                        if(vector1[i]->isColliding(vector2[j]->getPoints()) || vector2[j]->isColliding(vector1[i]->getPoints()))
                        {
                            return true;
                        }
                    }
                    else if (vector2[j]->getName()==CIRCLE)
                    {
                        if(vector1[i]->isColliding(vector2[j]->getPoints()) || vector2[j]->isColliding(vector1[i]->getPoints()) || vector2[j]->isColliding(vector1[i]->getSections()))
                        {
                            return true;
                        }
                    }
                    else
                    {
                        cout<<ERROR;
                    }
                }
                else if(vector1[i]->getName()==TRIANGLE)
                {
                    if(vector2[j]->getName()==RECTANGLE)
                    {
                        if(vector1[i]->isColliding(vector2[j]->getPoints()) || vector2[j]->isColliding(vector1[i]->getPoints()))
                        {
                            return true;
                        }
                    }
                    else if(vector2[j]->getName()==TRIANGLE)
                    {
                        if(vector1[i]->isColliding(vector2[j]->getPoints()) || vector2[j]->isColliding(vector1[i]->getPoints()))
                        {
                            return true;
                        }
                    }
                    else if(vector2[j]->getName()==TRAPEZE)
                    {
                        if(vector1[i]->isColliding(vector2[j]->getPoints()) || vector2[j]->isColliding(vector1[i]->getPoints()))
                        {
                            return true;
                        }
                    }
                    else if (vector2[j]->getName()==CIRCLE)
                    {
                        if(vector1[i]->isColliding(vector2[j]->getPoints()) || vector2[j]->isColliding(vector1[i]->getPoints()) || vector2[j]->isColliding(vector1[i]->getSections()))
                        {
                            return true;
                        }
                    }
                    else
                    {
                        cout<<ERROR;
                    }
                }
                else if(vector1[i]->getName()==TRAPEZE)
                {
                    if(vector2[j]->getName()==RECTANGLE)
                    {
                        if(vector1[i]->isColliding(vector2[j]->getPoints()) || vector2[j]->isColliding(vector1[i]->getPoints()))
                        {
                            return true;
                        }
                    }
                    else if(vector2[j]->getName()==TRIANGLE)
                    {
                        if(vector1[i]->isColliding(vector2[j]->getPoints()) || vector2[j]->isColliding(vector1[i]->getPoints()))
                        {
                            return true;
                        }
                    }
                    else if(vector2[j]->getName()==TRAPEZE)
                    {
                        if(vector1[i]->isColliding(vector2[j]->getPoints()) || vector2[j]->isColliding(vector1[i]->getPoints()))
                        {
                            return true;
                        }
                    }
                    else if (vector2[j]->getName()==CIRCLE)
                    {
                        if(vector1[i]->isColliding(vector2[j]->getPoints()) || vector2[j]->isColliding(vector1[i]->getPoints()) || vector2[j]->isColliding(vector1[i]->getSections()))
                        {
                            return true;
                        }
                    }
                    else
                    {
                        cout<<ERROR;
                    }

                }
                else if (vector1[i]->getName()==CIRCLE)
                {
                    if(vector2[j]->getName()==RECTANGLE)
                    {
                        if(vector1[i]->isColliding(vector2[j]->getPoints()) || vector2[j]->isColliding(vector1[i]->getPoints()) || vector1[i]->isColliding(vector2[j]->getSections()))
                        {
                            return true;
                        }
                    }
                    else if(vector2[j]->getName()==TRIANGLE)
                    {
                        if(vector1[i]->isColliding(vector2[j]->getPoints()) || vector2[j]->isColliding(vector1[i]->getPoints()) || vector1[i]->isColliding(vector2[j]->getSections()))
                        {
                            return true;
                        }
                    }
                    else if(vector2[j]->getName()==TRAPEZE)
                    {
                        if(vector1[i]->isColliding(vector2[j]->getPoints()) || vector2[j]->isColliding(vector1[i]->getPoints()) || vector1[i]->isColliding(vector2[j]->getSections()))
                        {
                            return true;
                        }
                    }
                    else if (vector2[j]->getName()==CIRCLE)
                    {
                        if(vector1[i]->isColliding(vector2[j]->getPoints()))
                        {
                            return true;
                        }
                    }
                    else
                    {
                        cout<<ERROR;
                    }

                }
                else
                {
                    cout<<ERROR;
                }
            }
        }
        return false; ///NO Collision
}

