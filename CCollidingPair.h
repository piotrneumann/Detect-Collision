#include <iostream>
#include "CObject.h"

using namespace std;

class CCollidingPair
{
private:
    CObject *objectFirst;
    CObject *objectSecod;
public:
CCollidingPair(CObject *first, CObject *second);
void show();


};

