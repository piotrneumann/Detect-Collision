#include "CCollidingPair.h"
#include <iostream>

CCollidingPair::CCollidingPair(CObject *first, CObject *second)
{
    //objectFirst = new Object();
    //objectSecod = new Object();
    objectFirst=first;
    objectSecod=second;
}
void CCollidingPair::show()
{
    objectFirst->show();
    objectSecod->show();
}
