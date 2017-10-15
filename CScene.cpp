#include "CScene.h"
#include <iostream>

using namespace std;


CScene::CScene()
{

}
void CScene::addObject(CObject *obOther)
{
    objects.push_back(obOther);
}
void CScene::rotate(int i, double degrees)
{
    objects[i]->rotate(degrees);
}
void CScene::shift(int i, double x, double y)
{
    objects[i]->shift(x,y);
}
vector<CCollidingPair*> CScene::detectCollision()
{
    for(int i=0;i<objects.size();i++)
    {
        for(int j=i+1;j<objects.size();j++)
        {
            if(objects[i]->isColliding(objects[j]))
            {
                CCollidingPair *pair = new CCollidingPair(objects[i],objects[j]);
                objectPair.push_back(pair);
            }
        }
    }
    return objectPair;
}
void CScene::show(int number)
{
    objects[number]->show();
}
